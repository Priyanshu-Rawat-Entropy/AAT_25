#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity act[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter start and finish time of activity " << i+1 << ": ";
        cin >> act[i].start >> act[i].finish;
    }

    sort(act, act + n, compare);

    cout << "Selected activities:\n";

    int lastFinish = act[0].finish;
    cout << "(" << act[0].start << "," << act[0].finish << ")\n";

    for(int i = 1; i < n; i++) {
        if(act[i].start >= lastFinish) {
            cout << "(" << act[i].start << "," << act[i].finish << ")\n";
            lastFinish = act[i].finish;
        }
    }

    return 0;
}
