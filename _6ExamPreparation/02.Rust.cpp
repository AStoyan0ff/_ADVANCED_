// 02.Rust.cpp -> Exam Preparation
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int a, int b, int n) {
    return a >= 0 && a < n && b >= 0 && b < n;
}

vector<vector<char>> rustSpread(vector<vector<char>> &matrix, int time) {

    int N = matrix.size();
    queue<pair<int, int>> rustQu;

    for (int idx = 0; idx < N; idx++) {

        for (int idx2 = 0; idx2 < N; idx2++) {

            if (matrix[idx][idx2] == '!') {
                rustQu.push({idx, idx2});
            }
        }
    }

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while (time -- > 0) {
        int nextSize = rustQu.size();

        for (int idx = 0; idx < nextSize; idx++) {

            auto [x, y] = rustQu.front();
            rustQu.pop();

            for (auto [dx, dy] : dir) {

                int nx = x + dx;
                int ny = y + dy;

                if (isValid(nx, ny, N) && matrix[nx][ny] == '.') {

                    matrix[nx][ny] = '!';
                    rustQu.push({nx, ny});
                }
            }
        }
    }

    return matrix;
}

int main() {

    int n = 10;
    vector<vector<char>> matrix(n, vector<char>(n));

    for (int idx = 0; idx < n; idx++) {

        for (int idx3 = 0; idx3 < n; idx3++) {
            cin >> matrix[idx][idx3];
        }
    }

    int time;
    cin >> time;

    vector<vector<char>> rslt = rustSpread(matrix, time);

    for (int indx = 0; indx < n; indx++) {

        for (int indx2 = 0; indx2 < n; indx2++) {
            cout << rslt[indx][indx2];
        }
        cout << endl;
    }
    return 0;
}
