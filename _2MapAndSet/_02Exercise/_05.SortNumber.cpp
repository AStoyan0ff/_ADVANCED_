// 05.Sort Numbers -> Exarcise
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<double> digits;
    double num;

    while (cin >> num) {
        digits.push_back(num);

        if (cin.peek() == '\n') break;  // Спиране при край на реда
    }

    sort(digits.begin(), digits.end());

    for (size_t indx = 0; indx < digits.size(); indx++) {
        cout << digits[indx];

        if (indx != (digits.size() - 1)) {
            cout << " <= ";
        }
    }
    cout << endl;
}
