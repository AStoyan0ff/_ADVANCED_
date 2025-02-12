//02. Fishes.cpp -> C++ Advanced - Retake Exam - 17 February 2024
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

void printBag(const stack<string>& bag, int bagNumber) {
    cout << bagNumber << ": ";

    if (bag.empty()) {
        cout << "<empty>";
    }
    else {
        stack<string> temp = bag;
        vector<string> contents;

        while (!temp.empty()) {
            contents.push_back(temp.top());
            temp.pop();
        }

        for (int i = contents.size() - 1; i >= 0; --i) {
            cout << contents[i];

            if (i > 0) cout << ", ";
        }
    }
    cout << endl;
}

int main() {

    stack<string> bag1, bag2, bag3;

    string line;
    while (getline(cin, line)) {

        if (line == "END") break;

        istringstream iss(line);
        int pole;
        string fishName;
        iss >> pole;
        getline(iss >> ws, fishName);

        if (fishName == "THROW") {

            if (pole == 1 && !bag1.empty()) bag1.pop();
            else if (pole == 2 && !bag2.empty()) bag2.pop();
            else if (pole == 3 && !bag3.empty()) bag3.pop();
        }
        else {

            if (pole == 1) bag1.push(fishName);
            else if (pole == 2) bag2.push(fishName);
            else if (pole == 3) bag3.push(fishName);
        }
    }


    printBag(bag1, 1);
    printBag(bag2, 2);
    printBag(bag3, 3);


    map<string, int> restaurantFish, pateFish;

    while (getline(cin, line)) {
        if (line == "END") break;
        restaurantFish[line] = 0;
    }

    auto countFish = [&](stack<string>& bag) {

        while (!bag.empty()) {
            string fish = bag.top();

            if (restaurantFish.find(fish) != restaurantFish.end()) {
                restaurantFish[fish]++;
            }
            else {
                pateFish[fish]++;
            }
            bag.pop();
        }
    };

    countFish(bag1);
    countFish(bag2);
    countFish(bag3);


    cout << "Restaurant: ";
    if (restaurantFish.empty()) {
        cout << "<nothing>";
    }
    else {
        bool first = true;

        for (auto& [fish, count] : restaurantFish) {

            if (count > 0) {

                if (!first) cout << ", ";
                cout << fish << ": " << count;
                first = false;
            }
        }
    }
    cout << endl;


    cout << "Pate: ";
    if (pateFish.empty()) {
        cout << "<nothing>";
    }
    else {

        bool first = true;

        for (auto& [fish, count] : pateFish) {

            if (count > 0) {

                if (!first) cout << ", ";
                cout << fish << ": " << count;

                first = false;
            }
        }
    }
    cout << endl;

    return 0;
}
