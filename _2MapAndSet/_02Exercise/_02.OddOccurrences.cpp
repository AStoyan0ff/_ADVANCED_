// 02. Odd Occurrences.cpp -> Exarcise
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    string input;
    getline(cin, input);

    map<string, int> wordCnt;
    vector<string> vectStr;

    stringstream ss(input);
    string word;

    while (ss >> word) {
        // Change "word" to  lowercase -> ::tolower
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (wordCnt[word] == 0) {
            vectStr.push_back(word);
        }
        wordCnt[word]++;
    }

    bool bFirst = true;

    for (const string& word : vectStr) {

        if (wordCnt[word] % 2 != 0) {

            if (!bFirst) {
                cout << ", ";
            }

            cout << word;
            bFirst = false;
        }
    }

    cout << endl;
    return 0;
}
