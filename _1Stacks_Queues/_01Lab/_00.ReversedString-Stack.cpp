// 00.Reversed String.cpp - "Stack"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

void reverseString(const string &input) {
    stack<char> charSt;
    stack<string> strSt;


    stringstream ss(input);
    string word;

    while (ss >> word) {
        for (char c : word) {
            charSt.push(c);
        }

        string reversedWord;

        while (!charSt.empty()) {

            reversedWord += charSt.top();
            charSt.pop();
        }

        strSt.push(reversedWord);
    }


    while (!strSt.empty()) {
        cout << strSt.top();
        strSt.pop();

        if (!strSt.empty()) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {

    string input;
    getline(std::cin, input);

    reverseString(input);

    return 0;
}
