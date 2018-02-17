#include <iostream>
using namespace std;
int P001(int n) {
    int a,b,c;
    a=n/5;
    b=n/3;
    c=n/15;
    a=5*a*(a+1)/2;
    b=3*b*(b+1)/2;
    c=15*c*(c+1)/2;
    return b+a-c;
}
int main(){
    cout<<P001(1000)<<endl;
    return 0;
}
