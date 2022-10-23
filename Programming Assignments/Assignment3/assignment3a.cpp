#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;

void countCandies (priority_queue<int, vector<int>, greater<int>>& candyQ, vector<int>& pastPiles) {
    if (candyQ.size() == 1) {
        return;
    }

    int first = candyQ.top();
    candyQ.pop();
    int second = candyQ.top();
    candyQ.pop();

    candyQ.push(first+second);
    pastPiles.push_back(first+second);
    
    countCandies(candyQ, pastPiles);
}

int main() {

    int initBags;
    cin >> initBags;
    int currCandies;
    priority_queue<int, vector<int>, greater<int>> candyQ;
    vector<int> pastPiles;

    for (int i = 0; i < initBags; ++i) {
        cin >> currCandies;
        candyQ.push(currCandies);    
    }

    countCandies(candyQ, pastPiles);
    int sum = 0;
    for (int i = 0; i < pastPiles.size(); ++i) {
        sum += pastPiles.at(i);
    }
    cout << sum * 2 << endl;

    return 0;
}