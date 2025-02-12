// 03. Symbol in Matrix.cpp -> Array -> Lab
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin >> ws;

    char matrix[N][N]; // char array
    cin.ignore();

    for (int idx = 0; idx < N; idx++) {

        string row;
        getline(cin, row);

        for (int a = 0; a < N; a++) {

            matrix[idx][a] = row[a];
        }
    }

    char c;
    cin >> c;

    for (int idx = 0; idx < N; idx++) {

        for (int a = 0; a < N; a++) {

            if (matrix[idx][a] == c) {

                cout << "(" << idx << ", " << a << ")" << endl;
                return 0;
            }
        }
    }

    cout << c << " does not occur in the matrix" << endl;

    return 0;
}