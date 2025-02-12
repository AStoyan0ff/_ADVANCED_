//01. Entities.cpp -> C++ Advanced - Retake Exam (10 July 2021)
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string input;
    getline(cin, input);


    vector<string> fields;
    size_t pos = 0;

    while ((pos = input.find(' ')) != string::npos) {

        fields.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    fields.push_back(input);


    vector<vector<string>> entities;
    string line;

    while (getline(cin, line)) {

        if (line == "end") {
            break;
        }

        vector<string> entity;
        size_t pos = 0;

        while ((pos = line.find(' ')) != string::npos) {

            entity.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        entity.push_back(line);
        entities.push_back(entity);
    }

    string target;
    getline(cin, target);

    // Find the index of the target field
    int index = -1;
    for (size_t i = 0; i < fields.size(); i++) {

        if (fields[i] == target) {

            index = i;
            break;
        }
    }

    map<string, int> valueCounts;

    for (const auto& entity : entities) {

        string value = entity[index];
        valueCounts[value]++;
    }

    string mostValue;
    int maxCount = 0;

    for (const auto& pair : valueCounts) {

        if (pair.second > maxCount) {

            mostValue = pair.first;
            maxCount = pair.second;
        }
    }
    cout << mostValue << " " << maxCount << endl;

    return 0;
}