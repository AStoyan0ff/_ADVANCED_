// 02. Positions Of.cpp -> Multidimensional Arrays – Exercise
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    int R, C; // Rows, Cols
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));

    for (int idx = 0; idx < R; idx++) {

        for (int idx2 = 0; idx2 < C; idx2++) {

            cin >> matrix[idx][idx2];
        }
    }

    int T; cin >> T; // Target

    bool isFound = false;

    for (int idx = 0; idx < R; idx++) {
        for (int idx2 = 0; idx2 < C; idx2++) {

            if (matrix[idx][idx2] == T) {
                cout << idx << " " << idx2 << endl;// The position

                isFound = true;
            }
        }
    }

    if (!isFound) {
        cout << "not found" << endl;
    }

    return 0; // Yabba-Dabba-Doo =)
}