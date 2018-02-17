#include <iostream>
#include <cmath>
using namespace std;
#define MAX 8
unsigned int fatorial[10];
unsigned int S=0;
void fc(unsigned int p,unsigned int F,unsigned int N){
    if(N==F){
        S+=N;
    }
    if(p<MAX){
        for(unsigned char i=0;i<=9;i++){
            fc(p+1,F+fatorial[i],N*10+i);
        }
    }
}
unsigned int P034(){
    fatorial[0]=1;
    for(unsigned int i=1;i<=9;i++){
        fatorial[i]=i*fatorial[i-1];
    }
    for(unsigned int i=1;i<=9;i++){
        fc(1,fatorial[i],i);
    }
    return S-3;
}
int main(){
    cout<<P034()<<endl;
    return 0;
}
