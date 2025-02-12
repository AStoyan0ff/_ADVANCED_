//  02. Find.cpp -> Computer Memory, References and Pointers - LaB
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Company {
    string name;
    string id;
};

int main() {

    vector<Company> companies;

    while (true) {
        string input;
        getline(cin, input);

        if (input == "end") {
            break;
        }

        istringstream iss(input);
        string name, id;
        iss >> name >> id;

        Company company = {name, id};
        companies.push_back(company);
    }

    string findId;
    cin >> findId;

    Company* foundCompany = nullptr; // *ptr to the find company

    for (Company& company : companies) {

        if (company.id == findId) {
            foundCompany = &company; // *ptr to the curr company
            break;
        }
    }

    if (foundCompany) {
        cout << foundCompany->name << " " << foundCompany->id << endl;
    }
    else {
        cout << "[not found]" << endl;
    }

    return 0;
}