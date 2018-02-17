#include <iostream>
#include <cstring>
using namespace std;
unsigned int P050(){
    const unsigned int N=1000000;
    const unsigned int Np=N/10;
    char Pr[N];
    unsigned int P[Np];
    unsigned int CP=0;
    memset(Pr,true,sizeof(Pr));
    Pr[0]=0;
    Pr[1]=0;
    {
        unsigned int i=2;
        while(i<N){
            if(Pr[i]){
                for(unsigned int j=2;j*i<N;j++){
                    Pr[j*i]=0;
                }
            }
            i++;
        }
    }
    P[0]=0;
    CP=1;
    for(unsigned int j=0,Pa=0;j+Pa<N;j++){
        if(Pr[j]){
            if(CP>Np){
                cout<<"Aumente o valor de Np"<<endl;
                return 0;
            }
            P[CP]=j+Pa;
            Pa=P[CP];
            CP++;
        }
    }
    unsigned int Q=0,S=0;
    for(unsigned int i=0;i<CP;i++){
        for(unsigned int j=i;j<CP;j++){
            if(Pr[P[j]-P[i]]){
                if(j-i>Q){
                    Q=j-i;
                    S=P[j]-P[i];
                }
            }
        }
    }
    return S;
}
int main(){
    cout<<P050()<<endl;
    return 0;
}

