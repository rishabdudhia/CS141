#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

int find(vector<int>& settledCities, int city) {
    bool found = false;
    for (int i = 0; i < settledCities.size(); ++i) {
        if (settledCities.at(i) == city) {
            found = true;
            return i;
        }
    }
    return -1;
}

void FindDist(vector<vector<pair<int,int>>>& graph, vector<int>& tentDistances, int start, int desired, int maxWeight) {
    vector<int> settledCities;
    // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
    // tuple<int, int, int> t1 = {2, 3, 1};
    // tuple<int, int, int> t2 = {4, 6, 3};
    // tuple<int, int, int> t3 = {1, 9, 11};
    // tuple<int, int, int> t4 = {2, 4, 2};
    // Q.push(t1);
    // Q.push(t2);
    // Q.push(t3);
    // Q.push(t4);
    // tuple<int, int, int> curr;
    // for (int i = 0; i < 4; ++i) {
    //     curr = Q.top();
    //     Q.pop();
    //     cout << get<0>(curr) <<' ' << get<1>(curr) << ' '<< get<2>(curr) << endl;
    // }
    vector<tuple<int, int, int>> Q;
    tentDistances.at(start) = 0;
    tuple<int, int, int> curr;
    get<0>(curr) = tentDistances.at(start); //dist from start
    get<1>(curr) = start; //current city
    get<2>(curr) = -1; // city that rested tent dist
    Q.push_back(curr);
    tuple<int, int, int> neighbor;
    get<0>(neighbor) = 0;
    get<1>(neighbor) = 0;
    get<2>(neighbor) = 0;
    int min = 0;

    while (!Q.empty()) {
        min = 0;
        for (int i = 0; i < Q.size(); ++i){ 
            if (get<0>(Q.at(i)) < get<0>(Q.at(min))) {
                min = i;
            }
        }
        curr = Q.at(min);
        Q.erase(Q.begin()+min);
        settledCities.push_back(get<1>(curr));
        tentDistances.at(get<1>(curr)) = get<0>(curr);
        for (int i = 0; i < graph.at(get<1>(curr)).size(); ++i) {
            if (find (settledCities, graph.at(get<1>(curr)).at(i).first) != -1) {
                continue;
            }
            if (tentDistances.at(graph.at(get<1>(curr)).at(i).first) != maxWeight) {
                int possDist = get<0>(curr) + graph.at(get<1>(curr)).at(i).second;
                if (possDist < tentDistances.at(graph.at(get<1>(curr)).at(i).first)) {
                    tentDistances.at(graph.at(get<1>(curr)).at(i).first) = possDist;
                    int want = 0;
                    int looking = graph.at(get<1>(curr)).at(i).first;
                    for (int j = 0; j < Q.size(); ++j) {
                        want = get<1>(Q.at(j));
                        if (want == looking) {
                            get<0>(Q.at(j)) = possDist;
                            get<2>(Q.at(j)) = get<1>(curr);
                        }
                    }
                }
            }
            else {
                get<0>(neighbor) = get<0>(curr) + graph.at(get<1>(curr)).at(i).second; //new tent dist of neighbor
                tentDistances.at(graph.at(get<1>(curr)).at(i).first) = get<0>(neighbor); 
                get<1>(neighbor) = graph.at(get<1>(curr)).at(i).first; //neighbor name
                get<2>(neighbor) = get<1>(curr); // city that set tent dist
                Q.push_back(neighbor);
            }
        }

        // for (int i = 0; i < tentDistances.size(); ++i) {
        //     cout << tentDistances.at(i) << ' ';
        // }
        // cout << endl;
        // for (int i = 0; i < settledCities.size(); ++i) {
        //     cout << settledCities.at(i) << ' ';
        // }
        // cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio (false);
    int numCities = 0;
    int numEdges = 0;
    cin >> numCities;
    cin >> numEdges;
    int currCity = 0;
    int desiredCity = 0;
    cin >> currCity;
    cin >> desiredCity;

    vector<vector<pair<int, int>>> graph;
    vector<pair<int, int>> connections;
    for (int i = 0; i < numCities; ++i) {
        graph.push_back(connections);
    }

    int c1 = 0;
    int c2 = 0;
    int weight = 0;
    pair<int, int> edge;
    edge.first = 0;
    edge.second = 0;
    int maxWeight = 0;
    for (int i = 0; i < numEdges; ++i) {
        cin >> c1;
        cin >> c2;
        cin >> weight;
        if (weight > maxWeight) {
            maxWeight = weight;
        }
        edge.first = c2;
        edge.second = weight;
        graph.at(c1).push_back(edge);
        edge.first = c1;
        edge.second = weight;
        graph.at(c2).push_back(edge);
    }

    // for (int i = 0; i < graph.size(); ++i) {
    //     for (int j = 0; j < graph.at(i).size(); ++j) {
    //         cout << graph.at(i).at(j).first << ' ';
    //     }
    //     cout << endl;
    // }

    vector<int> tentDistances;
    for (int i = 0; i < graph.size(); ++i) {
        tentDistances.push_back(numeric_limits<int>::max());
    }
    

    FindDist(graph, tentDistances, currCity, desiredCity, numeric_limits<int>::max());

    cout << tentDistances.at(desiredCity) << endl;

    return 0;
}