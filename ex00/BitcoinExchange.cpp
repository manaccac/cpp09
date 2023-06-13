#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &s_BitcoinExchange) {
	*this = s_BitcoinExchange;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &s_BitcoinExchange) {
	if (this != &s_BitcoinExchange) {
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &fileName) {
    loadBitcoinDatabase(fileName);
}

void BitcoinExchange::loadBitcoinDatabase(const std::string &fileName) {
    std::ifstream file(fileName.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + fileName);
    }
    std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		std::string priceStr;
		std::getline(ss, priceStr);
		std::stringstream ssPrice(priceStr);
		float price;
		ssPrice >> price;

		bitcoinDatabase[date] = price;
	}

}

float BitcoinExchange::evaluate(const std::string &date, float value) {
    std::map<std::string, float>::iterator it = bitcoinDatabase.lower_bound(date);

    // if the date is not found, use the closest lower date
    if (it == bitcoinDatabase.end() || it->first != date) {
        if (it == bitcoinDatabase.begin()) {
            throw std::runtime_error("No date in database is earlier than: " + date);
        }
        --it;
    }

    float bitcoinPrice = it->second;
    return value * bitcoinPrice;
}
