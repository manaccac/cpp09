#include <algorithm>  // Ajout de l'en-tête <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date) {
    // Verifiez que la date a la bonne longueur
    if (date.length() != 10) return false;

    // Verifiez que les separateurs de date sont corrects
    if (date[4] != '-' || date[7] != '-') return false;

    // Obtenez l'annee, le mois et le jour en tant qu'entiers
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    // Verifiez que le mois est valide
    if (month < 1 || month > 12) return false;

    // Verifiez que le jour est valide
    if (day < 1 || day > 31) return false;

    // Verifiez les mois qui n'ont que 30 jours
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }

    // Verifiez fevrier et les annees bissextiles
    if (month == 2) {
        if (day > 29) return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) return false;
    }

    return true;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: btc inputFile.txt\n";
        return 1;
    }

    BitcoinExchange btc("data.csv"); 
    std::ifstream inputFile(argv[1]);
    std::cout << "Opening file " << argv[1] << "\n";

    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." + std::string(argv[1]) + "\n";
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
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << "\n";
            continue;
        }
        if (end == valueStr.c_str()) {
            std::cerr << "Invalid float format" << "\n";
            continue;
        }
		if (value < 0) {
			std::cerr << "Error: not a positive number." << "\n";
			continue;
		}
        if (value > 1000) {
            std::cerr << "Error: too large a number." << "\n";
            continue;
        }
        float result = btc.evaluate(date, value);
        std::cout << date << " => " << value << " = " << result << "\n";
    }

    return 0;
}
