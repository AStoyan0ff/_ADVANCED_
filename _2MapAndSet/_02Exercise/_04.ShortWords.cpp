// 04. Short Words -> Exarcise
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    string input;
    getline(cin, input);

    set<string> shortWords;

    stringstream ss(input);
    string word;

    while (ss >> word) {
        // Превръщане на думата в lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);


        if (word.size() < 5) {
            shortWords.insert(word);
        }
    }


    bool first = true;

    for (const auto& a : shortWords) {

        if (!first) {
            cout << ", ";
        }

        cout << a;
        first = false;
    }

    cout << endl;
}
