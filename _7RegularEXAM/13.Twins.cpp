// 03. Twins.cpp -> C++ Advanced - Retake Exam - 17 June 2023
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Client {

    string name;
    int processTime;
};

int main() {

    int N;
    cin >> N;

    queue<Client> pepiQu;
    queue<Client> mimiQu;

    for (int i = 0; i < N; i++) {

        string cash;
        string name;
        int processingTime;

        cin >> cash >> name >> processingTime;

        if (cash == "Pepi") {
            pepiQu.push({name, processingTime});
        }
        else if (cash == "Mimi") {
            mimiQu.push({name, processingTime});
        }
    }

    int T;
    cin >> T;

    Client currPepi = {"", 0};
    Client currMimi = {"", 0};

    for (int minute = 0; minute < T; minute++) {
        // Pepi's turn
        if (currPepi.processTime == 0) {

            if (!pepiQu.empty()) {

                currPepi = pepiQu.front();
                pepiQu.pop();
            }
            else {
                currPepi = {"", 0};
            }
        }

        if (currPepi.processTime > 0) {
            cout << "Pepi processing " << currPepi.name << endl;

            currPepi.processTime--;
        }
        else {
            cout << "Pepi Idle" << endl;
        }

        // Mimi's turn
        if (currMimi.processTime == 0) {

            if (!mimiQu.empty()) {

                currMimi = mimiQu.front();
                mimiQu.pop();
            }
            else {
                currMimi = {"", 0};
            }
        }

        if (currMimi.processTime > 0) {
            cout << "Mimi processing " << currMimi.name << endl;

            currMimi.processTime--;
        }
        else {
            cout << "Mimi Idle" << endl;
        }
    }

    return 0;
}