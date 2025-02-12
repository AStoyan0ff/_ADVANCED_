#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalance(string& input) {
    stack<char> sex; // =)

    for (char c : input) {

        if (c == '(' || c == '{' || c == '[') {
            sex.push(c);
        }
        else {
            if (sex.empty()) return false;

            char topUp = sex.top();
            sex.pop();

            if ((c == ')' && topUp != '(') ||
                (c == '}' && topUp != '{') ||
                (c == ']' && topUp != '[')) {

                return false;
            }
        }
    }
    return sex.empty();
}

int main() {

    string input;
    getline(cin, input);

    if (isBalance(input)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0; // Yabba-Dabba-Doo =)
}
