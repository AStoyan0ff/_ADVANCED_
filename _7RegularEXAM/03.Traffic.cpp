//03.Traffic - C++ Advanced (Regular Exam)
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin.ignore();

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int idx = 0; idx < N; idx++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[idx][j];
        }
    }
    cout << "  ";

    for (int idx = 0; idx < N; idx++) {
        cout << char('A' + idx) << " ";
    }
    cout << endl;

    for (int idx = 0; idx < N; idx++) {
        cout << char('A' + idx) << " ";

        for (int j = 0; j < N; j++) {
            cout << matrix[idx][j] << " ";
        }
        cout << endl;
    }

    vector<string> optimizations;
    int totalOpportunities = 0;

    unordered_map<int, vector<string>> maxOptimizations;
    int maxOpportunity = 0;

    for (int idx = 0; idx < N; idx++) {
        for (int j = idx + 1; j < N; j++) {
            int diff = abs(matrix[idx][j] - matrix[j][idx]);

            if (diff > 0) {
                stringstream ss;

                ss << char('A' + idx) << char('A' + j)
                   << "(" << matrix[idx][j] << ") - "
                   << char('A' + j) << char('A' + idx)
                   << "(" << matrix[j][idx] << ")";

                optimizations.push_back(ss.str());
                totalOpportunities += diff;

                if (diff > maxOpportunity) {

                    maxOpportunity = diff;
                    maxOptimizations[diff].clear();
                }
                if (diff == maxOpportunity) {
                    maxOptimizations[diff].push_back(
                        char('A' + idx) + string(1, char('A' + j)) + "-" +
                        char('A' + j) + string(1, char('A' + idx)));
                }
            }
        }
    }
    for (const auto& opt : optimizations) {
        cout << opt << endl;
    }
    cout << "Total opportunities: " << totalOpportunities << endl;

    if (maxOpportunity > 0) {
        cout << "Max optimization: " << maxOpportunity << ": ";

        for (size_t idx = 0; idx < maxOptimizations[maxOpportunity].size(); idx++) {
            cout << maxOptimizations[maxOpportunity][idx];

            if (idx != maxOptimizations[maxOpportunity].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Max optimization: none" << endl;
    }

    return 0; //AStoyanoff
}
