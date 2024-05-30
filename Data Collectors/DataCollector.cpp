#include "DataCollector.h"

// Initialize static member
Map<int, Map<int, Vector<WeatherRecord>>> DataCollector::weather_data;

// Accumulates weather data from a weather record.
void DataCollector::accumulateData(const WeatherRecord& record) {
    weather_data[record.date.GetYear()][record.date.GetMonth()].add(record);
}

// Retrieves the collected weather data.
const Map<int, Map<int, Vector<WeatherRecord>>>& DataCollector::getData() {
    return weather_data;
}

// Clears the collected weather data.
void DataCollector::clear() {
    weather_data.clear();
}
