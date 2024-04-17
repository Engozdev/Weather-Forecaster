#ifndef LABWORK7_ENGOZDEV_WEATHERAPP_H
#define LABWORK7_ENGOZDEV_WEATHERAPP_H
#pragma once

#include "CityMeteoData.h"

#include "ftxui/component/component.hpp"       // for CatchEvent, Renderer
#include "ftxui/component/event.hpp"           // for Event
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, vbox, window, Element, Elements

#include <iostream>
#include <nlohmann/json.hpp>
#include <utility>  // for move
#include <vector>   // for vector

using namespace ftxui;

class WeatherApp {
public:
    WeatherApp() = default;
    ~WeatherApp() = default;
    void run();
    void config();
    Elements Generator(Event& event, Elements& show, int& city_index);
private:
    std::vector<CityMeteoData> cities;
    int cities_amount = 0, update_frequency{};
};

#endif //LABWORK7_ENGOZDEV_WEATHERAPP_H
