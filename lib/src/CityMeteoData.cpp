#include "../include/CityMeteoData.h"
#include <lib/include/UI.h>
#include <windows.h>

void CityMeteoData::increaseForecastDays() {
    if (forecast_days_ == 16) return;
    if (forecast_days_ == morning_.size()) {
        ++forecast_days_;
        update(); // for upd demo
    } else {
        ++forecast_days_;
    }
}

void CityMeteoData::decreaseForecastDays() {
    if (forecast_days_ == 0) return;
    --forecast_days_;
}

ftxui::Elements CityMeteoData::printDays() {
    return getInterface(forecast_days_, dates, morning_, day_, evening_, night_, f_cur_, city_, country_);
}

std::string formattedDate(const std::string& in) {
    std::stringstream js(in);
    std::string date;
    std::getline(js, date, 'T');
    js = std::stringstream(date);
    std::vector<std::string> seglist;
    while (std::getline(js, date, '-')) seglist.push_back(date);
    int year = std::stoi(seglist[0]), month = std::stoi(seglist[1]), day = std::stoi(seglist[2]);
    time_t rawtime;
    struct tm* timeinfo;
    char str[32];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    mktime(timeinfo);
    strftime(str, sizeof(str), "%a. %B, ", timeinfo);
    std::string result = str + std::to_string(timeinfo->tm_mday);
    return result;
}

void CityMeteoData::update() {
//    increaseForecastDays(); for upd demo
    cpr::Response r = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city?name=" + city_},
                               cpr::Header{{"X-Api-Key", "sLEfORTGXWsF6bAflUxvbA==XXDLbjV2vjxhP1eE"}});
    if (r.status_code != 200) {
        if (r.status_code == 400) {
            nlohmann::json error = nlohmann::json::parse(r.text);
            std::cerr << "Error! " << error[0]["reason"] << std::endl;
        } else {
            std::cerr << "Error! Can't find city with the following name: " << city_ << " with response code "
                      << r.status_code << std::endl;
        }
        exit(EXIT_FAILURE);
    }
    nlohmann::json resp = nlohmann::json::parse(r.text);

    std::string forecast_days_string = "&forecast_days_=" + std::to_string(forecast_days_);

    std::string latitude = "latitude=" + resp[0]["latitude"].dump(),
            longitude = "longitude=" + resp[0]["longitude"].dump();
    std::string day_end = "&hourly=temperature_2m,relative_humidity_2m,apparent_temperature,precipitation,weather_code,visibility,wind_speed_10m,wind_direction_10m&timezone=Europe%2FMoscow";
    std::string current_end = "&current=temperature_2m,relative_humidity_2m,apparent_temperature,precipitation,weather_code,wind_speed_10m,wind_direction_10m&timezone=Europe%2FMoscow";
    std::string basic_url =
            "https://api.open-meteo.com/v1/forecast?" + latitude + "&" + longitude + forecast_days_string;
    cpr::Response r_weather = cpr::Get(cpr::Url{basic_url + current_end});
    if (r_weather.status_code != 200) {
        if (r_weather.status_code == 400) {
            nlohmann::json error = nlohmann::json::parse(r_weather.text);
            std::cerr << "Error! " << error[0]["reason"] << std::endl;
        } else {
            std::cerr << "Error! Can't find the current forecast for the city: " << city_ << " with response code: "
                      << r_weather.status_code;
        }
        exit(EXIT_FAILURE);
    }
    nlohmann::json weather_resp = nlohmann::json::parse(r_weather.text);
    f_cur_ = Forecast(weather_resp["current"]["weather_code"], weather_resp["current"]["wind_direction_10m"],
                      weather_resp["current"]["temperature_2m"], weather_resp["current"]["apparent_temperature"],
                      weather_resp["current"]["wind_speed_10m"], weather_resp["current"]["precipitation"]);

    r_weather = cpr::Get(cpr::Url{basic_url + day_end});
    if (r_weather.status_code != 200) {
        if (r_weather.status_code == 400) {
            nlohmann::json error = nlohmann::json::parse(r_weather.text);
            std::cerr << "Error! " << error[0]["reason"] << std::endl;
        } else {
            std::cerr << "Error! Can't find the current forecast for the city: " << city_ << " with response code: "
                      << r_weather.status_code;
        }
        exit(EXIT_FAILURE);
    }
    weather_resp = nlohmann::json::parse(r_weather.text);
    morning_.resize(forecast_days_), day_.resize(forecast_days_), evening_.resize(forecast_days_), night_.resize(
            forecast_days_), dates.resize(forecast_days_);
    for (int i = 0; i < forecast_days_; ++i) {
        dates[i] = formattedDate(weather_resp["hourly"]["time"][24 * i]);
        f_day_ = Forecast(weather_resp["hourly"]["weather_code"][24 * i + 6],
                          weather_resp["hourly"]["wind_direction_10m"][24 * i + 6],
                          weather_resp["hourly"]["temperature_2m"][24 * i + 6],
                          weather_resp["hourly"]["apparent_temperature"][24 * i + 6],
                          weather_resp["hourly"]["wind_speed_10m"][24 * i + 6],
                          weather_resp["hourly"]["precipitation"][24 * i + 6]);
        morning_[i] = f_day_;
        f_day_ = Forecast(weather_resp["hourly"]["weather_code"][24 * i + 12],
                          weather_resp["hourly"]["wind_direction_10m"][24 * i + 12],
                          weather_resp["hourly"]["temperature_2m"][24 * i + 12],
                          weather_resp["hourly"]["apparent_temperature"][24 * i + 12],
                          weather_resp["hourly"]["wind_speed_10m"][24 * i + 12],
                          weather_resp["hourly"]["precipitation"][24 * i + 12]);
        day_[i] = f_day_;
        f_day_ = Forecast(weather_resp["hourly"]["weather_code"][24 * i + 19],
                          weather_resp["hourly"]["wind_direction_10m"][24 * i + 19],
                          weather_resp["hourly"]["temperature_2m"][24 * i + 19],
                          weather_resp["hourly"]["apparent_temperature"][24 * i + 19],
                          weather_resp["hourly"]["wind_speed_10m"][24 * i + 19],
                          weather_resp["hourly"]["precipitation"][24 * i + 19]);
        evening_[i] = f_day_;
        f_day_ = Forecast(weather_resp["hourly"]["weather_code"][24 * i + 23],
                          weather_resp["hourly"]["wind_direction_10m"][24 * i + 23],
                          weather_resp["hourly"]["temperature_2m"][24 * i + 23],
                          weather_resp["hourly"]["apparent_temperature"][24 * i + 23],
                          weather_resp["hourly"]["wind_speed_10m"][24 * i + 23],
                          weather_resp["hourly"]["precipitation"][24 * i + 23]);
        night_[i] = f_day_;
    }
}
