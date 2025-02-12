// 02. Remove Invalid.cpp -> Memory Management – Lab
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// Структура за съхранение на информацията за компанията
struct Company {
    string name;
    int id;
};

// Функция за проверка на валидност на ID
bool isValId(const int& id) {
    return id >= 0; // Валидно ID е не негативно
}

int main() {

    vector<Company> companies; // Вектор за съхранение на компаниите

    // Четене на входа
    while (true) {
        string input;
        getline(cin, input);

        if (input == "end") {
            break;
        }

        istringstream iss(input);

        int id;
        string name;
        iss >> id;
        getline(iss, name);

        name = name.substr(1); // Премахваме водещия интервал

        // Добавяме в списъка
        Company company = {name, id};
        companies.push_back(company);
    }

    // Филтриране и отпечатване на компании с валидни ID
    for (const Company& company : companies) {

        if (isValId(company.id)) {
            cout << company.id << " " << company.name << endl << flush;
        }
    }

    return 0;
}

