#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: btc inputFile.txt\n";
        return 1;
    }

    BitcoinExchange btc("data.csv"); 
    std::ifstream inputFile(argv[1]);
    std::cout << "Opening file " << argv[1] << "\n";

    if (!inputFile.is_open()) {
        std::cerr << "Could not open file " + std::string(argv[1]) + "\n";
        return 1;
    }

    std::cout << "Date,Value,Bitcoin\n";
    std::string line;
    std::getline(inputFile, line); 

	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, '|');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());

        std::string valueStr;
        std::getline(ss, valueStr);

        // converting the string to float
        char *end;
        float value = std::strtof(valueStr.c_str(), &end);
        if (end == valueStr.c_str()) {
            std::cerr << "Invalid float format" << "\n";
            continue;
        }
		if (value < 0) {
			std::cerr << "Error: not a positive number." << "\n";
			continue;
		}
        if (value > 1000) {
            std::cerr << "Value out of range" << "\n";
            continue;
        }
        float result = btc.evaluate(date, value);
        std::cout << date << " => " << value << " = " << result << "\n";
    }

    return 0;
}
