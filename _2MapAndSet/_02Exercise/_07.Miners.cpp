// 07. Miners.cpp -> Exarcise
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    vector<string> resources;
    vector<int> quantities;

    string resource;
    int quantity;

    while (true) {
        cin >> resource;

        if (resource == "stop")  break;
        cin >> quantity;

        bool isFound = false;

        for (size_t idx = 0; idx < resources.size(); idx++) {

            if (resources[idx] == resource) {
                quantities[idx] += quantity;

                isFound = true;
                break;
            }
        }

        if (!isFound) {

            resources.push_back(resource);
            quantities.push_back(quantity);
        }
    }

    for (size_t idx = 0; idx < resources.size(); idx++) {

        cout << resources[idx] << " -> " << quantities[idx] << endl;
    }

    return 0;
}
