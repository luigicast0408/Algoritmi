#include <iostream>
using namespace std;
int mul(int x, int y);

int main(){
    int x=3, y=4;
    cout<<"\n MUL: "<<mul(x,y)<<endl;

}

int mul(int x, int y){
    if (y == 1){
        return x;
    }
    return x + mul(x,y-1);
}