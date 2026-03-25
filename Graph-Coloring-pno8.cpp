#include <iostream>
using namespace std;

int graph[10][10], color[10], n, m;


bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}


bool graphColoring(int v) {


    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {

        if (isSafe(v, c)) {

            color[v] = c;

            if (graphColoring(v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors: ";
    cin >> m;

    if (graphColoring(0)) {
        cout << "\nColoring solution:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    } else {
        cout << "\nNo solution exists with " << m << " colors." << endl;
    }

    return 0;
}