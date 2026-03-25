#include <iostream>
using namespace std;

int n, target;
int arr[10];

void subsetSum(int index, int sum) {


    if (sum == target) {
        cout << "Subset found." << endl;
        return;
    }


    if (index == n || sum > target)
        return;


    subsetSum(index + 1, sum + arr[index]);


    subsetSum(index + 1, sum);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    subsetSum(0, 0);

    return 0;
}