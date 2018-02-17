#include <iostream>
#include <cstring>
using namespace std;
const unsigned int N=1000000;
const unsigned int Target=7;
bool P[N];
unsigned int P051(){
    memset(P,true,sizeof(P));
    P[0]=false;
    P[1]=false;
    for(unsigned int i=2;i<N;i++){
        if(P[i]){
            for(unsigned int j=2;j*i<N;j++){
                P[i*j]=0;
            }
        }
    }
    for(unsigned int i=0;i<N;i++){
        if(P[i]){
            unsigned int S=0,M=1;
            unsigned int D[30];
            for(unsigned int u=i;u;S++){
                D[S]=u%10;
                u/=10;
                M*=10;
            }
            M/=10;
            for(unsigned int q=1;q<(1<<S);q++){
                unsigned int N=0,U=0;
                for(unsigned int p=0,Dz=1;p<S;p++,Dz*=10){
                    if(q&(1<<p)){
                        U+=Dz;
                    }else{
                        N+=D[p]*Dz;
                    }
                }
                {
                    unsigned int s=0;
                    for(unsigned int k=0;(k-s<=10-Target) && k<10;k++){
                        if(P[N+U*k]){
                            if(N+U*k>=M){
                                s++;
                            }
                        }
                    }
                    if(s==Target){
                        for(unsigned int k=0;k<10;k++){
                            if(P[N+U*k]){
                                if(N+U*k>=M){
                                    return N+U*k;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    cout<<P051()<<endl;
    return 0;
}

