#include <iostream>

using namespace std;

int main() {

    int castleSize;
    int numRounds;
    cin >> castleSize;
    cin >> numRounds;
    int player1;
    int player2;
    int player3;
    int player4;
    int team1Total = castleSize;
    int team2Total = castleSize;
    bool gameDone = false;

    for (int i = 0; i < numRounds; ++i) {
        cin >> player1 >> player2 >> player3 >> player4;

        team1Total = team1Total - (player3 * player4);
        team2Total = team2Total - (player1 * player2);

        if (team1Total <= 0 && team2Total <= 0) {
            cout << "It's a tie at round " << (i + 1) << '!' << endl;
            gameDone = true;
            break;
        }
        else if (team1Total <= 0) {
            cout << "Team 2 wins at round " << (i + 1) << '!' << endl;
            gameDone = true;
            break;
        }
        else if (team2Total <= 0) {
            cout << "Team 1 wins at round " << (i + 1) << '!' << endl;
            gameDone = true;
            break;
        }
    }

    if (!gameDone) {
        cout << "Oh no!" << endl;
    }

    return 0;
}