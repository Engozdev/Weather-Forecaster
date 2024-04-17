#include "../include/UI.h"


std::unordered_map<uint32_t, std::string> kWeatherCodesInterpretations = {
        {0,
                "    \\   /   \n"
                "     .-.     \n"
                "  ― (   ) ―  \n"
                "     `-’     \n"
                "    /   \\   \n"},
        {1,
                "   \\  /     \n"
                " _ /\"\".-.  \n"
                "   \\_(   ). \n"
                "   /(___(__) \n"
                "             \n"},
        {2,
                "             \n"
                "     .--.    \n"
                "  .-(    ).  \n"
                " (___.__)__) \n"
                "             \n"},
        {3,
                "             \n"
                "     .--.    \n"
                "  .-(    ).  \n"
                " (___.__)__) \n"
                "             \n"},
        {45,
                "             \n"
                " _ - _ - _ - \n"
                "  _ - _ - _  \n"
                " _ - _ - _ - \n"
                "             \n"},
        {48,
                "             \n"
                " _ - _ - _ - \n"
                "  _ - _ - _  \n"
                " _ - _ - _ - \n"
                "             \n"},
        {51,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "     ‘ ‘ ‘ ‘ \n"
                "    ‘ ‘ ‘ ‘  \n"},
        {53,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "     ‘ ‘ ‘ ‘ \n"
                "    ‘ ‘ ‘ ‘  \n"},
        {55,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "   ‚‘‚‘‚‘‚‘  \n"
                "   ‚’‚’‚’‚’  \n"},
        {56,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "     ‘ * ‘ * \n"
                "    * ‘ * ‘  \n"},
        {57,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "    ‘ * ‘ *  \n"
                "   * ‘ * ‘   \n"},
        {61,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "    ‘ ‘ ‘ ‘  \n"
                "   ‘ ‘ ‘ ‘   \n"},
        {63,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "    ‘ ‘ ‘ ‘  \n"
                "   ‘ ‘ ‘ ‘   \n"},
        {65,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "  ‚‘‚‘‚‘‚‘   \n"
                "  ‚’‚’‚’‚’   \n"},
        {66,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "    * * * *  \n"
                "   * * * *   \n"},
        {67,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "    * * * *  \n"
                "   * * * *   \n"},
        {71,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "    *  *  *  \n"
                "   *  *  *   \n"},
        {73,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "   * * * *   \n"
                "  * * * *    \n"},
        {75,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "   * * * *   \n"
                "  * * * *    \n"},
        {77,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "   * * * *   \n"
                "  * * * *    \n"},
        {80,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "  ‚‘‚‘‚‘‚‘   \n"
                "  ‚’‚’‚’‚’   \n"},
        {81,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "  ‚‘‚‘‚‘‚‘   \n"
                "  ‚’‚’‚’‚’   \n"},
        {82,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "  ‚‘‚‘‚‘‚‘   \n"
                "  ‚’‚’‚’‚’   \n"},
        {83,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "  ‚‘‚‘‚‘‚‘   \n"
                "  ‚’‚’‚’‚’   \n"},
        {85,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "   * * * *   \n"
                "  * * * *    \n"},
        {86,
                "     .-.     \n"
                "    (   ).   \n"
                "   (___(__)  \n"
                "   * * * *   \n"
                "  * * * *    \n"},
        {96,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "     *⚡*⚡*   \n"
                "    *  *  *  \n"},
        {99,
                " _`/\"\".-.  \n"
                "  ,\\_(   ). \n"
                "   /(___(__) \n"
                "     *⚡*⚡*   \n"
                "    *  *  *  \n"}
};

std::unordered_map<int, std::string> kWeatherInterpreter{
        {0,  "Clear sky"},
        {1,  "Mainly clear"},
        {2,  "Partly cloudy"},
        {3,  "Overcast"},
        {45, "Fog"},
        {48, "Depositing rime fog"},
        {51, "Light drizzle"},
        {53, "Moderate drizzle"},
        {55, "Dense intensity drizzle"},
        {56, "Light freezing drizzle"},
        {57, "Dense intensity freezing drizzle"},
        {61, "Slight rain"},
        {63, "Moderate rain"},
        {65, "Heavy intensity rain"},
        {66, "Light freezing rain"},
        {67, "Heavy intensity freezing rain"},
        {71, "Slight snow"},
        {73, "Moderate snow"},
        {75, "Heavy intensity snow"},
        {77, "Snow grains"},
        {80, "Slight rain showers"},
        {81, "Moderate rain showers"},
        {82, "Violent rain showers"},
        {83, "Heavy intensity rain showers"},
        {85, "Slight snow thunderstorm"},
        {86, "Heavy intensity snow thunderstorm"},
        {96, "Slight hail thunderstorm"},
        {99, "Heavy hail thunderstorm"}
};

Element getWeatherPicture(int weather_code) {
    std::istringstream forecast(kWeatherCodesInterpretations[weather_code]);
    std::string temp;
    std::vector<std::string> lines;
    while (std::getline(forecast, temp, '\n')) {
        lines.push_back(temp);
    }
    Element e = vbox({
                             text(lines[0]),
                             text(lines[1]),
                             text(lines[2]),
                             text(lines[3]),
                             text(lines[4])
                     });
    return e;
}

std::string getArrow(int wind_direction) {
    if (wind_direction >= 338 || wind_direction <= 22) {
        return "↓";
    }
    if (wind_direction >= 293) {
        return "↘";
    }
    if (wind_direction >= 248) {
        return "→";
    }
    if (wind_direction >= 203) {
        return "↗";
    }
    if (wind_direction >= 158) {
        return "↑";
    }
    if (wind_direction >= 113) {
        return "↖";
    }
    if (wind_direction >= 68) {
        return "←";
    } else {
        return "↙";
    }
}

Element
getForecastDescription(std::string weather_description, float temperature, float apparent_temperature,
                       int wind_direction, float wind_speed, float precipitation) {
    Element e = vbox({
                             text(weather_description),
                             text(std::format("{:.1f}", temperature) + "(" +
                                  std::format("{:.1f}", apparent_temperature) + ")" + " °C"),
                             text(getArrow(wind_direction) + std::format(" {:.1f}", wind_speed) + " km/h"),
                             text(std::format("{:.1f}", precipitation) + " mm")
                     });
    return e;
}

Element
getForecastPartDay(const std::string& part_of_day, int weather_code, const std::string& weather_description,
                   float temperature,
                   float apparent_temperature, int wind_direction, float wind_speed, float precipitation) {
    Element v = vbox({
                             text(part_of_day) | center | bold,
                             separator(),
                             hbox({
                                          vbox({getWeatherPicture(weather_code)}),
                                          vbox({getForecastDescription(weather_description, temperature,
                                                                       apparent_temperature,
                                                                       wind_direction, wind_speed, precipitation)}),
                                  })
                     });
    return v;
}

Element getForecastCurrent(int weather_code, const std::string& weather_description, float temperature,
                           float apparent_temperature, int wind_direction, float wind_speed, float precipitation) {
    Element v = hbox({
                             vbox({getWeatherPicture(weather_code)}),
                             vbox({getForecastDescription(weather_description, temperature,
                                                          apparent_temperature,
                                                          wind_direction, wind_speed, precipitation)}),
                     });
    return v;
}

Element getForecastDay(const std::string& date, Forecast& morning, Forecast& day, Forecast& evening, Forecast& night) {
    std::string parts[4] = {"Morning", "Day", "Evening", "Night"};
    Element content = border(
            hbox({
                         getForecastPartDay(parts[0], morning.weather_code, kWeatherInterpreter[morning.weather_code],
                                            morning.temperature, morning.apparent_temperature, morning.wind_direction,
                                            morning.wind_speed, morning.precipitation),
                         separator(),
                         getForecastPartDay(parts[1], day.weather_code, kWeatherInterpreter[day.weather_code],
                                            day.temperature, day.apparent_temperature, day.wind_direction,
                                            day.wind_speed, day.precipitation),
                         separator(),
                         getForecastPartDay(parts[2], evening.weather_code, kWeatherInterpreter[evening.weather_code],
                                            evening.temperature, evening.apparent_temperature, evening.wind_direction,
                                            evening.wind_speed, evening.precipitation),
                         separator(),
                         getForecastPartDay(parts[3], night.weather_code, kWeatherInterpreter[night.weather_code],
                                            night.temperature, night.apparent_temperature, night.wind_direction,
                                            night.wind_speed, night.precipitation),
                 })
    );
    Element bord = text(" " + date + " ") | bold | center;
    Element win = window(bord, content);
    return win;
}


Elements
getInterface(size_t amount, std::vector<std::string>& dates, std::vector<Forecast>& morning, std::vector<Forecast>& day,
             std::vector<Forecast>& evening, std::vector<Forecast>& night, Forecast& current,
             const std::string& city_name,
             const std::string& country_name) {
    Elements q = {vbox({text("Current forecast: " + city_name + ", " + country_name),
                        separatorEmpty(),
                        getForecastCurrent(current.weather_code, kWeatherInterpreter[current.weather_code],
                                           current.temperature,
                                           current.apparent_temperature, current.wind_direction, current.wind_speed,
                                           current.precipitation)}),
                  separatorEmpty()
    };
    for (int i = 0; i < amount; ++i) {
        Element content = getForecastDay(dates[i], morning[i], day[i], evening[i], night[i]);
        q.push_back(content);
    }
    return q;
}