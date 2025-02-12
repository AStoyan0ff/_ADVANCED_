// 01. Compare Matrices.cpp -> Multidimensional Arrays – Exercise
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<int>> readMatrix(int& rows) {
    cin >> rows;

    vector<vector<int>> matrix(rows);

    for (int indx = 0; indx < rows; indx++) {

        string line;
        getline(cin >> ws, line);

        stringstream ss(line);
        int number;

        while (ss >> number) {
            matrix[indx].push_back(number);
        }
    }
    return matrix;
}

bool checkMatrix(const vector<vector<int>>& matrxOne, const vector<vector<int>>& matrxTwo) {
    if (matrxOne.size() != matrxTwo.size()) return false;

    for (size_t indx = 0; indx < matrxOne.size(); indx++) {
        if (matrxOne[indx].size() != matrxTwo[indx].size()) return false;

        for (size_t mtrx = 0; mtrx < matrxOne[indx].size(); mtrx++) {
            if (matrxOne[indx][mtrx] != matrxTwo[indx][mtrx]) return false;
        }
    }
    return true;
}

int main() {

    int rowsOne, rowsTwo;

    vector<vector<int>> matrxOne = readMatrix(rowsOne);
    vector<vector<int>> matrxTwo = readMatrix(rowsTwo);

    if (checkMatrix(matrxOne, matrxTwo)) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    return 0;
}
