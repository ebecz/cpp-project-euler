#include <iostream>
#include <cstring>
using namespace std;
class Esquisita{
public:
    unsigned char N[10];
    Esquisita(void){
        for(unsigned int i=0;i<10;i++){
            N[i]=0;
        }
    }
    void Incrementar(void){
        unsigned char r=1;
        for(unsigned int i=0;i<10;i++){
            N[i]+=r;
            r=N[i]-N[i]%10;
            N[i]-=r;
            r/=10;
        }
    }
    void Adicionar(Esquisita&B){
        unsigned char r=0;
        for(unsigned int i=0;i<10;i++){
            N[i]+=B.N[i]+r;
            r=N[i]-N[i]%10;
            N[i]-=r;
            r/=10;
        }
    }
    inline void MultiplicarPor10(void){
        for(unsigned int i=9;i;i--){
            N[i]=N[i-1];
        }
        N[0]=0;
    }
    inline void Multiplicar(unsigned int k){
        unsigned int r=0;
        for(unsigned int i=0;i<10;i++){
            N[i]*=k;
            N[i]+=r;
            r=N[i]-(N[i]%10);
            N[i]-=r;
            r/=10;
        }
    }
    void Multiplicar(Esquisita&X){
        Esquisita S;
        for(unsigned int i=0;i<10;i++){
            S.MultiplicarPor10();
            Esquisita T=X;
            T.Multiplicar(N[9-i]);
            S.Adicionar(T);
        }
        (*this)=S;
    }
    void Elevar(unsigned int k){
        Esquisita T;
        T.N[0]=1;
        for(unsigned int i=0;i<k;i++){
            T.Multiplicar(*this);
        }
        (*this)=T;
    }
    unsigned long long int ToULLInt(){
        unsigned long long int s=0;
        for(unsigned int i=0;i<10;i++){
            s*=10;
            s+=N[9-i];
        }
        return s;
    }
};
unsigned long long int P048(){
    Esquisita S,N;
    for(unsigned int i=1;i<=1000;i++){
        N.Incrementar();
        {
            Esquisita T=N;
            T.Elevar(i);
            S.Adicionar(T);
        }
    }
    return S.ToULLInt();
}
int main(){
    cout<<P048()<<endl;
    return 0;
}

