#include <iostream>
#include <cstring>
using namespace std;
const unsigned int Max=64;
const unsigned int Nds=3;
unsigned int P[Max];
unsigned char N[Nds][Max];
unsigned int P046(){
    {
        bool Prime[Max*100];
        unsigned int c=0;
        for(unsigned int i=0;i<Max;i++){
            Prime[i]=true;
        }
        unsigned int i=2;
        do{
            if(Prime[i]){
                P[c]=i;
                c++;
                for(unsigned int j=2;(j*i)<100*Max;j++){
                    Prime[j*i]=false;
                }
            }
            i++;
        }while(c<Max);
    }{
        unsigned int i=0;
        unsigned int c=0;
        do{
            c=Nds;
            i++;
            unsigned char T[Max];
            for(unsigned int j=0;j<Max;j++){
                T[j]=0;
                unsigned int t=i;
                while(!(t%j)){
                      T[j]++;
                      t/=j;
                }
            }
            for(unsigned int i=0;i<Nds-1;i++){
                unsigned int c_=0;
                for(unsigned int j=0;j<Max;j++){
                    if(N[i][j]>=T[j]){
                        N[i][j]-=T[j];
                    }
                    if(N[i][j]){
                        c_++;
                    }
                }
                c=min(c,c_);
            }
            {
                unsigned int c_=0;
                for(unsigned int j=0;j<Max;j++){
                    N[Max-1][j]=T[j];
                    if(N[Max-1][j]){
                        c_++;
                    }
                }
                c=min(c,c_);
            }
        }while(c<Nds);
        return i-Nds+1;
    }
}
int main(){
    cout<<"Teste"<<endl;
    cout<<P046()<<endl;
    return 0;
}
