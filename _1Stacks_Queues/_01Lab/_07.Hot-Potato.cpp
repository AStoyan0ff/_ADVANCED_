// 07.Hot-Potato.cpp
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string names;
    getline(cin, names);

    int cntChild;
    cin >> cntChild;

    queue<string> childrenQueue;
    stringstream ss(names);
    string inputName;

    while (ss >> inputName) {
        childrenQueue.push(inputName);
    }
    while (childrenQueue.size() > 1) {

        for (int idx = 1; idx < cntChild; idx++) {
            childrenQueue.push(childrenQueue.front());
            childrenQueue.pop();

        }
        cout << "Removed " << childrenQueue.front() << endl;
        childrenQueue.pop();
    }
    cout << "Last is " << childrenQueue.front() << endl;
    return 0;
    // AStoyanoff
}