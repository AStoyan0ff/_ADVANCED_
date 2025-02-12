// 01. Government Facility.cpp -> Regular Exam – 10 February 2024
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {

    queue<string> quOne, quTwo;
    stack<string> chairSt;

    string cmd;

    while (cin >> cmd) {

        if (cmd == "5") {
            break;
        }
        else if (cmd == "10") {

            if (!quOne.empty()) {
                quOne.pop();
            }
        }
        else if (cmd == "20") {
            if (!quTwo.empty()) {
                quTwo.pop();
            }
        }
        else if (cmd == "12") {

            if (!quOne.empty()) {

                string person = quOne.front();
                quOne.pop();
                quTwo.push(person);
            }
        }
        else if (cmd == "23") {

            if (!quTwo.empty()) {

                string person = quTwo.front();
                quTwo.pop();
                chairSt.push(person);
            }
        }
        else if (cmd == "31") {

            if (!chairSt.empty()) {

                string person = chairSt.top();
                chairSt.pop();
                quOne.push(person);
            }
        }
        else if (cmd == "99") {
            cout << "1: ";

            if (quOne.empty()) {
                cout << "<empty>";
            }
            else {
                queue<string> temp = quOne;

                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
            }
            cout << endl;

            cout << "2: ";

            if (quTwo.empty()) {
                cout << "<empty>";
            }
            else {
                queue<string> temp = quTwo;

                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
            }
            cout << endl;

            cout << "3: ";

            if (chairSt.empty()) {
                cout << "<empty>";
            }
            else {
                stack<string> temp = chairSt;

                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
            }
            cout << endl;
        }
        else {

            string name = cmd;

            int quNum;
            cin >> quNum;

            if (quNum == 1) {
                quOne.push(name);
            }
            else if (quNum == 2) {
                quTwo.push(name);
            }
        }
    }

    return 0;
}