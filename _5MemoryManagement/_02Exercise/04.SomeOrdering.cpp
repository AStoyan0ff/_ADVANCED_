// 04. Some Ordering.cpp -> Memory Management, Pointers and References – Exercise
#include <iostream>
using namespace std;

// Функция за конвертиране на всички символи в низ към малки букви
void toLowerCase(char* str) {

    while (*str != '\0') {

        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

// Функция за конвертиране на всички символи в низ към главни букви
void toUpperCase(char* str) {

    while (*str != '\0') { // Докато не достигнем края на низа

        if (*str >= 'a' && *str <= 'z') {
            *str -= 32; // Превръщаме малка буква в главна
        }
        str++; // Придвижваме указателя към следващия символ
    }
}

int main() {

    char input[256]; // Създаваме достатъчно голям масив за входния низ [256]
    cin.getline(input, 256);

    // Създаваме копия на входния низ
    char lowerCase[256], upperCase[256];

    char* ptrInput = input; // Указател към входния низ
    char* ptrLower = lowerCase; // Указател към копието за малки букви
    char* ptrUpper = upperCase; // Указател към копието за главни букви

    // Копираме входния низ в двата нови масива
    while (*ptrInput != '\0') {

        *ptrLower = *ptrInput;
        *ptrUpper = *ptrInput;

        ptrLower++;
        ptrUpper++;
        ptrInput++;
    }
    *ptrLower = '\0'; // Добавяме терминираща нула в края
    *ptrUpper = '\0';

    // Конвертиране на копията
    toLowerCase(lowerCase);
    toUpperCase(upperCase);

    cout << lowerCase << endl;
    cout << upperCase << endl;

    return 0;
}
