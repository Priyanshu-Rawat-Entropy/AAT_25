#include <iostream>
using namespace std;

struct Job {
    int start, finish, profit;
};


void sortByFinish(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].finish > jobs[j + 1].finish) {
                Job temp   = jobs[j];
                jobs[j]    = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter start, finish and profit of job " << i + 1 << ": ";
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
    }

    sortByFinish(jobs, n);

int dp[n];
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {

        int incl = jobs[i].profit;


        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].finish <= jobs[i].start) {
                incl += dp[j];
                break;
            }
        }


        int excl = dp[i - 1];

        dp[i] = max(incl, excl);
    }

    cout << "\nMaximum profit: " << dp[n - 1] << endl;

    return 0;
}