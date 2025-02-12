// 02.Stacks Sum.cpp
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {

    stack<int> stack;
    string inputLine;

    getline(cin, inputLine);
    istringstream iss(inputLine);

    int number;

    while (iss >> number) {
        stack.push(number);
    }

    while (true) {
        getline(cin, inputLine);

        if (inputLine == "end") {
            break;
        }

        istringstream cmdStr(inputLine);
        string cmd;
        cmdStr >> cmd;

        if (cmd == "add") {
            int numOne, numTwo;

            cmdStr >> numOne >> numTwo;
            stack.push(numOne);
            stack.push(numTwo);
        }
        else if (cmd == "remove") {
            int cnt;
            cmdStr >> cnt;

            // Remove elements ...
            if (cnt <= stack.size()) {
                for (int idx = 0; idx < cnt; idx++) {
                    stack.pop();
                }
            }
        }
    }

    int sum = 0;

    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }

    cout << sum << endl;

    return 0; //Yabba-Dabba-Doo =)
}


