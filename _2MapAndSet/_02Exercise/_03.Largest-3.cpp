// 03. Largest 3 -> Exarcise
#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main() {
    // Обектен тип функция за извършване на сравнения. Основният шаблон извиква оператора > за тип T.
    multiset<double, greater<double>> numbers;
    double digit;

    while (cin >> digit) {
        numbers.insert(digit);

        if (cin.peek() == '\n') break;
    }

    int cnt = 0;

    for (const double& num : numbers) {

        cout << num << " ";
        cnt++;

        if (cnt == 3) break;
    }

    cout << endl;
}
