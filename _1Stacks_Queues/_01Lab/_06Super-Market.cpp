// 06.SuperMarket.cpp - Stack and Queue - LaB
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


int main() {

    queue<string> queueCustomer;
    string input;

    while (true) {
        getline(cin, input);

        if (input == "End") {

            cout << queueCustomer.size() << " people remaining." << endl;
            break;
        }
        if (input == "Paid") {

            while (!queueCustomer.empty()) {

                cout << queueCustomer.front() << endl;
                queueCustomer.pop();
            }
        }
        else {
            queueCustomer.push(input);
        }
    }
    return 0;
}