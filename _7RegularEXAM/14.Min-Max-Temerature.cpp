// 01. Min-Max Temperature.cpp -> C++ Advanced - Retake Exam - 17 June 2023
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int main() {

    int input;
    cin >> input;

    map<string, pair<double, double>> mapCity;

    while (mapCity.size() < input) {

        string city;
        cin >> city;

        double minTemp, maxTemp;
        cin >> minTemp >> maxTemp;

        double minDegrees = min(minTemp, maxTemp);
        double maxDegrees = max(minTemp, maxTemp);

        if (mapCity.find(city) != mapCity.end()) {

            mapCity[city].first = min(mapCity[city].first, minDegrees);
            mapCity[city].second = max(mapCity[city].second, maxDegrees);
        }
        else { // ADD new City ....
            mapCity[city] = {minDegrees, maxDegrees};
        }
    }

    for (auto it = mapCity.begin(); it != mapCity.end(); ++it) {

        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    }
    return 0;
}
