// 02. Transporter - C++ Advanced (Regular Exam)
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Station {
    string name;
    int search;
};

int main() {

    vector<Station> stations;
    vector<int> pallets;
    string line;

    while (getline(cin, line) && line != "end") {

        istringstream iss(line);
        Station station;

        iss >> station.name >> station.search;
        stations.push_back(station);
    }

    getline(cin, line);
    istringstream iss(line);

    int pallet;

    while (iss >> pallet) {
        pallets.push_back(pallet);
    }

    int allRemaining = 0;

    for (int in : pallets) allRemaining += in;
    vector<int> remainPallets = pallets;

    bool outOfStock = false;
    int completedSearch = 0;

    for (auto& station : stations) {

        if (allRemaining == 0) {

            completedSearch += station.search;
            outOfStock = true;

            cout << station.name << " Out of Stock!" << endl;
            continue;
        }

        int needed = station.search;
        vector<pair<int, int>> deliveries;

        for (int idx = remainPallets.size() - 1; idx >= 0 && needed > 0; idx--) {

            if (remainPallets[idx] > 0) {

                int toDeliver = min(needed, remainPallets[idx]);
                deliveries.emplace_back(idx, toDeliver);

                remainPallets[idx] -= toDeliver;
                needed -= toDeliver;
                allRemaining -= toDeliver;
            }
        }

        cout << station.name;

        for (auto& delivery : deliveries) {
            cout << " " << delivery.first << ":" << delivery.second;
        }

        if (needed > 0) {
            cout << " Out of Stock!";

            completedSearch += needed;
            outOfStock = true;
        }
        cout << endl;
    }

    int remainPacks = 0;

    for (int cnt : remainPallets) {
        remainPacks += cnt;
    }

    if (outOfStock) {
        cout << "Incomplete: " << completedSearch << endl;
    }
    else if (remainPacks > 0) {
        cout << "Remaining packs: " << remainPacks << endl;
    }

    return 0;
}

