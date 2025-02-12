// 06. Squares -> Exarcise
#include <iostream>
#include <set>                                 // Wrong result
#include <cmath>
using namespace std;


bool isSquareNumber(int num) {

    if (num < 0) return false; // if negative digits are NOT squares
    int sqr = sqrt(num);

    return sqr * sqr == num;
}

int main() {

    multiset<int, greater<int> > squareNumbers;

    int num;
    while (cin >> num) {

        if (isSquareNumber(num)) {
            squareNumbers.insert(num); // add square digit
        }

        if (cin.peek() == '\n') break;
    }

    for (const int& sqrNum : squareNumbers) {
        cout << sqrNum << " ";
    }
    cout << endl;
}
