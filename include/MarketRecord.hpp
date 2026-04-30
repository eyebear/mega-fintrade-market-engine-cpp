#ifndef MARKET_RECORD_HPP
#define MARKET_RECORD_HPP

#include <string>

struct MarketRecord {
    std::string symbol;
    std::string date;

    double open;
    double high;
    double low;
    double close;

    long long volume;
};

#endif