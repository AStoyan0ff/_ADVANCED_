// 01.Reversed String.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

static string reverseWords(const string& input) {

    istringstream stream(input);
    vector<string> words;
    string word;

    while (stream >> word) {

        reverse(word.begin(), word.end());
        words.push_back(word);
    }

    reverse(words.begin(), words.end());


    ostringstream result;

    for (size_t idx = 0; idx < words.size(); idx++) {
        result << words[idx];

        if (idx < words.size() - 1) {
            result << " ";
        }
    }

    return result.str();
}

int main() {

    string input;
    getline(cin, input);

    string reversed = reverseWords(input);
    cout << reversed << endl;

    return 0;
}
