// 08. Even Time.cpp
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin.ignore();

    map<int, int> myMap;

    for (int idx = 0; idx < N; idx++) {

      int digit;
        cin >> digit;

        myMap[digit]++;
    }

    for (const auto& entry : myMap) {

        if (entry.second % 2 == 0) {
            cout << entry.first << endl;
            break;
        }
    }
    return 0;
}
