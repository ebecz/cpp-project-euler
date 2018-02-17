#include <iostream>
using namespace std;
unsigned int P007(unsigned int N_){
    const unsigned int MEGA=1024*1024;
    const unsigned int KILO=1024;
    bool M[MEGA];
    unsigned int N[10*KILO];
    unsigned int i,j=2,k=0;
    bool LOOP=true;
    for(i=0;i<MEGA;i++){
        M[i]=true;
    }
    while(LOOP){
        while(!M[j]){
            j++;
            if(j>MEGA){
                cout<<"Problema com o MEGA"<<endl;
                return 0;
            }
        }
        N[k++]=j;
        if(k>10*KILO){
            LOOP=false;
        }
        for(i=2*j;i<MEGA;i+=j){
            M[i]=false;
        }
        j++;
    }
    return N[N_-1];
}
int main(){
    cout<<P007(1001)<<endl;
    return 0;
}
