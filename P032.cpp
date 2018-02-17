#include <iostream>
using namespace std;
bool marcar(unsigned int&d,unsigned int x,unsigned int&k){
    unsigned int t;
    bool R=false;
    do{
        t=1<<(x%10);
        if(t&d){
            R=true;
        }
        d|=t;
        x/=10;
        k++;
    }while(x);
    return R;
}
inline unsigned int eval(unsigned int x){
    static unsigned int M[200];
    static unsigned int index=0;
    for(unsigned int i=0;i<index;i++){
        if(x==M[i]){
            return 0;
        }
    }
    M[index]=x;
    index++;
    return x;
}
unsigned int P032(){
    unsigned int S=0;
    for(unsigned int a=1;a<100000;a++){
        unsigned int d=0,k=0;
        if(marcar(d,a,k)){continue;}
        for(unsigned int b=a,c,l=0,e;l<=9;b++){
            if(a==39 && b==186){
                unsigned int s=0;
            }
            l=k;
            e=d;
            if(marcar(e,b,l)){continue;}
            c=a*b;
            if(marcar(e,c,l)){continue;}
            if(e==0x3FE){
                S+=eval(c);
            }
        }
    }
    return S;
}
int main(){
    cout<<P032()<<endl;
    return 0;
}
