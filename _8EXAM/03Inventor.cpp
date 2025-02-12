// 03. Inventor.cpp -> C++ Advanced - Regular Exam - 8 February 2025
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
    double pricePerProduct, quantity;
    string buffer;

    cin.ignore();

    while (getline(cin, buffer)) {
        if (buffer.empty()) {
            break;
        }

        basic_istringstream<char> istr(buffer);
        if (!(istr >> city)) {
            continue;
        }

        if (!(cin >> pricePerProduct >> quantity)) {
            break;
        }
        cin.ignore();

        double totalPrice = quantity * pricePerProduct;
        cityTotalPrice[city] += totalPrice;
    }

    for (const auto& entry : cityTotalPrice) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
