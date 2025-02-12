//01. Format Lines.cpp -> C++ Advanced - Exam - 3 July 2021
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> divisionWords(const string& text) {

    vector<string> result;

    stringstream ss(text);
    string word;

    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

vector <string> formatLines(const vector<string>& result, int width) {

    vector <string> lines;
    string currLine;

    for (const string& word : result) {

        if (currLine.empty()) {
            currLine = word;
        }
        else {
            if (currLine.size() + 1 + word.size() <= width) {
                currLine += " " + word;
            }
            else {
                lines.push_back(currLine);
                currLine = word;
            }
        }
    }
    if (!currLine.empty()) {
        lines.push_back(currLine);
    }
    return lines;
}

int main() {

    string input;
    string str;

    while (getline(cin, input)) {

        if (input == "###") {
            break;
        }
        str += input + " ";
    }

    int maxWidth;
    cin >> maxWidth;

    vector <string> words = divisionWords(str);
    vector <string> formLines = formatLines(words, maxWidth);

    for (const string& word : formLines) {
        cout << word << endl;
    }

    return 0;
}