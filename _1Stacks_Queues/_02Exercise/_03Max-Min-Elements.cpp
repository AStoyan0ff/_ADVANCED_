#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;

    stack<int> myStack;
    vector<int> out;

    for (int idx = 0; idx < N; idx++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;

            myStack.push(x);
        }
        else if (cmd == 2) {
            if (!myStack.empty()) {
                myStack.pop();
            }
        }
        else if (cmd == 3) {

            if (!myStack.empty()) {

              stack<int> temp = myStack;
                int maxElement = temp.top();

                while (!temp.empty()) {

                    maxElement = max(maxElement, temp.top());
                    temp.pop();
                }
                out.push_back(maxElement);
            }
        }
        else if (cmd == 4) {

            if (!myStack.empty()) {

              stack<int> temp = myStack;
                int minElement = temp.top();

                while (!temp.empty()) {

                    minElement = min(minElement, temp.top());
                    temp.pop();
                }
                out.push_back(minElement);
            }
        }
    }


    for (int val : out) {
        cout << val << endl;
    }

    vector<int> rmngElements;

    while (!myStack.empty()) {

      rmngElements.push_back(myStack.top());
        myStack.pop();
    }

    for (size_t idx = 0; idx < rmngElements.size(); idx++) {
        cout << rmngElements[idx];

        if (idx != rmngElements.size() - 1) {
            cout << ", ";
        }
    }

    return 0;
}
