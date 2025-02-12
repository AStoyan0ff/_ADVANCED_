// 01. Count Real Numbers.cpp
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {

    map<double, int> realNum;
    double digit;

    while (cin >> digit) {
        realNum[digit]++;

        if (cin.peek() == '\n') break;
    }

    for (const auto& pair : realNum) {
        cout << pair.first << " -> " << pair.second << endl;
    }
    return 0; //AStoyanoff
}
