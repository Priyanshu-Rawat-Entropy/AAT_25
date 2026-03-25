#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    bool found = false;


    for (int i = 0; i <= n - m; i++) {

      int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }


        if (j == m) {
            cout << "Pattern found at position " << i << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Pattern not found." << endl;

    return 0;
}