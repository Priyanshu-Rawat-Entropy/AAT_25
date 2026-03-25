#include <iostream>
using namespace std;

int graph[10][10], path[10], n;


bool isSafe(int v, int pos) {

    if (!graph[path[pos - 1]][v]) return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;

    return true;
}


bool hamiltonian(int pos) {

    if (pos == n) {

        return graph[path[pos - 1]][path[0]];
    }


    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonian(pos + 1))
                return true;


            path[pos] = -1;
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


    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamiltonian(1)) {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0];
    } else {
        cout << "No Hamiltonian Cycle exists";
    }

    return 0;
}