// 02.Deep Space - C++ Advanced (Regular Exam)
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {

    vector<string> matrix;
    string line;

    while (getline(cin, line) && line != "end") {
        matrix.push_back(line);
    }
    string replaceWord;
    cin >> replaceWord;

    map<char, int> starTypes;

    int totalStars = 0;
    int totalPlanets = 0;
    int totalAsteroidsComets = 0;

    for (const auto& row : matrix) {
        for (char c : row) {

            if (isalpha(c) && isupper(c)) { //Check stars
                starTypes[c]++;
                totalStars++;
            } else if (isdigit(c)) { // Check planets
                totalPlanets += c - '0';
            } else if (c == '#' || c == '$') { // Check Asteroids,Comets
                totalAsteroidsComets++;
            }
        }
    }

    for (auto& row : matrix) {
        for (char& c : row) {
            if (replaceWord.find(c) != string::npos) {
                c = '+';
            }
        }
    }
    cout << "Stars: " << totalStars << endl;

    for (const auto& [key, value] : starTypes) {
        cout << "- " << key << ": " << value << endl;
    }

    cout << "Planets: " << totalPlanets << endl;
    cout << "Asteroids/comets: " << totalAsteroidsComets << endl;

    for (const auto& row : matrix) {
        cout << row << endl;
    }
    return 0;
}
