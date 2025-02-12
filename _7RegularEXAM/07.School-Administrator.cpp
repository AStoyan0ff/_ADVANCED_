// 01. School Administrator.cpp -> Retake Exam - (17 February 2024)
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    map<string, vector<int>> roomCnt;
    string input;

    while (getline(cin, input)) {

        if (input == "END") break;

        istringstream iss(input);

        string name;
        int room;
        iss >> name >> room;

        roomCnt[name].push_back(room);
    }

    for (auto& entry : roomCnt) {
        sort(entry.second.begin(), entry.second.end());
    }

    while (getline(cin, input)) {
        if (input == "END") break;

        string name = input;

        if (roomCnt.find(name) != roomCnt.end()) {
            cout << name << ": ";

            for (int room : roomCnt[name]) {
                cout << room << " ";
            }
            cout << endl;
        }
        else {
            cout << name << ": Not found!" << endl;
        }
    }
    return 0;
}
