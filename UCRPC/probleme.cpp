#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {

    int timeLength;
    int upperOpen;
    int lowerOpen;
    cin >> timeLength >> upperOpen >> lowerOpen;
    int upperMaxperTime[timeLength];
    for (int i = 0; i < timeLength; ++i) {
        upperMaxperTime[i] = 0;
    }
    int lowerMaxperTime[timeLength];
    for (int i = 0; i < timeLength; ++i) {
        lowerMaxperTime[i] = 0;
    }
    
    int beginTime;
    int endTime;
    int bonus;
    int points;

    for (int i = 0; i < upperOpen; ++i) {
        scanf("%d %d %d", &beginTime, &endTime, &bonus);

        if (bonus == 0) {
            points = 1;
        }
        else if (bonus == 1) {
            points = 3;
        }

        for (int j = beginTime; j <= endTime; ++j) {
            upperMaxperTime[j] = points;
        }
    }

    for (int i = 0; i < lowerOpen; ++i) {
        scanf("%d %d %d", &beginTime, &endTime, &bonus);

        if (bonus == 0) {
            points = 1;
        }
        else if (bonus == 1) {
            points = 3;
        }

        for (int j = beginTime; j <= endTime; ++j) {
            lowerMaxperTime[j] = points;
        }
    }

    int sum = 0;
    for (int j = 0; j < timeLength; ++j) {
        if (upperMaxperTime[j] > lowerMaxperTime[j]) {
            sum = sum + upperMaxperTime[j];
        }
        else {
            sum = sum + lowerMaxperTime[j];
        }
    }

    cout << sum << endl;

    return 0;
}