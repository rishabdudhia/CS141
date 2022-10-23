#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int cars;
    int carSize;
    cin >> cars;
    cin >> carSize;
    
    string contents;
    int toadCount = 0;

    for (int i = 0; i < cars; ++i) {
        cin >> contents;

        for (int j = 0; j < carSize; ++j) {
            if (contents.at(j) == 't') {
                ++toadCount;
            }
        }
    }

    cout << toadCount << endl;

    return 0;
}