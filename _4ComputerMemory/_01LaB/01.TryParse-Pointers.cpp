//  01. TryParse.cpp -> Computer Memory, References and Pointers - LaB
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool tryParse(const string* str, int* number) {

    istringstream iss(*str);
    iss >> *number;
    // std::ios::eof

    //bool eof() const;
    // Тази функция може да се използва,
    // за да се провери дали повредата се дължи на
    // достигането на края на подаването или по някаква друга причина.

    // true, ако флагът за състояние на грешка "eof" на потока е зададен
    // (което сигнализира, че краят на файла е достигнат от последната операция за въвеждане).
    // невярно в противен случай.
    // Aко бъде хвърлено изключение, няма промени в потока.

    // std::ios::fail

    // bool fail() const;
    //Връща true, ако за потока са зададени флагове за състояние на грешка fail или bad.
    //Поне един от тези флагове се задава, когато възникне грешка по време на операция за въвеждане.
    //"fail" обикновено се задава от операция, когато грешката е свързана с
    // вътрешната логика на самата операция; може да са възможни допълнителни операции в потока.
    // Докато "bad" обикновено се задава, когато грешката включва загуба на целостта на потока,
    // която е вероятно да продължи дори ако се опита друга операция върху потока.
    // "bad" може да се провери независимо чрез извикване на членска функция "bad".

    return !(iss.fail() || !iss.eof());
}

int main() {

    string inp1, inp2;
    cin >> inp1 >> ws >> inp2;

    int digitOne, digitTwo;

    int* ptrDigitOne = &digitOne;
    int* ptrDigitTwo = &digitTwo;

    bool isAnalysis = tryParse(&inp1, ptrDigitOne);
    bool areAnalysis = tryParse(&inp2, ptrDigitTwo);

    if (isAnalysis && areAnalysis) {
        cout << (*ptrDigitOne + *ptrDigitTwo)<< endl;
    }
    else {
        if (!isAnalysis) {
            cout << "[error] " << inp1 << endl;
        }
        else {
            cout << inp1 << endl;
        }

        if (!areAnalysis) {
            cout << "[error] " << inp2 << endl;
        }
        else {
            cout << inp2 << endl;
        }
    }

    return 0;
}