#include <iostream>
#include <cstring>
#define NMax 7
using namespace std;
unsigned int G[7]={1,10,100,1000,10000,100000,1000000};
unsigned int CCharInt(unsigned int N){
    unsigned int n=0;
    while(N){
        n++;
        N/=10;
    }
    return n;
}
unsigned int P040(){
    unsigned int i=1,s=0,b=0,m=1;
    do{
        s+=CCharInt(i);
        if(G[b]<=s){
            unsigned int it=i;
            for(unsigned int k=(s-G[b]);k;k--){
                it/=10;
            }
            it%=10;
            m*=it;
            b++;
            if(b>=NMax){
                return m;
            }
        }
        i++;
    }while(true);
}
int main(){
    cout<<P040()<<endl;
    return 0;
}
