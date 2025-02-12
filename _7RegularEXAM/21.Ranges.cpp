//02. Ranges.cpp -> C++ Advanced - Exam - 3 July 2021
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {

    vector<pair<int, int>> ranges;

    string line;
    while (getline(cin, line)) {
        if (line == ".") break;

        int start, end;
        sscanf(line.c_str(), "%d %d", &start, &end);
        ranges.push_back({start, end});
    }

    sort(ranges.begin(), ranges.end());

    while (getline(cin, line)) {
        if (line == ".") break;

        int num = stoi(line);
        bool isFound = false;

        int left = 0;
        int right = ranges.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (ranges[middle].first <= num && num <= ranges[middle].second)
                isFound = true;
                break;

            if (ranges[middle].second <= num)  //else if ???
                left = middle + 1;

            else
                right = middle - 1;

        }

        if (isFound)
            cout << "in" << endl;

        else
            cout << "out" << endl;

    }
    return 0;
}




