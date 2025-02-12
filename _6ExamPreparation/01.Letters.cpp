// 01.Letters.cpp -> Exam Preparation
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    string input;
    getline(cin, input);

    map<char, set<string>> letterText;

    stringstream ss(input);
    string word;

    while (ss >> word) {

        word.erase(remove_if(word.begin(),
        word.end(),[](char c) { return !isalpha(c); }),
        word.end());



        set<char> processLetters;

        for (char c : word) {
            char lowerCaseChar = tolower(c);

            if (processLetters.find(lowerCaseChar) == processLetters.end()) {

                letterText[lowerCaseChar].insert(word);
                processLetters.insert(lowerCaseChar);
            }
        }
    }

    string line;

    while (getline(cin, line)) {

        if (line == ".") {
            break;
        }

        char letter = tolower(line[0]);

        if (letterText.find(letter) != letterText.end()) {

            for (const string& a : letterText[letter]) {
                cout << a << " ";
            }
            cout << endl;
        }
        else {
            cout << "---" << endl;
        }
    }
    return 0;
}
