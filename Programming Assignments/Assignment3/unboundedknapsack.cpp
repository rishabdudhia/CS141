#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int inSuitcase (int remaining, vector<int>& weightVals, vector<pair<int,int>>& items, int lowWeight) {
    if (weightVals.at(remaining) != -1) {
        return weightVals.at(remaining);
    }

    if (remaining < lowWeight) {
        weightVals.at(remaining)= 0;
        return 0;
    }

    int currBest = 0;
    int choose_i = 0;
    int leave_i = 0;

    for (int i = 0; i < items.size(); ++i) {
        if (items.at(i).first <= remaining) {
            leave_i = inSuitcase(remaining, weightVals, items, lowWeight);
            choose_i = inSuitcase(remaining - items.at(i).first, weightVals, items, lowWeight) + items.at(i).second;
            int currVal = leave_i;
            if (choose_i > currVal) {
                currVal = choose_i;
            }
            if (currVal > currBest) {
                currBest = currVal;
            }
        }
    }

    weightVals.at(remaining) = currBest;
    return currBest;
}


int main() {

    string currLine;
    string num;
    getline(cin, currLine);
    int r = 0;
    while (currLine.at(r) != ' ') {
        num.push_back(currLine.at(r));
        ++r;
    }
    int maxWeight = stoi(num);
    ++r;
    num.clear();
    while (r < currLine.size()) {
        num.push_back(currLine.at(r));
        ++r;
    }
    int n = stoi(num);
    
    int weight;
    int value;
    pair<int, int> curr;
    vector<pair<int, int>> items; //first: weight; second: value
    int lowWeight = 2000;
    

    for (int i = 0; i < n; ++i) {
        cin >> weight;
        cin >> value;
        if (weight < lowWeight) {
            lowWeight = weight;
        }

        curr.first = weight;
        curr.second = value;

        items.push_back(curr);
    }

    vector<int> weightVals(maxWeight+1, -1);
    
    int finalVal = inSuitcase(maxWeight, weightVals, items, lowWeight);

    for (int i = 0; i < maxWeight+1; ++i) {
        cout << weightVals.at(i) << ' ';
    }
    
    cout << endl << finalVal << endl;
    return 0;
}


