#include <iostream>
using namespace std;
bool IsPrime(signed int n){
    unsigned int i=2;
    if(n<=1){
        return false;
    }
    while(n!=i){
        if(!(n%i)){
            return false;
        }
        i++;
    }
    return true;
}
signed int P027(){
    signed int i,j,n,a,b,N;
    for(i=-1000;i<1000;i++){
        for(j=-1000;j<1000;j++){
            n=0;
            while(IsPrime(n*n+i*n+j)){n++;};
            if(n>N){
                a=i;
                b=j;
                N=n;
            }
        }
    }
    return a*b;
}
int main(){
    cout<<P027()<<endl;
    return 0;
}
