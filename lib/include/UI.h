#ifndef LABWORK7_ENGOZDEV_UI_H
#define LABWORK7_ENGOZDEV_UI_H
#pragma once

#include "../include/CityMeteoData.h"

#include "ftxui/component/screen_interactive.hpp"

#include <iostream>
#include <format>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <sstream>

using namespace ftxui;

Element getWeatherPicture(int weather_code);

Element
getForecastDescription(std::string weather_description, float temperature, float apparent_temperature,
                       int wind_direction, float wind_speed, float precipitation);

Element
getForecastPartDay(const std::string& part_of_day, int weather_code, const std::string& weather_description,
                   float temperature,
                   float apparent_temperature, int wind_direction, float wind_speed, float precipitation);

Element getForecastCurrent(int weather_code, const std::string& weather_description, float temperature,
                           float apparent_temperature, int wind_direction, float wind_speed, float precipitation);

Element getForecastDay(const std::string& date, Forecast& morning, Forecast& day, Forecast& evening, Forecast& night);

Elements
getInterface(size_t amount, std::vector<std::string>& dates, std::vector<Forecast>& morning, std::vector<Forecast>& day,
       std::vector<Forecast>& evening, std::vector<Forecast>& night, Forecast& current, const std::string& city_name,
       const std::string& country_name);

#endif //LABWORK7_ENGOZDEV_UI_H
