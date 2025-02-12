#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int N, S, X;
    cin >> N >> S >> X;

    queue<int> qu;

    for (int i = 0; i < N; i++) {

        int num;
        cin >> num;

        qu.push(num);
    }

    for (int i = 0; i < S && !qu.empty(); i++) {
        qu.pop();
    }

    if (qu.empty()) {
        cout << 0 << endl;
    } else {
        bool isFound = false;
        int smallNum = qu.front();

        while (!qu.empty()) {

            int curr = qu.front();
            qu.pop();

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
