#include <iostream>
int fibonacciSequence(int n);
using namespace std;
int main(){
    int n = 7;
    cout<<"\nFibonacci sequence: "<<fibonacciSequence(n)<<endl;
}

int fibonacciSequence(int n){
    int vector[n];
    for (int i = 0; i < n; ++i) {
        vector[i]=-1;
    }

    if (n <= 2){
        return n;
    }
    if (vector[n-1] == -1){
        vector[n-1]= fibonacciSequence(n-1);
    }
    return fibonacciSequence(n-1) + fibonacciSequence(n-2);
}
