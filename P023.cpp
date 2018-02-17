#include <iostream>
#include <cstring>
using namespace std;
unsigned int P023(unsigned int n){
    bool N[n];
    bool M[n];
    for(unsigned int i=0;i<n;i++){
        unsigned int S=0;
        for(unsigned int j=1;j<=(i/2);j++){
            if(!(i%j)){
                S+=j;
            }
        }
        N[i]=(S>i);
    }
    memset(M,0xff,sizeof(M));
    for(unsigned int i=0;i<n;i++){
        if(N[i]){
            for(unsigned int j=i;j+i<n;j++){
                if(N[j]){
                    M[i+j]=false;
                }
            }
        }
    }
    unsigned int S=0;
    for(unsigned int i=0;i<n;i++){
        if(M[i]){
            S+=i;
        }
    }
    return S;
}
int main() {
    cout<<P023(28123)<<endl;
    return 0;
}
