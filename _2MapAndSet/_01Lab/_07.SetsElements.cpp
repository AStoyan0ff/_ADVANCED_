// 07.Sets of Elements.cpp
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {

    int a, b;

    string elements;
    getline(cin, elements);

    istringstream iss(elements);
    iss >> a >> b;

    set<int> setOne;
    set<int> setTwo;

    for (int idx = 0; idx < a; idx++) {
        int digit;
        getline(cin, elements);

        istringstream issDigit(elements);
        issDigit >> digit;
        setOne.insert(digit);
    }

    for (int idx = 0; idx < b; idx++) {
        int digit;
        getline(cin, elements);

        istringstream issDigit(elements);
        issDigit >> digit;
        setTwo.insert(digit);
    }

    set<int> setThree;
    for (const auto& digit : setOne) {
        if (setTwo.count(digit) > 0) {
            setThree.insert(digit);
        }
    }

    for (const auto& digit : setThree) {
        cout << digit << " ";
    }

    cout << endl;

    return 0;
}
