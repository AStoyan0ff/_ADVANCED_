// 06. Unique Username.cpp
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {

    int N;
    string input;
    getline(cin, input);

    istringstream iss(input);
    iss >> N;

    set<string> userSet;

    for (int indx = 0; indx < N; indx++) {
        string username;
        getline(cin, username);

        userSet.insert(username);
    }

    for (const auto& username : userSet) {
        cout << username << endl;
    }
    return 0;
}
