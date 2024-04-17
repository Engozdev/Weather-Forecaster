#ifndef LABWORK7_ENGOZDEV_CITYMETEODATA_H
#define LABWORK7_ENGOZDEV_CITYMETEODATA_H
#pragma once

#include <cpr/cpr.h>
#include <ctime>
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <unordered_map>
#include <vector>

struct Forecast {
    int weather_code, wind_direction;
    float temperature, apparent_temperature, wind_speed, precipitation;

    Forecast() = default;

    Forecast(int wc, int wd, float t, float at, float ws, float p) : weather_code(wc), wind_direction(wd),
                                                                     temperature(t), apparent_temperature(at),
                                                                     wind_speed(ws), precipitation(p) {}
};

class CityMeteoData {
public:
    explicit CityMeteoData(std::string& name, int delta) : forecast_days_(delta) {
        std::istringstream location(name);
        std::string temp;
        std::vector<std::string> words;
        while (std::getline(location, temp, ';')) {
            words.push_back(temp);
        }
        city_ = words[0];
        country_ = words[1];
        update();
    };

    ~CityMeteoData() = default;

    void update();
    void increaseForecastDays();
    void decreaseForecastDays();
    ftxui::Elements printDays();
private:
    std::string city_, country_;
    int forecast_days_ = 0;
    Forecast f_cur_{}, f_day_{};
    std::vector<Forecast> morning_, day_, evening_, night_;
    std::vector<std::string> dates;
};

#endif //LABWORK7_ENGOZDEV_CITYMETEODATA_H
