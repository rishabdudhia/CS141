#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long sort(vector<long long>&, long long , long long);
long long merge(vector<long long>&, long long, long long, long long);

int main() {

    int numTrains;
    vector<long long> cars;
    long long number;
    cin >> numTrains;

    for (int i = 0; i < numTrains; ++i) {
        cin >> number;
        cars.push_back(number);
    }

    cout << sort(cars, 0, cars.size() - 1) << endl;

    return 0;
}

long long sort(vector<long long>& cars, long long l, long long r) {
    long long mid;
    long long count = 0;

    if (r > l) {
        mid = (l + r) / 2;

        count = count + sort(cars, l, mid);
        count = count + sort(cars, mid + 1, r);

        count = count + merge(cars, l, mid + 1, r);
    }

    return count;
}

long long merge(vector<long long>& cars, long long l, long long mid, long long r) {
    long long count = 0;
    vector<long long> holder;

    long long i = l;
    long long j = mid;
    
    while (i < mid && j <= r) {
        if (cars.at(i) < cars.at(j)) {
            holder.push_back(cars.at(i));
            ++i;
        }
        else {
            holder.push_back(cars.at(j));
            ++j;

            count = count + (mid - i);
        }
    }

    while (i < mid) {
        holder.push_back(cars.at(i));
        ++i;
    }
    while (j <= r) {
        holder.push_back(cars.at(j));
        ++j;
    }

    long long k = 0;
    for (i = l; i <= r; ++i) {
        cars.at(i) = holder.at(k);
        ++k;
    }

    return count;
}