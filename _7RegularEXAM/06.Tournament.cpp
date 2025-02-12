// 03. Tournament.cpp -> C++ Advanced - Retake Exam
// Football Championship =)
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Team {

    int points = 0;
    int scoreGoals = 0;
    int receivedGoals = 0;
};

int main() {

    string line;
    getline(cin, line);
    istringstream teamStream(line);

    vector<string> players;
    map<string, Team> teamData;

    string team;
    while (teamStream >> team) {

        players.push_back(team);
        teamData[team] = Team();
    }

    while (getline(cin, line) && line != ".") {
        istringstream matchStream(line);

        string teamOne, teamTwo;
        int firstGoal, secondGoal;

        matchStream >> teamOne >> firstGoal >> teamTwo >> secondGoal;

        teamData[teamOne].scoreGoals += firstGoal;
        teamData[teamOne].receivedGoals += secondGoal;
        teamData[teamTwo].scoreGoals += secondGoal;
        teamData[teamTwo].receivedGoals += firstGoal;

        if (firstGoal > secondGoal) {
            teamData[teamOne].points += 3;
        }
        else if (firstGoal < secondGoal) {
            teamData[teamTwo].points += 3;
        }
        else {
            teamData[teamOne].points += 1;
            teamData[teamTwo].points += 1;
        }
    }

    int maxPoints = 0;
    vector<string> topTeams;

    for (const auto& teamName : players) {

        const Team& temp = teamData[teamName];

        cout << teamName << " - " << temp.points << " - "
             << temp.scoreGoals << " - " << temp.receivedGoals << endl << flush;

        if (temp.points > maxPoints) {

            maxPoints = temp.points;
            topTeams.clear();
            topTeams.push_back(teamName);
        }
        else if (temp.points == maxPoints) {

            topTeams.push_back(teamName);
        }
    }

    cout << "Top team(s) : ";

    for (size_t idx = 0; idx < topTeams.size(); idx++) {
        cout << topTeams[idx];

        if (idx < topTeams.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}