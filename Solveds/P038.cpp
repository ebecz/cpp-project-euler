#include <iostream>
#include <cstring>
using namespace std;
unsigned int Ns=0;
inline bool Testar(unsigned const long long int N){
    unsigned char P=0;
    unsigned int Nm=N,Ninv=0;
    do{
        P++;
        Ninv*=10;
        Ninv+=Nm%10;
        Nm/=10;
    }while(Nm);
    Nm=N;
    for(unsigned int i=0,d=0;i<P/2;i++){
        d*=10;
        d+=Nm%10;
        Nm/=10;
        unsigned long long int S=0;
        unsigned int j=1,t;
        do{
            t=j*d;
            do{
                S*=10;
                t/=10;
            }while(t);
            S+=j*d;
            j++;
            if(S==Ninv){
                Ns=max(Ns,Ninv);
            }
        }while(Ninv>=S);
    }
    return false;
}
void Construir(unsigned int Mk,unsigned int A){
    if(Mk){
        A*=10;
        for(unsigned int i=1,mt=2;i<=9;i++,mt<<=1){
            if(Mk&mt){
                A+=i;
                Construir(Mk^mt,A);
                A-=i;
            }
        }
    }else{
        Testar(A);
    }
}
unsigned int P038(){
    Construir(0x3FE,0);
    return Ns;
}
int main(){
    cout<<P038()<<endl;
    return 0;
}
