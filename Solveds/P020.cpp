#include <iostream>
using namespace std;
#define TAM 400
unsigned short int M[TAM]={0,};
unsigned short int P020(unsigned int N) {
    unsigned short int i,r;
    M[0]=1;
    do{
        for(i=0,r=0;i<TAM;i++){
            M[i]*=N;
            M[i]+=r;
            r=M[i]/10;
            M[i]%=10;
        }
        if(r){
            throw("AUMENTE O TAMANHO");
        }
    }while(--N);
    for(i=0,r=0;i<TAM;i++){
        r+=M[i];
    }
    return r;
}
int main() {
    cout<<P020(100)<<endl;
    return 0;
}
