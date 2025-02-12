// 06. Reverse Matrix Diagonals.cpp -> Multidimensional Arrays - Exercise
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void ReverseMatrix(const vector<vector<int> > &matrix, int R, int C) {

    vector<vector<int> > diagonals(R + C - 1);

    for (int a = 0; a < R; a++) {

        for (int b = 0; b < C; b++) {

            diagonals[a + b].push_back(matrix[a][b]);
        }
    }

    for (int idx = diagonals.size() - 1; idx >= 0; idx--) {

        for (auto it = diagonals[idx].rbegin(); it != diagonals[idx].rend(); it++) {

            cout << *it << " ";
        }

        cout << endl;
    }
}

int main() {

    int R, C;
    cin >> R >> C;

    vector<vector<int> > matrix(R, vector<int>(C));

    for (int a = 0; a < R; a++) {

        for (int b = 0; b < C; b++) {

            cin >> matrix[a][b];
        }
    }

    ReverseMatrix(matrix, R, C);

    return 0;
}


