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
    cout << "\nMax number of object that can be insert in the bag is: " << knapsackProblem(vector, K, size) << endl;
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

    if (vector[N] > K) {
        return knapsackProblem(vector, K, N-1);
    }
    return (vector[N] + knapsackProblem(vector,K-vector[N],N-1));
}

/*
 * steps for resolve this problem (iterative solution):
 * 1. sort vector  max to min
 * 2. define the basic case: 1. N == 0 and when vector[N] > K (max weight)
 * 3. when the object terminated or the weight max is reached finish the function
 */
