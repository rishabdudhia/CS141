#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minEdit (int p1, int p2, vector<int>& string1, vector<int>& string2, vector<vector<int>>& vals) {
    if (p1 < 0) {
        int sum = 0;
        for (int i = 0; i <= p2; ++i) {
            sum += string2.at(i);
        }
        return sum;
    }
    if (p2 < 0) {
        int sum = 0;
        for (int i = 0; i <= p1; ++i) {
            sum += string1.at(i);
        }
        return sum;
    }

    if (vals.at(p1).at(p2) != -1) {
        return vals.at(p1).at(p2);
    }

    if (string1.at(p1) == string2.at(p2)) {
        vals.at(p1).at(p2) = minEdit(p1-1, p2-1, string1, string2, vals);
        return vals.at(p1).at(p2);
    }
    vector<int> currVals;
    int delete1 = minEdit(p1-1,p2,string1, string2, vals) + string1.at(p1);
    currVals.push_back(delete1);
    int delete2 = minEdit(p1,p2-1,string1,string2,vals) + string2.at(p2);
    currVals.push_back(delete2);
    int insert1 = minEdit(p1, p2-1, string1, string2, vals) + string2.at(p2);
    currVals.push_back(insert1);
    int insert2 = minEdit(p1-1,p2,string1,string2,vals) + string1.at(p1);
    currVals.push_back(insert2);
    int change = minEdit(p1-1, p2-1, string1, string2, vals) + abs(string1.at(p1)-string2.at(p2));
    currVals.push_back(change);

    int min = currVals.at(0);
    for (int i = 1; i < currVals.size(); ++i) {
        if (currVals.at(i) < min) {
            min = currVals.at(i);
        }
    }

    vals.at(p1).at(p2) = min;
    return vals.at(p1).at(p2);
}

int main() {
    int length1 = 0;
    int length2 = 0;

    cin >> length1 >> length2;

    int currVal;
    vector<int> string1;
    vector<int> string2;

    for (int i = 0; i < length1; ++i) {
        cin >> currVal;
        string1.push_back(currVal);
    }
    for (int i = 0; i < length2; ++i) {
        cin >> currVal;
        string2.push_back(currVal);
    }

    vector<vector<int>> vals;
    vector<int> temp;
    for (int i = 0; i < length2; ++i) {
        temp.push_back(-1);
    }
    for (int i = 0; i < length1; ++i) {
        vals.push_back(temp);
    }
    cout << minEdit (length1-1, length2-1, string1, string2, vals) << endl;
    return 0;
}