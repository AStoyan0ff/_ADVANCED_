// 02.	Average Student Grades.cpp
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

    int N; cin >> N;

    map<string, vector<double>> studentRecords;

    for (int idx = 0; idx < N; idx++) {

        string studentName;
        double grade;
        cin >> studentName >> grade;

        studentRecords[studentName].push_back(grade);
    }
    for (const auto& [studentName, grades] : studentRecords) {
        cout << studentName << " -> ";

        double result = 0.0;

        for (const auto& grade : grades) {
            cout << setprecision(2) << fixed << grade << " ";
            result += grade;
        }

        double avrg = result / grades.size();

        cout << "(avg: " << setprecision(2) << fixed << avrg << ")" << endl;
    }
    return 0;
}