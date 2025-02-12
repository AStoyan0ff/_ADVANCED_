// 04. Record Unique Names.cpp
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin.ignore();

    set<string> inputNames;
    vector<string> uniqueNames;

    string line;

    for (int idx = 0; idx < N; idx++) {
        getline(cin, line);

        if (inputNames.find(line) == inputNames.end()) {

            inputNames.insert(line);
            uniqueNames.push_back(line);
        }
    }

    for (const auto& uniqueName : uniqueNames) {
        cout << uniqueName << endl;
    }
    return 0;
}
