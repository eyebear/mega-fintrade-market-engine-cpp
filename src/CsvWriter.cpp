#include "CsvWriter.hpp"

#include <fstream>
#include <iostream>

void writeMarketDataCsv(
    const std::string& filePath,
    const std::vector<MarketRecord>& records
) {
    std::ofstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not write file: " << filePath << std::endl;
        return;
    }

    file << "symbol,date,open,high,low,close,volume\n";

    for (const MarketRecord& record : records) {
        file
            << record.symbol << ","
            << record.date << ","
            << record.open << ","
            << record.high << ","
            << record.low << ","
            << record.close << ","
            << record.volume << "\n";
    }

    file.close();
}