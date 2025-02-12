// 04.MatchingBrackets.cpp
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

static void MatchingBrackets(const string& temp) {
    stack<int> brackets;

    for (size_t idx = 0; idx < temp.size(); idx++) {
        if (temp[idx] == '(') {
            brackets.push(idx);
        }
        else if (temp[idx] == ')') {
            int startIdx = brackets.top();
            brackets.pop();

            string subSrt = temp.substr(startIdx, idx - startIdx + 1);
            cout << subSrt << endl;
        }
    }
}

int main() {

    string attempt;
    getline(cin, attempt);

    MatchingBrackets(attempt);

    return 0; // Yabba-Dabba-Doo =)
}
