#include <iostream>
using namespace std;
#define TAM 400
unsigned int P016(unsigned int N){
    char Num[TAM]={0,};
    unsigned int r=0,i;
    Num[0]=1;
    do{
        for(i=0;i<TAM;i++){
            Num[i]+=Num[i]+r;
            r=Num[i]/10;
            Num[i]%=10;
        }
        if(r){
            cout<<"Aumenta a TAM"<<endl;
            return 0;
        }
    }while(--N);
    for(i=0,r=0;i<TAM;i++){
        r+=Num[i];
    }
    return r;
}
int main() {
    cout << P016(1000) << endl;
    return 0;
}
