#include <iostream>
int factorial(int n);
using namespace std;

int main(){
    int n=4;
    cout<<"\nFactorial: "<< factorial(n)<<endl;
}

int factorial(int n){
    if (n == 1 ){
        return 1;
    }
    return n * factorial(n-1);
}