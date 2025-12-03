#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Список городов Украины с реальными координатами (широта, долгота)
    std::vector<std::pair<std::string, std::pair<double,double>>> cities = {
        {"Київ", {50.4501, 30.5234}},
        {"Львів", {49.8397, 24.0297}},
        {"Одеса", {46.4775, 30.7326}},
        {"Харків", {49.9935, 36.2304}},
        {"Дніпро", {48.4647, 35.0462}},
        {"Запоріжжя", {47.8388, 35.1396}},
        {"Миколаїв", {46.9750, 31.9946}},
        {"Херсон", {46.6354, 32.6169}},
        {"Чернігів", {51.4982, 31.2893}},
        {"Полтава", {49.5883, 34.5514}},
        {"Черкаси", {49.4444, 32.0598}},
        {"Житомир", {50.2547, 28.6587}},
        {"Рівне", {50.6199, 26.2516}},
        {"Івано-Франківськ", {48.9226, 24.7111}},
        {"Тернопіль", {49.5535, 25.5948}},
        {"Луцьк", {50.7472, 25.3254}},
        {"Ужгород", {48.6208, 22.2879}},
        {"Суми", {50.9077, 34.7981}},
        {"Вінниця", {49.2328, 28.4810}},
        {"Кропивницький", {48.5079, 32.2623}}
    };

    // Рандом
    std::srand(std::time(nullptr));
    int index = std::rand() % cities.size();

    std::string cityName = cities[index].first;
    double lat = cities[index].second.first;
    double lon = cities[index].second.second;

    std::cout << "Випадкове мiсто: " << cityName << "\n";

    // Создаём карту
    std::ofstream out("map.html");
    if (!out) {
        std::cerr << "Помилка створення map.html\n";
        return 1;
    }

    out <<
"<!DOCTYPE html>\n"
"<html lang=\"uk\">\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <title>Випадкове мiсто: " << cityName << "</title>\n"
"    <link rel=\"stylesheet\" href=\"https://unpkg.com/leaflet@1.9.4/dist/leaflet.css\" />\n"
"    <style>\n"
"        body { margin: 0; padding: 0; }\n"
"        #map { height: 100vh; width: 100vw; }\n"
"    </style>\n"
"</head>\n"
"<body>\n"
"    <div id=\"map\"></div>\n"
"\n"
"    <script src=\"https://unpkg.com/leaflet@1.9.4/dist/leaflet.js\"></script>\n"
"    <script>\n"
"        var map = L.map('map').setView([" << lat << ", " << lon << "], 12);\n"
"\n"
"        L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {\n"
"            maxZoom: 18,\n"
"        }).addTo(map);\n"
"\n"
"        L.marker([" << lat << ", " << lon << "])\n"
"            .addTo(map)\n"
"            .bindPopup('" << cityName << "')\n"
"            .openPopup();\n"
"    </script>\n"
"</body>\n"
"</html>\n";

    out.close();

    std::cout << "Готово! Вiдкрийте map.html у браузерi.\n";
    return 0;
}
