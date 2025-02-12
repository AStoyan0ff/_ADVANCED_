#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool earliestLexicographically(const string & current, const string & result) {
    return current < result;
}

bool shortestString(const string & current, const string & result) {
    return current.length() < result.length();
}

bool longestString(const string & current, const string & result) {
    return current.length() > result.length();
}

bool constainsA(const string & current, const string & result) {
    if (result.find('a') != string::npos)
        return false;
    return current.find('a') != string::npos;
}

int main() {

    string line;
    getline(cin, line);

    vector<string> data;

    istringstream istr(line);

    while(istr >> line)
        data.push_back(line);

    int operationCode;
    cin >> operationCode;

    bool (*func)(const string & current, const string & result);

    switch(operationCode) {
        case 1:
            func = earliestLexicographically;
        break;
        case 2:
            func = shortestString;
        break;
        case 3:
            func = longestString;
        break;
        case 4:
            func = constainsA;
        break;
    }

    string result = data[0];

    for(size_t curr = 1; curr < data.size(); curr++)
        if (func(data[curr], result))
            result = data[curr];

    cout << result << endl;

    return 0;
}