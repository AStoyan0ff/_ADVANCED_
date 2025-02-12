#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {

    string clothesLine;
    getline(cin, clothesLine);

    int rackCapacity;
    cin >> rackCapacity;

    stack<int> clothesStack;

    stringstream ss(clothesLine);
    int clothVal;

    while (ss >> clothVal) {
        clothesStack.push(clothVal);
    }

    int currRackCapacity = 0;
    int racksCnt = 1;

    while (!clothesStack.empty()) {
        int currClothing = clothesStack.top();


        if (currRackCapacity + currClothing <= rackCapacity) {

            currRackCapacity += currClothing;
            clothesStack.pop();
        }
        else {

            racksCnt++;
            currRackCapacity = 0;
        }
    }

    cout << racksCnt << endl;

    return 0;
}
