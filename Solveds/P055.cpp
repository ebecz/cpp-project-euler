#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const unsigned long long int N=10000;
const unsigned long long int MAX=100000*N;
unsigned char M[MAX];
const char YES=2;
const char MAY=1;
const char NOT=0;
unsigned long long int reverse(unsigned long long int x){
    unsigned long long int T=0;
    while(x){
        T*=10;
        T+=x%10;
        x/=10;
    }
    return T;
}
char ISN_Lychrel2(unsigned long long int n,unsigned long long int rn,unsigned char deep){
    unsigned long long int T=n+rn,R=reverse(T);
    if(T==R){
        return YES;
    }else if(deep==49){
        return NOT;
    }else{
        return ISN_Lychrel2(T,R,deep+1);
    }
}
char ISN_Lychrel(unsigned long long int n,unsigned long long int rn,unsigned char deep){
    if(M[n]==MAY){
        unsigned long long int R1=rn,T=n+R1,R2=reverse(T);
        if(T==R2){
            M[n]=YES;
            M[R1]=YES;
        }else{
            if(T>MAX){
                return ISN_Lychrel2(T,R2,deep+1);
            }else if(deep==49){
                return NOT;
            }else{
                M[n]=ISN_Lychrel(T,R2,deep+1);
            }
        }
    }
    return M[n];
}
unsigned long long int P055(){
    unsigned long long int c=0;
    memset(M,MAY,sizeof(M));
    for(unsigned long long int i=2;i<N;i++){
        if(!ISN_Lychrel(i,reverse(i),1)){
            c++;
        }
    }
    return c;
}
int main(){
    cout<<P055()<<endl;
    return 0;
}
