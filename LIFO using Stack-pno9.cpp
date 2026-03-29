#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push(x);
    }

    cout << "LIFO Node Selection Order:\n";

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}