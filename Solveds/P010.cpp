#include <iostream>
using namespace std;
unsigned long long int P010(unsigned long long int N){
    bool M[N];
    unsigned long long int S=0;
    unsigned long long int i,j=2;
    for(i=0;i<N;i++){
        M[i]=true;
    }
    while(true){
        for(i=2*j;i<N;i+=j){
            M[i]=false;
        }
        S+=j;
        do{
            j++;
            if(j>=N){
                return S;
            }
        }while(!M[j]);
    }
    return 0;
}
int main(){
    cout<<P010(2000000)<<endl;
    return 0;
}
