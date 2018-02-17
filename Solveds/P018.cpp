#include <iostream>
using namespace std;
#define TAM 15
short int NumL[15]={0,};
void Computar(unsigned int N){
    char CH[TAM*3];
    gets(CH);
    if(N){
        unsigned int i=0,j=0,n=0;
        Computar(N-1);
        do{
            if(CH[i]==' ' || CH[i]==0){
                NumL[j]=n+max( NumL[j],NumL[j+1]);
                j++;
                n=0;
            }else{
                n*=10;
                n+=CH[i]-'0';
            }
        }while(CH[i++]);
    }else{
        unsigned int i=0,j=0;
        do{
            if(CH[i]==' '){
                j++;
            }else{
                NumL[j]*=10;
                NumL[j]+=CH[i]-'0';
            }
        }while(CH[++i]);
    }
}
unsigned int P018(unsigned int N){
    Computar(N-1);
    return NumL[0];
}
int main() {
    cout<<P018(15)<<endl;
    return 0;
}
