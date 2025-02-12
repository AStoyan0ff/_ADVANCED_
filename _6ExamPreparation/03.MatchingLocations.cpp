// 03.	Matching Locations.cpp -> Exam Preparation
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double COMPARISON = 1e-6;

struct Location {

    string name;
    double latitude;
    double longitude;
    string latitudeOriginalStr; // Save the originals string
    string longitudeOriginalStr;
};

bool isCoordinates(double a, double b) {
    return fabs(a - b) < COMPARISON;
}

int main() {

    unordered_map<string, Location> locationsByName;
    vector<Location> locations;

    string attempt;


    while (getline(cin, attempt) && attempt != ".") {

        stringstream ss(attempt);
        string name, latitudeStr, longitudeStr;

        getline(ss, name, ',');
        getline(ss, latitudeStr, ',');
        getline(ss, longitudeStr, ',');

        double latitude = stod(latitudeStr);
        double longitude = stod(longitudeStr);

        Location loc = {name, latitude, longitude, latitudeStr, longitudeStr};
        locationsByName[name] = loc;
        locations.push_back(loc);
    }

    while (getline(cin, attempt) && attempt != ".") {  //Processing request
        stringstream ss(attempt);

        if (attempt.find(' ') != string::npos) { // Input contain coordinates

            double queryLatitude, queryLongitude;
            ss >> queryLatitude >> queryLongitude;

            for (const auto &loc : locations) {

                if (isCoordinates(loc.latitude, queryLatitude) &&

                    isCoordinates(loc.longitude, queryLongitude)) {
                    cout << loc.name << "," << loc.latitudeOriginalStr << "," << loc.longitudeOriginalStr << endl;
                }
            }
        }
        else {
            string quName = attempt; // Check the name

            if (locationsByName.count(quName)) {
                const auto &loc = locationsByName[quName];

                // Used originals string
                cout << loc.name << "," << loc.latitudeOriginalStr << "," << loc.longitudeOriginalStr << endl;
            }
        }
    }
    return 0;
}
