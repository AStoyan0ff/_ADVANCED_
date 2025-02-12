//01. Shopping List.cpp -> C++ Advanced - Regular Exam - 10 June 2023
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

struct ShoppingProducts {

    string name;
    double price;
    size_t count;
    double finalPrice;
};

int main(){

    size_t input;
    cin >> input;

    unordered_map<string, double> productsMap;
    vector<string>productsVect(input);
    set<double, greater<>>productsPrices;

    double result = 0;

    for(size_t pos = 0; pos < input; pos++) {

        string productName;
        double productPrice, productFinalPrice;
        size_t productCount;

        cin >> productName >> productPrice >> productCount;

        productFinalPrice = productCount * productPrice;

        productsMap[productName] = productFinalPrice;
        productsVect[pos] = productName;

        result += productFinalPrice;

        if (!productsPrices.count(productFinalPrice))
            productsPrices.insert(productFinalPrice);
    }

    cout << "The total sum is: " << result << " lv." << endl;

    for(double finalPrice : productsPrices)

        for(const string productName : productsVect)

            if(productsMap[productName] == finalPrice)
                cout << productName << ' ' << finalPrice << endl;

    return 0;
}
