// 02. Primary Diagonal.cpp -> Lab
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N; cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int x = 0; x < N; x++) {

        for (int y = 0; y < N; y++) {
            cin >> matrix[x][y];
        }
    }

    int primaryDiagonal = 0;

    for (int a = 0; a < N; a++) {
        primaryDiagonal += matrix[a][a];
    }

    cout << primaryDiagonal << endl;

    return 0;
}