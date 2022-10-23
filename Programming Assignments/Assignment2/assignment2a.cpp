#include<iostream>
#include<utility>

using namespace std;

int sort(int *, int, int, int);
int merge(int *, int, int, int, int);

int main() {

    int num;
    cin >> num;

    int arr[num];
    int input;

    for (int i = 0; i < num; ++i) {
        cin >> input;
        arr[i] = input;
    }
    int candyTotal = sort(arr,0, num-1, 0);

    // for (int i = 0; i < num; ++i) {
    //     cout << arr[i] << ' ';
    // }
    cout << candyTotal << endl;

    return 0; 
}

int sort(int *arr, int i, int k, int candyTotal) {
    if (i < k) {
        int j = (i + k) / 2;

        candyTotal = sort(arr,i,j, candyTotal);
        candyTotal = sort(arr,j+1,k, candyTotal);
        candyTotal = merge(arr, i, j, k, candyTotal);
    }

    return candyTotal;
}

int merge (int* arr, int i, int j, int k, int candyTotal) {
    int l1 = j - i + 1; 
    int l2 = k - j;
    int place = i;
    int rememberi = i;
    int rememberk = k;

    int arrL[l1+1];
    int arrR[l2+1];

    for (int r = 0; r < l1; ++r) {
        arrL[r] = arr[i];
        ++i;
    }
    arrL[l1] = -1;
    for (int r = 0; r < l2; ++r) {
        arrR[r] = arr[j+1];
        ++j;
    }
    arrR[l2] = -1;

    int r = 0;
    int l = 0;

    while (r <= l2 || l <= l1) {
        if (arrL[l] > arrR[r]) {
            arr[place] = arrL[l];
            ++l;
        }
        else {
            arr[place] = arrR[r];
            ++r;
        }
        if (arrL[l] == -1 && arrR[r] == -1) {
            break;
        }
        ++place;
    }
    int addCandies = arr[rememberi] - arr[rememberk];
    // cout << arr[rememberi] << arr[rememberk] << addCandies << endl;
    candyTotal = candyTotal + addCandies;

    return candyTotal;
}