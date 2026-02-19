#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter job id, deadline and profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    vector<char> slot(maxDeadline);
    vector<bool> filled(maxDeadline, false);

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(!filled[j]) {
                filled[j] = true;
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job sequence:\n";
    for(int i = 0; i < maxDeadline; i++)
        if(filled[i])
            cout << slot[i] << " ";

    cout << "\nTotal profit: " << totalProfit;

    return 0;
}
