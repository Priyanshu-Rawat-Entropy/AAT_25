#include <iostream>
using namespace std;


int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, amount;

    cout << "Enter number of coin types: ";
    cin >> n;

    int coins[n];

    cout << "Enter coin denominations:\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int INF = amount + 1;

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INF;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {


            if (coins[j] <= i && dp[i - coins[j]] != INF) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INF)
        cout << "\nNo solution: amount cannot be formed with given coins." << endl;
    else
        cout << "\nMinimum coins required: " << dp[amount] << endl;

    return 0;
}
