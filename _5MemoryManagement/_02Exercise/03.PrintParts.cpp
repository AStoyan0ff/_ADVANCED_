// 03. Print in Parts.cpp -> Memory Management, Pointers and References – Exarcise
#include <iostream>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    int** array = new int*[N];

    for (int r = 0; r < N; r++) {
        array[r] = new int[M];
    }

    // Четене на стойностите в масива
    for (int r = 0; r < N; r++) {

        for (int c = 0; c < M; c++) {
            cin >> array[r][c];
        }
    }

    int R, C;
    cin >> R >> C;

    // Ограничаване на R и C до размера на масива
    R = (R > N) ? N : R;
    C = (C > M) ? M : C;

    // Отпечатване на първите R реда и C колони
    for (int r = 0; r < R; r++) {

        for (int c = 0; c < C; c++) {
            cout << array[r][c] << " ";
        }
        cout << endl;
    }

    // Освобождаване на паметта
    for (int r = 0; r < N; r++) {
        delete[] array[r];
    }

    delete[] array;

}

