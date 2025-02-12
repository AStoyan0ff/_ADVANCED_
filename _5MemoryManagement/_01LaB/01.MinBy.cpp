// 01. MinBy.cpp -> Memory Management – Lab
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string findLexicographically(const vector<string>& words) {
    const string* earliest = &words[0]; // Указател към първата дума

    for (const string& word : words) {

        if (*earliest > word) {
            earliest = &word; // Пренасочваме указателя към новата най-ранна дума
        }
    }
    return *earliest;
}

string foundShortString(const vector<string>& words) {
    const string* shortest = &words[0]; // Указател към първата дума

    for (const string& word : words) {

        if (word.length() < shortest->length()) {
            shortest = &word; // Пренасочваме указателя към новата най-къса дума
        }
    }
    return *shortest;
}

string foundLongString(const vector<string>& words) {
    const string* longest = &words[0]; // Указател към първата дума

    for (const string& word : words) {

        if (word.length() > longest->length()) {
            longest = &word; // Пренасочваме указателя към новата най-дълга дума
        }
    }
    return *longest;
}

int main() {

    string inputLine;
    getline(cin, inputLine);

    int option;
    cin >> option;

    vector<string> words;

    istringstream iss(inputLine);
    string word;

    while (iss >> word) {
        words.push_back(word);
    }


    switch (option) {

        case 1: {
            string result = findLexicographically(words);
            cout << result << endl;
            break;
        }
        case 2: {
            string result = foundShortString(words);
            cout << result << endl;
            break;
        }
        case 3: {
            string result = foundLongString(words);
            cout << result << endl;
            break;
        }
        default:
            cerr << "Invalid option" << endl;
        break;
    }

    return 0;
}