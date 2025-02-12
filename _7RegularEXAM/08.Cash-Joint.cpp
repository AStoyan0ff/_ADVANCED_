#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {

    unordered_map<string, double> balances;
    vector<string> order;
    string command;

    // Четене на началните баланси
    while (true) {
        cin >> command;

        if (command == "END") break;

        double amount;
        cin >> amount;

        balances[command] = amount;
        order.push_back(command); // Запазваме реда на валутите
    }

    // Обработка на команди
    while (true) {
        cin >> command;

        if (command == "END") break;

        if (command == "+") {

            string currency;
            double amount;
            cin >> currency >> amount;
            balances[currency] += amount;
        }
        else if (command == "-") {

            string currency;
            double amount;
            cin >> currency >> amount;

            balances[currency] -= amount;
        }
        else if (command == "X") {

            string fromCurrency, toCurrency;
            double fromAmount, rate;
            cin >> fromCurrency >> fromAmount >> toCurrency >> rate;

            balances[fromCurrency] -= fromAmount;
            balances[toCurrency] += fromAmount * rate;
        }
        else if (command == "P") {

            for (const string& currency : order) {
                cout << currency << ": " << setprecision(2) << fixed << balances[currency] << endl;
            }
        }
    }
    return 0;
}