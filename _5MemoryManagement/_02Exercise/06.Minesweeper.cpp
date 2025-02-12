//06. Minesweeper.cpp -> Memory Management, Pointers and References – Exercise
#include <iostream>
using namespace std;

// int N, M;
//cin >> N >> M;
//unique_ptr<int[]>  arr = make_unique<int[]>(M*N)

void countMines(char matrix[100][100], int N, int M) {

    int m1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int m2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int result[100][100] = {0};


    for (int R = 0; R < N; R++) {
        for (int C = 0; C < M; C++) {

            if (matrix[R][C] == '!') {
                result[R][C]++;

                for (int S = 0; S < 8; S++) {

                    int a = R + m1[S];
                    int b = C + m2[S];

                    if (a >= 0 && a < N && b >= 0 && b < M) {
                        result[a][b]++;
                    }
                }
            }
        }
    }


    for (int R = 0; R < N; R++) {
        for (int C = 0; C < M; C++) {

            cout << result[R][C];
        }

        cout << endl;
    }
}

int main() {

    int n, m;
    char mat[100][100];

    cin >> n >> m;

    // Read the matrix
    for (int r = 0; r < n; r++) {

        for (int c = 0; c < m; c++) {
            cin >> mat[r][c];
        }
    }

    countMines(mat, n, m);

    return 0;
}

