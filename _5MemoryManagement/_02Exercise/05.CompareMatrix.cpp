//05. Compare Matrices.cpp -> Memory Management, Pointers and References – Exercise
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool ifEqual(int firstMatrix[10][10], int secondMatrix[10][10], int rows, int cols) {

    for (int R = 0; R < rows; R++) {

        for (int C = 0; C < cols; C++) {

            if (firstMatrix[R][C] != secondMatrix[R][C]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int rowsOne, colsOne = 0, rowsTwo, colsTwo = 0;
    int m1[10][10], m2[10][10];

    cin >> rowsOne;
    cin.ignore();

    for (int R = 0; R < rowsOne; R++) {

        string line;
        getline(cin, line);
        stringstream ss(line);

        int num, C = 0;

        while (ss >> num) {

            m1[R][C] = num;
            C++;
        }
        if (R == 0) {
            colsOne = C;
        }
    }
    cin >> rowsTwo;
    cin.ignore();

    for (int R = 0; R < rowsTwo; R++) {

        string input;
        getline(cin, input);
        stringstream ss(input);

        int num, C = 0;

        while (ss >> num) {

            m2[R][C] = num;
            C++;
        }
        if (R == 0) {
            colsTwo = C;
        }
    }

    if (rowsOne != rowsTwo || colsOne != colsTwo) {

        cout << "not equal" << endl;
        return 0;
    }


    if (ifEqual(m1, m2, rowsOne, colsOne)) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

}