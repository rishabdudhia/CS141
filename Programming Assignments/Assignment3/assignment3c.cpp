#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int inSuitcase (int remaining, int item, vector<vector<vector<int>>>& weightVals, vector<tuple<int, int, int>>& items, int lowWeight, int maxItems) {
    if (item == 0) {
        return 0;
    }
    int currTimesUsed = get<2>(items.at(item -1));

    if ((weightVals.at(get<2>(items.at(item -1))).at(item).at(remaining)) != -1) { 
        return weightVals.at(get<2>(items.at(item -1))).at(item).at(remaining);
    }

    if (remaining < lowWeight) {
        weightVals.at(get<2>(items.at(item -1))).at(item).at(remaining) = 0;
        return 0;
    }

    int currBest = inSuitcase(remaining, item-1, weightVals, items, lowWeight, maxItems);
    int temp = 0;
    bool inHere = false;
    if ((get<0>(items.at(item -1)) <= remaining) && (get<2>(items.at(item -1)) < maxItems)) {
        inHere = true;
        get<2>(items.at(item -1)) += 1;
        temp = inSuitcase(remaining-get<0>(items.at(item -1)), item, weightVals, items, lowWeight, maxItems) + get<1>(items.at(item -1)); //took out item - 1 for n value
    }
    
    // if (currBest > temp && inHere) {
    //     get<2>(items.at(item - 1)) = get<2>(items.at(item - 1)) - 1;
    //     weightVals.at(get<2>(items.at(item -1))).at(item).at(remaining) = currBest;
    //     return currBest;
    // }
    if (temp > currBest) {
        currBest = temp;
    }
    
    weightVals.at(currTimesUsed).at(item).at(remaining) = currBest;
    if (inHere){
        get<2>(items.at(item - 1)) = get<2>(items.at(item - 1)) - 1; 
    }
    return currBest;
}


int main() {

    int maxWeight = 0;
    cin >> maxWeight;
    int n = 0;
    cin >> n;
    int maxItems = 0;
    cin >> maxItems;
    
    int weight = 0;
    int value = 0;
    tuple<int, int, int> curr; //first: weight; second: value; third: times used
    vector<tuple<int, int , int>> items; // weight, value, timesUsed
    
    int lowWeight = 2000;
    

    for (int i = 0; i < n; ++i) {
        cin >> weight;
        cin >> value;
        if (weight < lowWeight) {
            lowWeight = weight;
        }
        curr = make_tuple(weight, value, 0);
        
        items.push_back(curr);
    }

    vector<vector<vector<int>>> weightVals;
    vector<vector<int>> temp;
    vector<int> temp2;
    for (int i = 0; i < maxWeight+1; ++i) {
        if (i == 0) temp2.push_back(0);
        else temp2.push_back(-1);
    }
    for (int i = 0; i < n+1; ++i) { 
        temp.push_back(temp2);
    }
    for (int i = 0; i < maxWeight+1; ++i) {
        temp.at(0).at(i) = 0;
    }
    for (int i = 0; i < maxItems+1; ++i) {
        weightVals.push_back(temp);
    }

    cout << inSuitcase(maxWeight, n, weightVals, items, lowWeight, maxItems) << endl;

    return 0;
}