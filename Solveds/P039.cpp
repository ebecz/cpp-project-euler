#include <iostream>
#include <cstring>
using namespace std;
#define NMax 1001
unsigned int V[NMax*NMax];
unsigned int S[NMax];
unsigned int P039(){
    memset(&V,NMax*NMax,0);
    memset(&S,NMax,0);
    for(unsigned int i=0;i<NMax;i++){
        V[i*i]=i;
    }
    for(unsigned int i=1;i<NMax;i++){
        for(unsigned int j=i;j<NMax;j++){
            unsigned int c=i*i+j*j;
            if(c<NMax*NMax){
                unsigned int s=i+j+V[c];
                if(s>=NMax){
                    break;
                }else if(V[c]){
                    S[s]++;
                }
            }else{
                break;
            }
        }
    }
    unsigned int M=0,N=0;
    for(unsigned int i=0;i<NMax;i++){
        if(M<S[i]){
            M=S[i];
            N=i;
        }
    }
    return N;
}
int main(){
    cout<<P039()<<endl;
    return 0;
}
