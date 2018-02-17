#include <iostream>
using namespace std;
unsigned int P021(unsigned int n){
    unsigned short int d[n];
    unsigned long long int S=0;
    for(unsigned short int i=0;i<n;i++){
        d[i]=0;
        for(unsigned short int j=1;j<i;j++){
            if(!(i%j)){
                d[i]+=j;
            }
        }
    }
    for(unsigned short int i=0;i<n;i++){
        if(d[i]<n){
            if(i==d[d[i]]){
                if(i!=d[i]){
                    S+=d[i];
                }
            }
        }
    }
    return S;
}
int main() {
    cout<<P021(10000)<<endl;
    return 0;
}
