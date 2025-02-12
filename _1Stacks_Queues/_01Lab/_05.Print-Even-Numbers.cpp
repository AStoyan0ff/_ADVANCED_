// 05.PrintEvenNumbers.cpp
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string line;
    getline(cin, line);

    stringstream ss(line);
    queue<int> numbersQueue;

    int num;

    while (ss >> num) {
        numbersQueue.push(num);
    }
    bool isFirst = true;

    while (!numbersQueue.empty()) {
        int curr = numbersQueue.front();
        numbersQueue.pop();

        if (curr % 2 == 0) {
            if (!isFirst) {
                cout << ", ";
            }
            cout << curr;
            isFirst = false;
        }
    }
    cout << endl;
    return 0;
}