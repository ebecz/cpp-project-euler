#include <iostream>
using namespace std;
unsigned int PoW(unsigned int n,unsigned int m){return m?PoW(n,m-1)*n:1;}
unsigned int P030(unsigned int n){
    unsigned int SN=0,SP=0,R=0;
    for(unsigned int f=0;f<=9;f++){
    SN+=100000*f;
    SP+=PoW(f,n);
        for(unsigned int e=0;e<=9;e++){
            SN+=10000*e;
            SP+=PoW(e,n);
            for(unsigned int a=0;a<=9;a++){
                SN+=1000*a;
                SP+=PoW(a,n);
                for(unsigned int b=0;b<=9;b++){
                    SN+=100*b;
                    SP+=PoW(b,n);
                    for(unsigned int c=0;c<=9;c++){
                        SN+=10*c;
                        SP+=PoW(c,n);
                        for(unsigned int d=0;d<=9;d++){
                            SN+=d;
                            SP+=PoW(d,n);
                            if(SN==SP){
                                R+=SN;
                            }
                            SN-=d;
                            SP-=PoW(d,n);
                        }
                        SN-=10*c;
                        SP-=PoW(c,n);
                    }
                    SN-=100*b;
                    SP-=PoW(b,n);
                }
                SN-=1000*a;
                SP-=PoW(a,n);
            }
            SN-=10000*e;
            SP-=PoW(e,n);
        }
    SN-=100000*f;
    SP-=PoW(f,n);
    }
    return R-1;
}
int main(){
    cout<<P030(5)<<endl;
    return 0;
}
