// 02. Matrix Sum.cpp -> C++ Advanced - Regular Exam - 08 Feb 2025
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int input;
    cin >> input;

    vector<int> elements(input * input);

    for (int pos = 0; pos < input * input; pos++) {
        cin >> elements[pos];
    }

    int rslt = 0;

    for (int r = 0; r < input; r++) {
        for (int c = 0; c < input; c++) {

            if (r != c && r + c != input - 1) {
                int num = elements[r * input + c];

                if (num % 2 != 0) {
                    rslt += num;
                }
            }
        }
    }

    cout << "The sum is: " << rslt << endl;

    return 0;
}
