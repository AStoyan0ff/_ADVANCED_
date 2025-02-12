//03. Data.cpp -> C++ Advanced - Retake Exam (10 July 2021)
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string input;
    cin >> input;

    vector<map<string, string>> requsts;

    string line;
    while (getline(cin, line)) {

        if (line == "[queries]") break;
        if (line.empty()) continue;

        map<string, string> format;

        istringstream iss(line);
        string key, value;

        while (iss >> key >> value) {

            format[key] = value;
        }

        requsts.push_back(format);
    }

    vector<pair<string, string>> formation;

    while (getline(cin, line)) {

        if (line == "end") break;

        istringstream iss(line);
        string indexValue, field;
        iss >> indexValue >> field;

        formation.push_back({indexValue, field});
    }

    for (const auto& form : formation) {
        string indexValue = form.first;
        string field = form.second;

        vector<string> results;
        bool found = false;

        for (const auto& req : requsts) {

            if (req.find(input) != req.end() && req.at(input) == indexValue) {
                found = true;

                if (req.find(field) != req.end()) {
                    results.push_back(req.at(field));
                }
            }
        }

        if (!found) {
            cout << "[not found]" << endl;
        }
        else if (results.empty()) {
            cout << endl;
        }
        else {

            for (size_t i = 0; i < results.size(); ++i) {

                if (i > 0) cout << " ";
                cout << results[i];
            }
            cout << endl;
        }
    }

    return 0;
}