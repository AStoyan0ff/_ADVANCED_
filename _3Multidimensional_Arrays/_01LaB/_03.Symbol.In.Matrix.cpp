// 03. Symbol in Matrix.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int N;
    cin >> N >> ws;


    vector<vector<char>> matrix(N, vector<char>(N));

    for (int r = 0; r < N; r++) {

        string curRow;
        getline(cin, curRow);

        for (int c = 0; c < N; c++) {

            matrix[r][c] = curRow[c];
        }
    }

    char symbol;
    cin >> symbol;
    // Do not used WS here

    for (int r = 0; r < N; r++) {

        for (int c = 0; c < N; c++) {

            if (matrix[r][c] == symbol) {

                cout << "(" << r << ", " << c << ")" << endl;
                return 0;
            }
        }
    }

    cout << symbol << " does not occur in the matrix" << endl;

    return 0; // AStoyanoff baby =)
}
