// 01.Count Same Values Array.cpp
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void cntSameValue(const vector<double>& numbers) {
    map<double, int> myMap;
    vector<double> myVector;

    for (double num : numbers) {

        if (myMap[num] == 0) {
            myVector.push_back(num);
        }
        myMap[num]++;
    }

    for (double num : myVector) {
        cout << num << " - " << myMap[num] << " times" << endl;
    }
}

int main() {

    string line;
    getline(cin, line);

    vector<double> numbers;
    size_t pos = 0;

    while (pos < line.size()) {
        double num;
        size_t end;

        num = stod(line.substr(pos), &end);
        numbers.push_back(num);
        pos += end;
    }

    cntSameValue(numbers);

    return 0;
}
