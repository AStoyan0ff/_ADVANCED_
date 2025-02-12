#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int foodQuantity;
    cin >> foodQuantity;

    queue<int> orders;
    int maxOrder = 0;

    string line;
    getline(cin >> ws, line);

    stringstream ss(line);
    int order;

    while (ss >> order) {

      orders.push(order);
        maxOrder = max(maxOrder, order);
    }

    cout << maxOrder << endl;

    while (!orders.empty()) {

        int currOrder = orders.front();

        if (foodQuantity >= currOrder) {

              foodQuantity -= currOrder;
                orders.pop();
        }
        else {
            break;
        }
    }

    if (orders.empty()) {
        cout << "Orders complete" << endl;
    }
    else {
        cout << "Orders left: ";

        while (!orders.empty()) {

            cout << orders.front();
            orders.pop();

            if (!orders.empty()) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
