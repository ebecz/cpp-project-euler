#include <iostream>
#include <cstring>
using namespace std;
unsigned int P045(){
    unsigned int t=286,p=166,h=144;
    unsigned int T,P,H;
    T=t*(t+1)/2;
    P=p*(3*p-1)/2;
    H=h*(2*h-1);
    do{
        if(T<P || T<H){
            t++;
            T=t*(t+1)/2;
        }
        if(P<T || P<H){
            p++;
            P=p*(3*p-1)/2;
        }
        if(H<P || H<T){
            h++;
            H=h*(2*h-1);
        }
    }while((T!=P) || (P!=H));
    cout<<"t="<<t<<"\tp="<<p<<"\th="<<h<<endl;
    return T;
}
int main(){
    cout<<P045()<<endl;
    return 0;
}
