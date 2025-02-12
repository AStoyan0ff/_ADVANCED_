// 03. Squares in Matrix.cpp -> Multidimensional Arrays – Exercise
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    int R, C;
    cin >> R >> C;

    vector<vector<char>> matrix(R, vector<char>(C));

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {

            cin >> matrix[row][col];
        }
    }

    int cnt = 0;

    for (int indx = 0; indx < R - 1; indx++) {
        for (int indx2 = 0; indx2 < C - 1; indx2++) {

            if ( // Обхождане на всяка клетка ...
                matrix[indx][indx2] == matrix[indx][indx2 + 1] &&
                matrix[indx][indx2] == matrix[indx + 1][indx2] &&
                matrix[indx][indx2] == matrix[indx + 1][indx2 + 1]) {

                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}



