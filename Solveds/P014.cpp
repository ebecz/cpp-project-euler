#include <iostream>
using namespace std;
unsigned int GetNum(unsigned int n){
    return n==1?1:GetNum((n%2)?(3*n+1):(n/2))+1;
}
unsigned int P014(void){
    unsigned int i,Nm=0,r,N;
    for(i=1;i<1000000;i++){
        N=GetNum(i);
        if(Nm<N){
            Nm=N;
            r=i;
        }
    }
    return r;
}
int main(){
    cout<<P014()<<endl;
    return 0;
}

/* - Right way
const unsigned int Num=100*1024*1024;
static unsigned int N[Num];
unsigned int x;
unsigned int GetNum(unsigned int n){
    if(n>Num){
        cout<<"Erro de tamanho:"<<n<<endl;
        exit(0);
    }
    if(!N[n]){
        N[n]=GetNum((n%2)?(3*n+1):(n/2))+1;
    }
    x=max(x,n);
    return N[n];
}
unsigned int P014(void){
    memset(N,0,sizeof(N));
    unsigned int i,Nm=0,r;
    N[1]=1;
    for(i=1;i<100000;i++){
        if(Nm<GetNum(i)){
            Nm=GetNum(i);
            r=i;
        }
    }
    cout<<endl;
    return r;
}
*/
