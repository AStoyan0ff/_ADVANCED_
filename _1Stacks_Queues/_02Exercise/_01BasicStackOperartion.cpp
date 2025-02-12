#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, S, X;
    cin >> N >> S >> X;

    stack<int> myStack;

    for (int idx = 0; idx < N; idx++) {
        int num;
        cin >> num;

        myStack.push(num); // add elements
    }

    // Remove S elements
    for (int idx = 0; idx < S && !myStack.empty(); idx++) {

        myStack.pop();
    }

    if (myStack.empty()) {
        cout << 0 << endl;
    } else {
        bool isFound = false;
        int smallNum = myStack.top();

        while (!myStack.empty()) {

            int curr = myStack.top();
            myStack.pop();

            if (curr == X) {
                isFound = true;
            }
            smallNum = min(smallNum, curr);
        }

        if (isFound) {
            cout << "true" << endl;
        } else {
            cout << smallNum << endl;
        }
    }

    return 0;
}
