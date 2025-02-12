//03. Simple Calculator II used Queue
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

int simpleCalculator(const string &exp) {
    queue<string> qu;

    stringstream ss(exp);
    string input;

    while (ss >> input) {
        qu.push(input);
    }

    int rslt = stoi(qu.front());
    qu.pop();

    while (!qu.empty()) {
        string op = qu.front();
        qu.pop();

        if (!qu.empty()) {
            int digit = stoi(qu.front());
            qu.pop();

            if (op == "+") {
                rslt += digit;
            } else if (op == "-") {
                rslt -= digit;
            }
        }
    }
    return rslt;
}

int main() {

    string expr;
    getline(cin, expr);

    int rslt = simpleCalculator(expr);

    cout  << rslt << endl;

    return 0; // by AStoyanoff
}
