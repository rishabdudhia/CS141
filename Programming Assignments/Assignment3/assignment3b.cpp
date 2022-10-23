#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int inSuitcase (int remaining, int item, vector<vector<int>>& weightVals, vector<pair<int, int>>& items, int lowWeight) {
    
    if (weightVals.at(remaining).at(item) != -1) {
        return weightVals.at(remaining).at(item);
    }

    if (item == 0) {
        return 0;
    }

    if (remaining < lowWeight) {
        weightVals.at(remaining).at(item) = 0;
        return 0;
    }

    int currBest = inSuitcase(remaining, item-1, weightVals, items, lowWeight);
    int temp = 0;
    if (items.at(item-1).first <= remaining) {
        temp = inSuitcase(remaining-items.at(item-1).first, item-1, weightVals, items, lowWeight) + items.at(item-1).second;
    }
    if (temp > currBest) {
        currBest = temp;
    }
    weightVals.at(remaining).at(item) = currBest;
    return currBest;
}


int main() {

    int maxWeight;
    cin >> maxWeight;
    int n;
    cin >> n;
    
    int weight;
    int value;
    pair<int, int> curr; //first: weight; second: value
    vector<pair<int, int>> items;
    
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

    vector<vector<int>> weightVals;
    vector<int> temp;
    for (int i = 0; i < n+1; ++i) {
        if (i == 0) {
            temp.push_back(0);
        }
        else temp.push_back(-1);
    }
    for (int i = 0; i < maxWeight+1; ++i) {
        weightVals.push_back(temp);
    }
    for (int i = 0; i < temp.size(); ++i) {
        weightVals.at(0).at(i) = 0;
    }

    cout << inSuitcase(maxWeight, n, weightVals, items, lowWeight) << endl;

    return 0;
}