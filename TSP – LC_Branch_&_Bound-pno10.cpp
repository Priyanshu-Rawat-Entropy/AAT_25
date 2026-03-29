#include <bits/stdc++.h>
using namespace std;

#define INF 9999

int n = 4;

int tsp(int graph[][4]) {
    vector<int> perm = {1, 2, 3};
    int min_cost = INF;

    do {
        int cost = graph[0][perm[0]] +
                   graph[perm[0]][perm[1]] +
                   graph[perm[1]][perm[2]] +
                   graph[perm[2]][0];

        min_cost = min(min_cost, cost);

    } while (next_permutation(perm.begin(), perm.end()));

    return min_cost;
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum travelling cost: "
         << tsp(graph);

    return 0;
}