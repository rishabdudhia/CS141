#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void MakeMST(vector<vector<pair<int, int>>>& graph, vector<int>& tentDistances, int maxWeight, int start) {
    vector<int> settledCities(tentDistances.size(), 0);
    settledCities.at(start) = 1;
    int min = 0;
    vector<pair<int, int>> Q;
    pair<int, int> curr;
    curr.first = start;
    curr.second = 0;
    tentDistances.at(start) = 0;
    Q.push_back(curr);
    pair<int, int> temp;

    while (!Q.empty()) {
        min = 0;
        for (int i = 0; i < Q.size(); ++i) {
            if (Q.at(i).second < Q.at(min).second) {
                min = i;
            }
        }
        curr = Q.at(min);
        settledCities.at(curr.first) = 1;
        Q.erase(Q.begin()+min);

        for (int j = 0; j < graph.at(curr.first).size(); ++j) {
            if (settledCities.at(graph.at(curr.first).at(j).first)) {
                continue;
            }
            if (tentDistances.at(graph.at(curr.first).at(j).first) == maxWeight) {
                tentDistances.at(graph.at(curr.first).at(j).first) = graph.at(curr.first).at(j).second;
                temp.first = graph.at(curr.first).at(j).first;
                temp.second = graph.at(curr.first).at(j).second;
                Q.push_back(temp);
            }
            else {
                if (graph.at(curr.first).at(j).second < tentDistances.at(graph.at(curr.first).at(j).first)) {
                    tentDistances.at(graph.at(curr.first).at(j).first) = graph.at(curr.first).at(j).second;
                    for (int i = 0; i < Q.size(); ++i) {
                        if (Q.at(i).first == graph.at(curr.first).at(j).first) {
                            Q.at(i).second = graph.at(curr.first).at(j).second;
                        }
                    }
                }
            }
        }

        // for (int i = 0; i < tentDistances.size(); ++i) {
        //     cout << tentDistances.at(i) << ' ';
        // }
        // cout << endl;
    }
    
}

int main() {
    
    ios_base::sync_with_stdio (false);
    int numCities = 0;
    int numEdges = 0;
    cin >> numCities;
    cin >> numEdges;

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

    vector<int> tentDistances;
    for (int i = 0; i < graph.size(); ++i) {
        tentDistances.push_back(numeric_limits<int>::max());
    }

    MakeMST(graph, tentDistances, numeric_limits<int>::max(), 0);

    int sum = 0;
    for (int i = 0; i < tentDistances.size(); ++i) {
        sum += tentDistances.at(i);
    }
    cout << sum << endl;

    return 0;
}