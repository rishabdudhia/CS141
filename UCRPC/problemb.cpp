#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int numSwaps;
    cin >> numSwaps;
    int selectPlace = 3;
    
    int currSwap[2];
    int position;
    bool inTurn = false;

    for (int j = 0; j < numSwaps; ++j){
        for (int i = 0; i < 2; ++i) {
            cin >> position;
            currSwap[i] = position;
            if (position == selectPlace) {
                inTurn = true;
            }
        }
        if (!inTurn) {
            continue;
        }
        if (currSwap[0] == selectPlace) {
            selectPlace = currSwap[1];
        }
        else {
            selectPlace = currSwap[0];
        }

        inTurn = false;
    }
    

    
    cout << selectPlace << endl;

    return 0;
}





// string currSwap;

    // for (int i = 0; i <= numSwaps; ++i) {
    //     getline(cin, currSwap);
    //     if (currSwap.at(0) == selectPlace) {
    //         selectPlace = currSwap.at(2);
    //     }
    //     else if (currSwap.at(2) == selectPlace) {
    //         selectPlace = currSwap.at(0);
    //     }
    //     cin.clear();
    // }