#include <iostream>
using namespace std;

int sumk(int a[], int s, int k) {
    int sum = 0;

    for (int i = s; i < s + k; i++) {
        sum += a[i];
    }

    return sum;
}

int main() {
    int n, k;

    cin >> n;
    cin >> k;

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max = -1;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            if (abs(i - j) < k) continue;

            int sum = sumk(a, i, k) + sumk(a, j, k);
            if (sum > max) {
                max = sum;
            }
        }
    }

    cout << max << endl;
}
