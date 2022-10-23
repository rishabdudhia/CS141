#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void play(vector<string>&);
bool decide(vector<string>&, pair<int,int>&, int);
int move(pair<int,int>&, int, bool);

int main() {

    int size;
    int stunTime;
    cin >> size;
    cin >> stunTime;
    string currLine;
    vector<string> board;

    for (int i = 0; i < size; ++i) {
        cin >> currLine;
        board.push_back(currLine);
    }


    play(board);
    

    return 0;
}

void play (vector<string>& board) {
    int timeTaken = 0;
    pair<int,int> pos(0,0);

    bool nextMove = decide(board, pos, timeTaken);
    timeTaken
}