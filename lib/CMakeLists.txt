add_library(weatherApp
        include/WeatherApp.h
        src/WeatherApp.cpp
        include/CityMeteoData.h
        src/CityMeteoData.cpp
        include/UI.h
        src/UI.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 7b145103b94927015c93f3c68caea2b063b23627)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if (NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(weatherApp PRIVATE cpr::cpr)
target_link_libraries(weatherApp PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(weatherApp
        PUBLIC ftxui::screen
        PUBLIC ftxui::dom
        PUBLIC ftxui::component # Not needed for this example.
)
target_include_directories(weatherApp PUBLIC ${PROJECT_SOURCE_DIR})
