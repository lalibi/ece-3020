#include <iostream>
using namespace std;

int mdsum(int arr[][150], int size) {
    int k, sum = 0;

    for (k = 0; k < size; k++) {
        sum += arr[k][k];
    }

    return sum;
}

int sdsum(int arr[][150], int size) {
    int k, sum = 0;

    for (k = 0; k < size; k++) {
        sum += arr[k][size - k - 1];
    }

    return sum;
}

int csum(int arr[][150], int size, int col) {
    int i, sum = 0;

    for (i = 0; i < size; i++) {
        sum += arr[i][col];
    }

    return sum;
}

int rsum(int arr[][150], int size, int row) {
    int j, sum = 0;

    for (j = 0; j < size; j++) {
        sum += arr[row][j];
    }

    return sum;
}

bool isMagic(int arr[][150], int size) {
    int i, j, sum = 0;

    sum = mdsum(arr, size);

    for (i = 0; i < size; i++) {
        if (sum != rsum(arr, size, i)) {
            return false;
        }
    }

    for (j = 0; j < size; j++) {
        if (sum != csum(arr, size, j)) {
            return false;
        }
    }

    if (sum != sdsum(arr, size)) {
        return false;
    }

    return true;
}

bool contains(int arr[][150], int size, int value) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (arr[i][j] == value) {
                return true;
            }
        }
    }
    return false;
}

bool containsAllNumbers(int arr[][150], int size) {
    int k;

    for (k = 0; k < size * size; k++) {
        if (!contains(arr, size, k)) {
            return false;
        }
    }

    return true;
}

int main() {
    int i, j, sum, N, A[150][150];
    bool res;

    cin >> N;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    if (!containsAllNumbers(A, N)) {
        cout << "no";
    } else if (!isMagic(A, N)) {
        cout << "no";
    } else {
        cout << "yes";
    }

    return 0;
}
