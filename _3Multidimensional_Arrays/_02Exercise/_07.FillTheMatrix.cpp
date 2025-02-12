// 07. Fill the Matrix.cpp -> Multidimensional Arrays - Exercise
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void matrixA(vector<vector<int>> &matrix, int N) {
    int num = 1;

    for (int cols = 0; cols < N; cols++) {

        for (int rows = 0; rows < N; rows++) {

            matrix[rows][cols] = num++;
        }
    }
}

void matrixB(vector<vector<int>> &matrix, int N) {
    int num = 1;

    for (int cols = 0; cols < N; cols++) {

        if (cols % 2 == 0) {

            for (int rows = 0; rows < N; rows++) {

                matrix[rows][cols] = num++;
            }
        } else {

            for (int rows = N - 1; rows >= 0; rows--) {

                matrix[rows][cols] = num++;
            }
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix, int N) {

    for (int rows = 0; rows < N; rows++) {

        for (int cols = 0; cols < N; cols++) {

            cout << matrix[rows][cols] << " ";
        }
        cout << endl;
    }
}

int main() {

    string line;
    getline(cin, line);

    int N = stoi(line.substr(0, line.find(',')));
    char symbol = line[line.find(',') + 2];

    vector<vector<int>> matrix(N, vector<int>(N));

    if (symbol == 'A') {

        matrixA(matrix, N);
    }
    else if (symbol == 'B') {

        matrixB(matrix, N);
    }

    printMatrix(matrix, N);

    return 0;
}

