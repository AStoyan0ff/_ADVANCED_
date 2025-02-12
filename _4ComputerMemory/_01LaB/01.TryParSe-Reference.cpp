//  01. TryParse.cpp -> Computer Memory, References and Pointers - LaB
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool tryParse(const string& str, int& number) {

    istringstream iss(str);
    iss >> number;

    return !(iss.fail() || !iss.eof());
}

int main() {

    string inp1, inp2;
    cin >> inp1 >> ws >> inp2;

    int digitOne, digitTwo;

    bool isAnalysis = tryParse(inp1, digitOne);
    bool areAnalysis = tryParse(inp2, digitTwo);

    if (isAnalysis && areAnalysis) {
        cout << digitOne + digitTwo << endl;
    }
    else {
        if (!isAnalysis) {
            cout << "[error] " << inp1 << endl;
        }
        else {
            cout << inp1 << endl;
        }

        if (!areAnalysis) {
            cout << "[error] " << inp2 << endl;
        }
        else {
            cout << inp2 << endl;
        }
    }

    return 0;
}