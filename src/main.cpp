#include "CsvParser.hpp"
#include "CsvWriter.hpp"

#include <iostream>
#include <vector>

int main() {
    std::cout << "Mega FinTrade C++ Market Data Engine started." << std::endl;

    std::vector<MarketRecord> records =
        readMarketDataCsv("data/input/raw_market_data.csv");

    std::cout << "Records parsed: " << records.size() << std::endl;

    writeMarketDataCsv("data/output/parsed_market_data.csv", records);

    std::cout << "Parsed market data written to data/output/parsed_market_data.csv" << std::endl;

    return 0;
}