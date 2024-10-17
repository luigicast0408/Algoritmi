#include <iostream>
using namespace std;

int knapsackProblem(int vector[], int K, int N);
void sortVector(int vector[], int size);
void swap(int *a, int *b);

int main() {
    int vector[] = {3, 2, 3, 3, 4, 5, 6, 6};
    int size = 7;
    int K = 10;
    sortVector(vector, size);
    cout << "\nMax number of objects that can be inserted in the bag is: " << knapsackProblem(vector, K, size) << endl;

    return 0;
}


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortVector(int vector[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (vector[i] > vector[j]) {
                swap(&vector[i], &vector[j]);
            }
        }
    }
}

int knapsackProblem(int vector[], int K, int N) {
    if (N == 0 || K == 0) {
        return 0;
    }

    if (vector[N-1] > K) {
        return knapsackProblem(vector, K, N-1);
    }

    return max(vector[N] + knapsackProblem(vector, K - vector[N-1], N - 1),knapsackProblem(vector, K, N - 1));
}
