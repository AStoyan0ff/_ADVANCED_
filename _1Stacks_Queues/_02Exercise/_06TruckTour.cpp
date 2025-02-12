#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<pair<int, int>> petrolPumps(N);

    for (int idx = 0; idx < N; idx++) {
        int petrol, distance;
        cin >> petrol >> distance;

        petrolPumps[idx] = {petrol, distance};
    }

    int startIdx = 0;
    int totalPetrol = 0;
    int currPetrol = 0;

    for (int idx = 0; idx < N; idx++) {

        totalPetrol += petrolPumps[idx].first - petrolPumps[idx].second;
        currPetrol += petrolPumps[idx].first - petrolPumps[idx].second;

        if (currPetrol < 0) {

            startIdx = idx + 1;
            currPetrol = 0;
        }
    }

    if (totalPetrol < 0) {
        cout << -1 << endl;
    }
    else {
        cout << startIdx << endl;
    }
    return 0;
}
