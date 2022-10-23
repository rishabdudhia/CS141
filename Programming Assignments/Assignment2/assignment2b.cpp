#include <iostream>
#include <algorithm>

using namespace std;

int findMinPeople (int *, int);

int main() {

    int departments;
    int size;
    cin >> departments;
    int arr[departments];

    for (int i = 0; i < departments; ++i) {
        cin >> size;
        arr[i] = size;
    }

    cout << findMinPeople(arr,departments) << endl;

    return 0; 
}

int findMinPeople (int *arr, int departments) {
    sort(arr, arr + departments);

    int majority = 0;

    for (int i = 0; i < ((departments / 2) + 1); ++i) {
        majority += (arr[i] / 2) + 1;
    }
    
    return majority;
}