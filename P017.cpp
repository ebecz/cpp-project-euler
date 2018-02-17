#include <iostream>
using namespace std;
const char Uni[20]={-1+sizeof("zero"),-1+sizeof("one"),-1+sizeof("two"),-1+sizeof("three"),-1+sizeof("four"),-1+sizeof("five"),
                    -1+sizeof("six"),-1+sizeof("seven"),-1+sizeof("eight"),-1+sizeof("nine"),
                    -1+sizeof("ten"),-1+sizeof("eleven"),-1+sizeof("twelve"),-1+sizeof("thirteen"),-1+sizeof("fourteen"),
                    -1+sizeof("fifteen"),-1+sizeof("sixteen"),-1+sizeof("seventeen"),
                    -1+sizeof("eighteen"),-1+sizeof("nineteen")};
const char Dez[10]={-1+sizeof(""),-1+sizeof(""),-1+sizeof("twenty"),-1+sizeof("thirty"),-1+sizeof("forty"),-1+sizeof("fifty"),
                    -1+sizeof("sixty"),-1+sizeof("seventy"),-1+sizeof("eighty"),-1+sizeof("ninety")};
unsigned int P017(unsigned int Nm){
    int N;
    int S=0;
    do{
        N=Nm;
        if(N){
            int U=N%10;
            int D=(N/=10)%10;
            int C=(N/=10)%10;
            int M=(N/=10)%10;
            if(M){
                S+=Uni[M]+-1+sizeof("thousand");
                if(C+D+U){
                    S+=-1+sizeof("and");
                }
            }
            if(C){
                S+=Uni[C]+-1+sizeof("hundred");
                if(D+U){
                    S+=-1+sizeof("and");
                }
            }
            if(D>1){
                S+=Dez[D];
                if(U){
                    S+=Uni[U];
                }
            }else{
                if(D*10+U){
                    S+=Uni[D*10+U];
                }
            }
        }else{
            S+=Uni[0];
        }
    }while(--Nm);
    return S;
}
int main() {
    cout<<P017(1000)<<endl;
    return 0;
}
