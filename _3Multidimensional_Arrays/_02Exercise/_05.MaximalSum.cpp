// 05. Maximal Sum.cpp -> Multidimensional Arrays – Exercise
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    const int MatrixRowSize = 3;
    const int MatrixColSize = 3;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int r = 0; r < N; r++) {

        for (int c = 0; c < M; c++) {
            cin >> matrix[r][c];
        }
    }

    int maxSum = numeric_limits<const int>::min(); // The largest Sum

    int row = 0;
    int col = 0;

    // 3 x 3 matrix with  MaxSum
    for (int a = 0; a <= N - MatrixRowSize; a++) {

        for (int b = 0; b <= M - MatrixColSize; b++) {
            int currSum = 0;

            // Calculate the Sum
            for (int x = 0; x < MatrixRowSize; x++) {

                for (int z = 0; z < MatrixColSize; z++) {
                    currSum += matrix[a + x][b + z];
                }
            }

            // Check the Sum is Biggest
            if (currSum > maxSum) {

                maxSum = currSum;
                row = a;
                col = b;
            }
        }
    }


    cout << "Sum = " << maxSum << endl;

    for (int indx = 0; indx < MatrixRowSize; indx++) {

        for (int indx2 = 0; indx2 < MatrixColSize; indx2++) {
            cout << matrix[row + indx][col + indx2] << " ";
        }

        cout << endl;
    }

    return 0;
}
