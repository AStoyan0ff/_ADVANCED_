//  03. Order.cpp -> Computer Memory, References and Pointers - LaB
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Company {
    string name;
    string id;
};

bool isOrder(const Company& a, const Company& b) {
    return a.id < b.id;
}

int main() {

    vector<Company> companies;

    while (true) { // ForEver =)
        string input;
        getline(cin, input);

        if (input == "end")
            break;


        size_t pos = input.find(' ');
        string name = input.substr(0, pos);
        string id = input.substr(pos + 1);

        companies.push_back({name, id});
    }

    sort(companies.begin(), companies.end(), isOrder); // sort company ID

    for (const Company& company : companies) {
        cout << company.name << " " << company.id << endl << flush;
    }

    return 0;
}

