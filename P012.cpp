#include <iostream>
using namespace std;
unsigned int P012(unsigned int D){
    const unsigned int Naturais=1024*1024;
    const unsigned int Primos=1480;
    bool M[Naturais];
    unsigned int E,d;
    unsigned int N[Primos];
    unsigned int i,j=2,k=0,W,P;
    bool LOOP=true;
    for(i=0;i<Naturais;i++){
        M[i]=true;
    }
    while(LOOP){
        while(!M[j]){
            j++;
            if(j>Naturais){
                cout<<"Naturais insuficientes para preencher "<<Primos<<" Primos"<<endl;
                return 0;
            }
        }
        N[k++]=j;
        if(k>Primos){
            break;
        }
        for(i=2*j;i<Naturais;i+=j){
            M[i]=false;
        }
        j++;
    }
    i=0;
    W=0;
    do{
        W=(P+=(++i));
        d=1;
        for(j=0,k=0;W>=N[j];j++){
            E=1;
            if(j>Primos){
                cout<<"Primos insuficientes"<<endl;
                return 0;
            }
            while(!(W%N[j])){
                E++;
                W/=N[j];
            }
            d*=E;
        }
    }while(d<=D);
    return P;
}
int main(){
    cout<<P012(500)<<endl;
    return 0;
}
