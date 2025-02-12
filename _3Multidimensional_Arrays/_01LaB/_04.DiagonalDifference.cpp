// 04. Diagonal Difference -> Multidimensional Arrays - LaB
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N; cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int x = 0; x < N; x++) {

        for (int y = 0; y < N; y++) {
            cin >> matrix[x][y];
        }
    }

    int firstDiagonal = 0;
    int secondDiagonal = 0;

    for (int x = 0; x < N; x++) {

        firstDiagonal += matrix[x][x];
        secondDiagonal += matrix[x][N - 1 - x];
    }

    int diff = abs(firstDiagonal - secondDiagonal);

    cout << diff << endl << flush; // отпечатва при DeBugg

    return 0;

}
