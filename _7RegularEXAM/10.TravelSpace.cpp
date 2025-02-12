// 10.Travel Space.cpp -> Regular Exam – 10 February 2024
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

int findSpaceIndx(const vector<string>& classObject, const string& body) {
    return find(classObject.begin(), classObject.end(), body) - classObject.begin();
}

int main() {

    vector<string> classObject;
    string line;

    // Read the names of the bodies
    while (true) {
        getline(cin, line);

        if (line == "END") break;
        classObject.push_back(line);
    }

    int n = classObject.size();
    vector<vector<int>> travelTime(n, vector<int>(n));

    // Read the travel time matrix
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> travelTime[r][c];
        }
    }
    cin.ignore();

    // Find shortest and longest travel times
    int shortTime = INT_MAX, longTime = INT_MIN;
    vector<pair<int, int> > shorPair, longPair;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {

            if (r != c) {

                if (travelTime[r][c] < shortTime) {
                    shortTime = travelTime[r][c];
                    shorPair = {{r, c}};
                }
                else if (travelTime[r][c] == shortTime) {
                    shorPair.emplace_back(r, c);
                }
                if (travelTime[r][c] > longTime) {
                    longTime = travelTime[r][c];
                    longPair = {{r, c}};
                }
                else if (travelTime[r][c] == longTime) {
                    longPair.emplace_back(r, c);
                }
            }
        }
    }

    // Print shortest travel times
    for (const auto& pair : shorPair) {
        cout << shortTime << ": " << classObject[pair.first] << " -> " << classObject[pair.second] << endl;
    }

    // Print longest travel times
    for (const auto& pair : longPair) {
        cout << longTime << ": " << classObject[pair.first] << " -> " << classObject[pair.second] << endl;
    }

    string route;
    int totalTravelTime = 0;

    // Read and calculate travel routes
    while (true) {
        getline(cin, route);

        if (route == "END") break;

        stringstream ss(route);
        string body;
        vector<int> routeIndices;

        while (ss >> body) {
            routeIndices.push_back(findSpaceIndx(classObject, body));
        }

        int routeTime = 0;
        for (size_t i = 1; i < routeIndices.size(); i++) {
            routeTime += travelTime[routeIndices[i - 1]][routeIndices[i]];
        }

        totalTravelTime += routeTime;
        cout << routeTime << endl;
    }

    // Print total travel time
    cout << totalTravelTime << endl;

    return 0;
}