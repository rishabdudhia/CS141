#include <iostream>
#include <vector>

using namespace std;

int longestDec (int currPos, vector<long long>& sequence, vector<int>& vals) {
    if (currPos < 0) {
        return 0;
    }
    if (currPos == 0) {
        vals.at(0) = 1;
        return vals.at(0);
    }
    
    if (vals.at(currPos) != -1) {
        return vals.at(currPos);
    }

    if (currPos == 1) {
        if (sequence.at(currPos) < sequence.at(0)) {
            vals.at(currPos) = 2;
        }
        else vals.at(currPos) = 1;
        return vals.at(currPos);
    }
    int longest = 1;
    int temp = 0;



    for (int i = 0; i < currPos; ++i) {
        temp = longestDec (i, sequence, vals) + 1;
        if ((sequence.at(currPos) < sequence.at(i)) && temp > longest) {
            longest = temp;
        } 
    }

    vals.at(currPos) = longest;

    return longest;
}


int main() {

    int length = 0;
    cin >> length;
    long long currVal;
    vector<long long> sequence;

    for (int i = 0; i < length; ++i) {
        cin >> currVal;
        sequence.push_back(currVal);
    }

    vector<int> vals;
    for (int i = 0; i < sequence.size(); ++i) {
        vals.push_back(-1);
    }

    int longest = longestDec(sequence.size()-1, sequence, vals);
    
    int max = vals.at(0);
    for (int i = 1; i < vals.size(); ++i) {
        if (vals.at(i) > max) {
            max = vals.at(i);
        }
    }

    cout << max << endl;

    return 0;
}