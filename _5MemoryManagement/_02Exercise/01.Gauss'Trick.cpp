// 01. Gauss' Trick -> Memory Management, References and Pointers - Exercise
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main() {

    vector<int> list;
    string listBuff;
    getline(cin, listBuff);

    istringstream inpstr(listBuff);
    int num;

    while (inpstr >> num) {
        list.push_back(num);
    }

    int listSize = list.size();
    vector<int> result;

    for (int i = 0; i < (listSize + 1) / 2; i++) {

        if (i == listSize - 1 - i) {
            result.push_back(list[i]);
        }
        else {
            result.push_back(list[i] + list[listSize - 1 - i]);
        }
    }


    for (size_t i = 0; i < result.size(); i++) {

        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
