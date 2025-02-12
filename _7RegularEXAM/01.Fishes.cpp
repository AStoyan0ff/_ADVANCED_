// 01.Fishes.cpp -> C++ Advanced - Retake Exam
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {

    stack<string> flowA; //(LIFO - stack)
    queue<string> flowB; //(FIFO - queue)

    string fishName, flowType;

    while (cin >> fishName && fishName != "end") {
        cin >> flowType;

        if (flowType == "A") {
            flowA.push(fishName); // add in  A
        } else if (flowType == "B") {
            flowB.push(fishName); // add in B
        }
    }

    cout << "Flow A:" << endl;

    if (flowA.empty()) {
        cout << "<EMPTY>" << endl;
    } else {
        bool isFirst = true;

        while (!flowA.empty()) {

            if (!isFirst) {
                cout << ", ";
            }
            cout << flowA.top();

            flowA.pop();
            isFirst = false;
        }
        cout << endl;
    }

    cout << "Flow B:" << endl;

    if (flowB.empty()) {
        cout << "<EMPTY>" << endl;
    } else {
        bool isFirst = true;

        while (!flowB.empty()) {

            if (!isFirst) {
                cout << ", ";
            }
            cout << flowB.front();

            flowB.pop();
            isFirst = false;
        }
        cout << endl;
    }
    return 0; // AStoyanoff
}

