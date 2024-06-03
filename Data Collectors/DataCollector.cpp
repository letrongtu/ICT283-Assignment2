#include "DataCollector.h"

//---------------------------------------------------------------------------------

// Initialize static member
Vector<WeatherRecord> DataCollector::data;

//---------------------------------------------------------------------------------

// Accumulates weather data from a weather record.
void DataCollector::accumulateData(const WeatherRecord& record) {
    data.add(record);
}

//---------------------------------------------------------------------------------

// Retrieves the weather data.
const Vector<WeatherRecord>& DataCollector::getData(){
        return data;
}

//---------------------------------------------------------------------------------

// Clears the collected weather data.
void DataCollector::clear() {
    data.Clear();
}
