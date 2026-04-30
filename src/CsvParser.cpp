#include "CsvParser.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<MarketRecord> readMarketDataCsv(const std::string& filePath) {
    std::vector<MarketRecord> records;

    std::ifstream file(filePath);
    std::ofstream logFile("logs/rejected_rows.log");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filePath << std::endl;
        return records;
    }

    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open log file." << std::endl;
    }

    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string symbol, date;
        std::string openText, highText, lowText, closeText, volumeText;

        std::getline(ss, symbol, ',');
        std::getline(ss, date, ',');
        std::getline(ss, openText, ',');
        std::getline(ss, highText, ',');
        std::getline(ss, lowText, ',');
        std::getline(ss, closeText, ',');
        std::getline(ss, volumeText, ',');

        if (symbol.empty() || date.empty() ||
            openText.empty() || highText.empty() ||
            lowText.empty() || closeText.empty() ||
            volumeText.empty()) {

            std::string msg = "Invalid row (missing field): " + line;
            std::cerr << msg << std::endl;
            if (logFile.is_open()) logFile << msg << std::endl;
            continue;
        }

        try {
            MarketRecord record;
            record.symbol = symbol;
            record.date = date;
            record.open = std::stod(openText);
            record.high = std::stod(highText);
            record.low = std::stod(lowText);
            record.close = std::stod(closeText);
            record.volume = std::stoll(volumeText);

            records.push_back(record);
        } catch (const std::exception&) {
            std::string msg = "Invalid row (conversion error): " + line;
            std::cerr << msg << std::endl;
            if (logFile.is_open()) logFile << msg << std::endl;
            continue;
        }
    }

    file.close();
    if (logFile.is_open()) logFile.close();

    return records;
}