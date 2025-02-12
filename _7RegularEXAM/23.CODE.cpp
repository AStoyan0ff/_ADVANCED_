// 02. Code -> C++ Advanced - Retake Exam - 10 July 2021
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream sepIss(line);

    unordered_set<int> screening;

    int sep;
    while (sepIss >> sep) {
        screening.insert(sep);
    }

    string messLine;
    getline(cin, messLine);
    istringstream mIss(messLine);

    vector<int> message;

    int digit;
    while (mIss >> digit) {
        message.push_back(digit);
    }

    vector<vector<int>> parts;
    vector<int> currPart;

    for (int n : message) {

        if (screening.count(n)) {

            if (!currPart.empty()) {
                parts.push_back(currPart);
                currPart.clear();
            }
        }
        else {
            currPart.push_back(n);
        }
    }
    if (!currPart.empty()) {
        parts.push_back(currPart);
    }

    unordered_map<int, int> occurr;

    for (const auto& part : parts) {
        unordered_set<int> uniquePart;

        for (int p : part) {
            uniquePart.insert(p);
        }
        for (int p : uniquePart) {
            occurr[p]++;
        }
    }

    int findVal;

    while (true) {
        cin >> findVal;

        if (findVal == 0) {
            break;
        }
        cout << occurr[findVal] << endl;
    }

    return 0;
}