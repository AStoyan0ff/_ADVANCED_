// 04.Snake Moves.cpp -> Multidimensional Arrays – Exercise
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {

    char R, C; // Rows, Cols
    cin >> R >> C;

    string snake;
    cin >> snake;

   // vector<vector<char>> matrix(R, vector<char>(C));
    vector<vector<char>> matrix(R,{C});

    int snakeIdx = 0;
    int snakeLenght = snake.size();

    for (int idx = 0; idx < R; idx++) {
        if (idx % 2 == 0) {

            for (int idx2 = 0; idx2 < C; idx2++) {

                matrix[idx][idx2] = snake[snakeIdx];
                snakeIdx = (snakeIdx + 1) % snakeLenght;
            }
        } else {

            for (int idx2 = C - 1; idx2 >= 0; idx2--) {

                matrix[idx][idx2] = snake[snakeIdx];
                snakeIdx = (snakeIdx + 1) % snakeLenght;
            }
        }
    }

    for (int idx = 0; idx < R; idx++) {

        for (int idx2 = 0; idx2 < C; idx2++) {
            cout << matrix[idx][idx2];
        }
        cout << endl << flush;
    }

    return 0; // Yabba-Dabba-Doo =)
}
