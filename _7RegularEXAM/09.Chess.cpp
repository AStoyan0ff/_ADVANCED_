//02.Chess.cpp -> Regular Exam - 10 February 2024
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    const int SIZE = 8;
    vector<string> tableChess(SIZE);

    for (int pos = 0; pos < SIZE; pos++) {
        cin >> tableChess[pos];
    }

    string figureOfWhite = "";
    string figureOfBlack = "";

    for (int pos = 0; pos < SIZE; pos++) {

        for (char c : tableChess[pos]) {

            if (isupper(c))
                figureOfWhite += c;

            else if (islower(c))
                figureOfBlack += c;

        }
    }

    if (figureOfWhite.empty())
        cout << "<no white figures>" << endl;

    else
        cout << figureOfWhite << endl;

    if (figureOfBlack.empty())
        cout << "<no black figures>" << endl;

    else
        cout << figureOfBlack << endl;

    for (int pos = 0; pos < SIZE; pos++) {
        for (char &c : tableChess[pos]) {

            if (isupper(c))
                c = tolower(c);

            else if (islower(c))
                c = toupper(c);

        }
    }

    for (const string &as : tableChess)
        cout << as << endl;

    return 0;
}