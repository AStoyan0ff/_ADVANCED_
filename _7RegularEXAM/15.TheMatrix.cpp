// 02. The Matrix.cpp -> C++ Advanced -> Regular Exam - 10 June 2023
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

auto checkNumber(const int N) -> bool {

    if (N == 1) return true;
    if (N <= 1) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;

    for (int pos = 3; pos <= sqrt(N); pos += 2) {
        if (N % pos == 0) return false;
    }
    return true;
}

int main() {

    int input;
    cin >> input;

    vector<vector<int> > matrix(input, vector<int>(input));

    for (int r = 0; r < input; r++) {
        for (int c = 0; c < input; c++) {

            cin >> matrix[r][c];
        }
    }
    int sum = 0;

    for (int r = 0; r < input; r++) {
        for (int c = 0; c < input; c++) {

            if (r > c && r + c > input - 1) {
                if (checkNumber(matrix[r][c])) {

                    sum += matrix[r][c];
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}





