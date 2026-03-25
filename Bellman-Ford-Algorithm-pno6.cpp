#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];

    for (int i = 0; i < E; i++) {
        cout << "Enter source, destination and weight of edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int INF = 1e9;

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;


    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }


    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "\nGraph contains a negative weight cycle." << endl;
            return 0;
        }
    }

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INF)
            cout << "Unreachable";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}