#ifndef CSV_WRITER_HPP
#define CSV_WRITER_HPP

#include "MarketRecord.hpp"

#include <string>
#include <vector>

void writeMarketDataCsv(
    const std::string& filePath,
    const std::vector<MarketRecord>& records
);

#endif