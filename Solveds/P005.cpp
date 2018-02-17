#include <iostream>
using namespace std;
unsigned int P005(unsigned int N=20){
    unsigned int MB[]={2,3,5,7,11,13,17,19,0};
    unsigned int MES[sizeof(MB)]={0,};
    unsigned int MEV[sizeof(MB)]={0,};
    unsigned int T;
    unsigned int i;
    do{
        for(i=0,T=N;MB[i];i++){
            MEV[i]=0;
            while(!(T%MB[i])){
                T/=MB[i];
                MEV[i]++;
            }
        }
        for(i=0;MB[i];i++){
            MES[i]=max(MES[i],MEV[i]);
        }
    }while(--N);
    for(i=0,T=1;MB[i];i++){
        while(MES[i]--){
            T*=MB[i];
        }
    }
    return T;
}
int main(){
    cout<<P005(20)<<endl;
    return 0;
}
