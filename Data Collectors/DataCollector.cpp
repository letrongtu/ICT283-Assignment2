#include "DataCollector.h"

// Initialize static member
Vector<WeatherRecord> DataCollector::weather_data;
Map<int, Map<int, std::pair<int, int>>> DataCollector::indexMap;

// Accumulates weather data from a weather record.
void DataCollector::accumulateData(const WeatherRecord& record) {
    weather_data.add(record);
}

void DataCollector::indexData(){
    for(LongInt i = 0; i < weather_data.Size(); i++){
        int year = weather_data[i].date.GetYear();
        int month = weather_data[i].date.GetMonth();

        if(indexMap[year][month].first == 0 && indexMap[year][month].second == 0){
            indexMap[year][month].first = i;
        }

        indexMap[year][month].second = i;
    }
}

// Retrieves the collected weather data.
Vector<WeatherRecord> DataCollector::getDataByMonth(int month) {
    Vector<WeatherRecord> result;

    for (Map<int, Map<int, std::pair<int, int>>>::const_iterator year_iter = indexMap.begin(); year_iter != indexMap.end(); year_iter++) {
        if (year_iter->second.contains(month)) {
            LongInt start = year_iter->second.at(month).first;
            LongInt end = year_iter->second.at(month).second;
            for (LongInt i = start; i <= end; i++) {
                result.add(weather_data[i]);
            }
        }
    }
    return result;
}

Vector<WeatherRecord> DataCollector::getDataByMonthAndYear(int month, int year)
{
    Vector<WeatherRecord> result;

    if(indexMap.contains(year) && indexMap.at(year).contains(month)){
        LongInt start = indexMap.at(year).at(month).first;
        LongInt end = indexMap.at(year).at(month).second;

        for (LongInt i = start; i <= end; i++) {
            result.add(weather_data[i]);
        }
    }
    return result;
}

bool DataCollector::contains(int year)
{
    return indexMap.contains(year);
}

// Clears the collected weather data.
void DataCollector::clear() {
    weather_data.Clear();
    indexMap.clear();
}
