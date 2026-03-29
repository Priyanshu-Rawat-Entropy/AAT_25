#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    cout << "FIFO Node Selection Order:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}