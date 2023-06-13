#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:

	BitcoinExchange(const BitcoinExchange &s_BitcoinExchange);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &s_BitcoinExchange);
    BitcoinExchange(const std::string &fileName);
	
    void loadBitcoinDatabase(const std::string &fileName);
    float evaluate(const std::string &date, float value);
private:
    std::map<std::string, float> bitcoinDatabase;
};

#endif
