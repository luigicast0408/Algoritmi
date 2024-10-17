#include <iostream>
int fibonacciSequence(int n);
using namespace std;
int main(){
    int n = 7;
    cout<<"\nFibonacci sequence: "<<fibonacciSequence(n)<<endl;
}

int fibonacciSequence(int n){
    if (n <= 2){
        return n;
    }
    return fibonacciSequence(n-1) + fibonacciSequence(n-2);
}
