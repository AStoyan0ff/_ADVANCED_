// 03.Simple Calculator.cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// stack<int> digits;
// stack<char> operations; // used TWO staks

static int simpleCalculator(const string& expr) {

    istringstream iss(expr);

    int rslt = 0;
    int number;
    char op = '+';

    while (iss >> number) {

        if (op == '+') {
            rslt += number;
        }
        else if (op == '-') {
            rslt -= number;
        }

        iss >> op;
    }
    return rslt;
}

int main() {

    string line;
    getline(cin, line);

    int rslt = simpleCalculator(line);

    cout << rslt << endl;

    return 0; // Yabba-Dabba-Doo =)
}
