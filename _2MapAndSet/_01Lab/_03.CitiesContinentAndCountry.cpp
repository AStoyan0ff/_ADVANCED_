// 03. Cities by Continent and Country.cpp
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin.ignore();

    map<string, map<string, vector<string>>> input;

    for (int idx = 0; idx < N; idx++) {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string continent, country, city;
        iss >> continent >> country >> city;

        input[continent][country].push_back(city);
    }

    for (auto isContinent = input.begin(); isContinent != input.end(); isContinent++) {
        const string& continent = isContinent -> first;
        const auto& countries = isContinent -> second;

        cout << continent << ":" << endl;

        for (auto isCountry = countries.begin(); isCountry != countries.end(); isCountry++) {
            const string& country = isCountry -> first;
            const auto& cities = isCountry -> second;

            vector<string> sortCity = cities;
            sort(sortCity.begin(), sortCity.end());

            cout << "  " << country << " -> ";

            for (size_t idx = 0; idx < sortCity.size(); idx++) {
                cout << sortCity[idx];

                if (idx != sortCity.size() - 1) {
                    cout << ", ";
                }
            }

            cout << endl;
        }
    }
    return 0;
}

