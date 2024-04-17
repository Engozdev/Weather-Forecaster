#include "../include/WeatherApp.h"

Elements WeatherApp::Generator(Event& event, Elements& show, int& city_index) {
    if (event == ftxui::Event::Character('n')) {
        city_index = (city_index + 1) % cities_amount;
        show = cities[city_index].printDays();
    } else if (event == ftxui::Event::Character('p')) {
        city_index = (city_index - 1 + cities_amount) % cities_amount;
        show = cities[city_index].printDays();
    } else if (event == ftxui::Event::Character('+')) {
        cities[city_index].increaseForecastDays();
        show = cities[city_index].printDays();
    } else if (event == ftxui::Event::Character('-')) {
        cities[city_index].decreaseForecastDays();
        show = cities[city_index].printDays();
    } else if (event == ftxui::Event::Character('u')) {
        show = cities[city_index].printDays();
    }
    system("CLS");
    return show;
}

void WeatherApp::run() {
    config();
    auto screen = ScreenInteractive::TerminalOutput();
    screen.TrackMouse(false);

    Event key_pressed;
    int city_index = 0;
    Elements to_show = cities[city_index].printDays();
    auto component = Renderer([&] {
        Elements children = Generator(key_pressed, to_show, city_index);
        return vbox(std::move(children));
    });

    std::thread update([&screen, &to_show, &city_index, this]() {
        for (;;) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(std::chrono::minutes(update_frequency));
            for (int i = 0; i < cities_amount; i++) {
                cities[i].update();
            }
            to_show = cities[city_index].printDays();
            screen.PostEvent(ftxui::Event::Character('u'));
        }
    });
    update.detach();

    component |= CatchEvent([&](Event event) {
        if (event == Event::Escape) {
            screen.ExitLoopClosure()();
            return true;
        } else if (event == Event::Character('n') || event == Event::Character('p') ||
                   event == Event::Character('+') || event == Event::Character('-')) {
            key_pressed = std::move(event);
            return true;
        }
        key_pressed = Event::Special("Other button pressed");
        return false;
    });

    screen.Loop(component);
}

void WeatherApp::config() {
    std::ifstream f("../lib/config.json");
    if (f.is_open()) {
        nlohmann::json resp = nlohmann::json::parse(f);
        update_frequency = resp["updateFrequency"];
        for (std::string city: resp["cities"]) {
            cities.emplace_back(city, resp["daysToShow"]);
            cities_amount++;
        }
    } else {
        std::cerr << "Can't open config.json file" << std::endl;
        exit(EXIT_FAILURE);
    }
}
