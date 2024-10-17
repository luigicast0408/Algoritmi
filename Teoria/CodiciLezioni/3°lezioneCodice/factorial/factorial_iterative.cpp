#include <iostream>
int factorial(int n);
using namespace std;

int main() {
    int n = 4;
    cout << "\nFactorial: " << factorial(n) << endl;
}

int factorial(int n) {
    int p = 1;
    for (int i = 2; i <= n; i++) {
        p *= i;
    }
    return p;
}
