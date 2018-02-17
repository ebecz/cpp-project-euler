#include <iostream>
using namespace std;
int P002(int x){
    int a,b=0,c=2,S=0;
    while (a<x) {
        a=b*4+c;
        c=b;
        S+=b;
        b=a;
    }
    return S;
}
int main(){
    cout<<P002(4000000)<<endl;
    return 0;
}
