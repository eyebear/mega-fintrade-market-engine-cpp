#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include "MarketRecord.hpp"

#include <string>
#include <vector>

std::vector<MarketRecord> readMarketDataCsv(const std::string& filePath);

#endif