// 05.Parking Lot.cpp
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {

    set<string> parking;
    string input;

    while (getline(cin, input)) {
        if (input == "END") {
            break;
        }

        istringstream iss(input);
        string direction, carNumber;
        getline(iss, direction, ',');
        getline(iss >> ws, carNumber);

        if (direction == "IN") {
            parking.insert(carNumber);
        }
        else if (direction == "OUT") {
            parking.erase(carNumber);
        }
    }

    if (parking.empty()) {
        cout << "Parking Lot is Empty" << endl;
    }
    else {
        for (const auto& car : parking) {
            cout << car << endl;
        }
    }
    return 0;
}
