#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {

    int numCities;
    cin >> numCities;

    map<string, double> cityTotalPrice;

    string city;
    double price, quantity;
    string buff;
    cin.ignore();

    while (getline(cin, buff)) {
        if (buff.empty()) {
            break;
        }

        basic_istringstream<char> iss(buff);
        if (!(iss >> city)) {
            continue;
        }

        if (!(cin >> price >> quantity)) {
            break;
        }
        cin.ignore();

        double totalPrice = quantity * price;
        cityTotalPrice[city] += totalPrice;
    }

    for (const auto& entry : cityTotalPrice) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
