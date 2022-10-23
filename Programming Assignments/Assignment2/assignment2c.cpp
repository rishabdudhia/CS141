#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compareSecond(const pair<int,int>& left, const pair<int, int>& right) {
    return left.second < right.second;
}

int main() {

    int currMoney;
    cin >> currMoney;
    vector<pair<int,int>> costs(9);
    int currCost;

    for (int i = 0; i < costs.size(); ++i) {
        cin >> currCost;
        costs.at(i).second = currCost;
        costs.at(i).first = i;
    }

    sort(costs.begin(), costs.end(), compareSecond);
    pair<int,int> cheapest = costs.at(0);

    for (int i = 0; i < 9; ++i) {
        if (costs.at(i).second == cheapest.second && costs.at(i).first > cheapest.first) {
            cheapest = costs.at(i);
        }
    }

    vector<int> accepted;
    while (currMoney > 0 && currMoney >= cheapest.second) {
        if (currMoney >= 2 * cheapest.second) {
            currMoney -= cheapest.second;
            accepted.push_back(cheapest.first);
        }
        else {
            for (int i = 0; i < 9; ++i) {
                if (costs.at(i).second == cheapest.second && costs.at(i).first > cheapest.first) {
                    cheapest = costs.at(i);
                }
            }
        }
    }

    return 0;
}