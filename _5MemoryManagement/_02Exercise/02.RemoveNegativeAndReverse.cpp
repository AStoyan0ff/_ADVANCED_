// 02. Remove Negative and Reverse.cpp -> Memory Management, Pointers and References – Exercise
#include <iostream>
#include <sstream>
#include <list>
using namespace std;

int* removeReverse(int* arr, int size, int& newSize) {

    newSize = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] >= 0) newSize++;


    if (newSize == 0)
        return nullptr;


    int* newArr = new int[newSize];
    int indx = 0;


    for (int i = size - 1; i >= 0; i--) {

        if (arr[i] >= 0)
            newArr[indx++] = arr[i];

    }
    return newArr;
}

int main() {

    string input;
    getline(cin, input);

    istringstream iss(input);

    int* digit = new int[100]; // Temp Arr
    int size = 0, number;

    while (iss >> number)
        digit[size++] = number;


    int newSize = 0;
    int* result = removeReverse(digit, size, newSize);

    if (result == nullptr)
        cout << "empty" << endl;

    else {

        for (int i = 0; i < newSize; i++) {

            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
        delete[] result;
    }

    delete[] digit;

    return 0;
}
