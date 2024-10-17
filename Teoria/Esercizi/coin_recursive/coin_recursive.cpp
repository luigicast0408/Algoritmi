#include <iostream>
#include <climits>

using namespace std;

int min_coin(int T[], int R, int M);

int main() {
    int T[] = {1, 2, 3};
    int R = 6;
    int M = sizeof(T) / sizeof(T[0]);
    int result = min_coin(T, R, M);
    if (result == INT16_MAX) {
        cout << "Non è possibile dare il resto esattamente." << endl;
    } else {
        cout << "\nMin coin: " << result << endl;
    }

    return 0;
}

int min_coin(int T[], int R, int M) {
    if (M == 0 || R < 0)
        return INT16_MAX;

    if (R == 0)
        return 0;

    if (T[M - 1] > R) {
        return min_coin(T, R, M - 1);
    }
    return min(T[M] + min_coin(T, R - T[M - 1], M), min_coin(T, R, M - 1));
}

