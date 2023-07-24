#include <climits>
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of inputs: ";

    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << "Sum: " << sum << " Avg: " << (float) sum / n << endl;

    int odds = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            odds += 1;
        }
    }
    cout << "Odds: " << odds << endl;

    // int min = INT_MAX, max = INT_MIN;
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {   // Start from 1
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    cout << "Min: " << min << " Max: " << max << endl;

    return 0;
}
