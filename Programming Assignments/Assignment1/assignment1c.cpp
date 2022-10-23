#include <iostream>
#include <vector>

using namespace std;

void merge (vector<int>& scores, int p, int q, int r);
void sort (vector<int>& scores, int p, int r);


int main() {

    // cout << "Please enter the number of students in class: ";
    int students;
    cin >> students;

    vector<int> scores;
    int currScore;
    // cout << "Please enter the individual students' scores: " << endl;

    for (int i = 0; i < students; ++i) {
        cin >> currScore;
        scores.push_back(currScore);
    }

    sort (scores, 1, scores.size());

    // for (int i = 0; i < scores.size(); ++i) {
    //     cout << scores.at(i) << ' ';
    // }

    // cout << endl;

    // cout << "Please enter the number of queries you will have: ";

    int queries;
    int count;
    int rank;

    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        // cout << "Please enter the desired rank: ";
        cin >> rank;
        count = 1;

        if (rank == 1) {
            cout << scores.at(0) << endl;
        }

        else {
            for (int j = 1; j < scores.size(); ++j) {
                if (scores.at(j) == scores.at(j - 1)) {
                    continue;
                }
                ++count;
                if (count == rank) {
                    cout << scores.at(j) << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

void merge (vector<int>& scores, int p, int q, int r) {

    int accessp = p - 1;
    int accessq = q - 1;
    int accessr = r - 1;
    int length1 = q - p + 1;
    int length2 = r - q;
    int i;
    int j;
    int k;
    vector<int> left(length1+1);
    vector<int>right(length2+1);

    for (i = 0; i < length1; ++i) {
        left.at(i) = scores.at(accessp + i);
    }

    for (j = 0; j < length2; ++j) {
        right.at(j) = scores.at(q + j);
    }

    left.at(length1) = -1;
    right.at(length2) = -1;
    i = 0;
    j = 0;

    for (k = accessp; k < r; ++k) {
        if (left.at(i) == -1) {
            scores.at(k) = right.at(j);
            ++j;
        }
        else if (right.at(j) == -1) {
            scores.at(k) = left.at(i);
            ++i;
        }
        else if (left.at(i) > right.at(j)) {
            scores.at(k) = left.at(i);
            ++i;
        }
        else if (right.at(j) > left.at(i)) {
            scores.at(k) = right.at(j);
            ++j;
        }
        else if (right.at(j) == left.at(i)) {
            scores.at(k) = right.at(j);
            ++j;
        }
    }
}

void sort (vector<int>& scores, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        sort(scores,p,q);
        sort(scores,q+1,r);
        merge(scores,p,q,r);
    }
}