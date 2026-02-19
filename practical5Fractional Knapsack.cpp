#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};

bool compare(Item a, Item b) {
    return (double)a.profit / a.weight >
           (double)b.profit / b.weight;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << i+1 << ": ";
        cin >> items[i].profit >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalProfit = 0.0;

    for(int i = 0; i < n && capacity > 0; i++) {
        if(items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else {
            totalProfit += items[i].profit *
                           ((double)capacity / items[i].weight);
            break;
        }
    }

    cout << "Maximum profit: " << totalProfit;

    return 0;
}
