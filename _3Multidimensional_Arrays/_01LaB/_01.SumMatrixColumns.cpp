// 01. Sum Matrix Columns.cpp -> Lab
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    //int matrix[rows][cols];

    for (int R = 0; R < rows; R++) {

        for (int C = 0; C < cols; C++) { // четем матрицата
            cin >> matrix[R][C];
        }
    }

    for (int a = 0; a < cols; a++) {
        int buff = 0;

        for (int b = 0; b < rows; b++) {
            buff += matrix[b][a];
        }

        cout << buff << endl;
    }
    return 0;
}