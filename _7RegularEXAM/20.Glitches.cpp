//03. Glitches.cpp -> C++ Advanced - Exam - 3 July 2021
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    int input;
    cin >> input;

    vector<vector<char> > matrix(input, vector<char>(input));

    for (int row = 0; row < input; row++) {
        for (int col = 0; col < input; col++) {
            cin >> matrix[row][col];
        }
    }

    for (int row = 0; row < input; row++) {
        for (int col = 0; col < input; col++) {
            if (matrix[row][col] != '.') {
                char symbol = matrix[row][col];

                int top = row;
                int bottom = row;
                int left = col;
                int right = col;

                while (top > 0 && matrix[top - 1][col] == symbol) top --;
                while (bottom < input - 1 && matrix[bottom + 1][col] == symbol) bottom ++;
                while (left > 0 && matrix[row][left - 1] == symbol) left --;
                while (right < input - 1 && matrix[row][right + 1] == symbol) right ++;

                int centerRow = (top + bottom) / 2;
                int centerCol = (left + right) / 2;

                for ( int r = top; r <= bottom; r++ ) {
                    for (int c = left; c <= right; c++ ) {

                        if (r != centerRow ||c != centerCol) {
                            matrix[r][c] = '.';
                        }
                    }
                }
            }
        }
    }

    for (int row = 0; row < input; row++) {
        for (int col = 0; col < input; col++) {
            cout << matrix[row][col];
        }
        cout << endl;
    }
    return 0;
}



