#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int pathFromHelper (int location_i, int location_j, vector<vector<int>>& resort, vector<vector<int>>& resortVals, int x, int r, int c) {
    if ((location_i < 0) || (location_i >= r)) return 0;
    if ((location_j < 0) || (location_j >= c)) return 0;

    if (x > resort.at(location_i).at(location_j)) {
        return 0;
    }

    if (resortVals.at(location_i).at(location_j) != -1) {
        return resortVals.at(location_i).at(location_j);
    }

    int max = 0;
    int currVal = resort.at(location_i).at(location_j);
    int left = pathFromHelper (location_i, location_j-1, resort, resortVals, currVal, r, c) + 1;
    max = left;
    int right = pathFromHelper (location_i, location_j+1, resort, resortVals, currVal, r, c) + 1;
    if (right > max) max = right;
    int up = pathFromHelper (location_i-1, location_j, resort, resortVals, currVal, r, c) + 1;
    if (up > max) max = up;
    int down = pathFromHelper (location_i+1, location_j, resort, resortVals, currVal, r, c) + 1; 
    if (down > max) max = down; 

    resortVals.at(location_i).at(location_j) = max;

    return max;
}

int pathFrom (int location_i, int location_j, vector<vector<int>>& resort, vector<vector<int>>& resortVals, int r, int c) {
    int max = 0;
    int currVal = resort.at(location_i).at(location_j);
    int left = pathFromHelper (location_i, location_j-1, resort, resortVals, currVal, r, c) + 1;
    max = left;
    int right = pathFromHelper (location_i, location_j+1, resort, resortVals, currVal, r, c) + 1;
    if (right > max) max = right;
    int up = pathFromHelper (location_i-1, location_j, resort, resortVals, currVal, r, c) + 1;
    if (up > max) max = up;
    int down = pathFromHelper (location_i+1, location_j, resort, resortVals, currVal, r, c) + 1; 
    if (down > max) max = down; 

    resortVals.at(location_i).at(location_j) = max;
    return max;
}

int allPaths (vector<vector<int>>& resort, vector<vector<int>>& resortVals, int r, int c) {
    int max = -1;
    int curr = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            curr = pathFrom(i, j, resort, resortVals, r, c);
            resortVals.at(i).at(j) = curr;
            if (curr > max) {
                max = curr;
            }
        }
    }
    
    return max;
}

int main() {
    int r = 0;
    cin >> r;
    int c = 0;
    cin >> c;

    vector<int> temp;
    vector<vector<int>> resort; //made vec of ints instead of pairs
    int curr = 0;
    //pair<int,int> currPair;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> curr;
            temp.push_back(curr);
        }
        resort.push_back(temp);
        temp.clear();
    }
    vector<vector<int>> resortVals;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            temp.push_back(-1);
        }
        resortVals.push_back(temp);
        temp.clear();
    }

    cout << allPaths(resort, resortVals, r, c) << endl;
}