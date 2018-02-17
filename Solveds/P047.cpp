#include <iostream>
#include <cstring>
using namespace std;
const unsigned int Max=30000;
const unsigned int Nds=4;
unsigned int P[Max];
unsigned char N[Nds][Max];
bool Prime[Max*100];
unsigned int P047(){
    {
        unsigned int c=0;
        for(unsigned int i=0;i<Max*100;i++){
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
            if(i>=100*Max){
                cout<<"Aquele 100 tah errado"<<endl;
            }
        }while(c<Max);
        cout<<"Ultimo Primo="<<P[Max-1]<<endl;
    }{
        unsigned int i=0;
        unsigned int c=0;
        do{
            c=Nds;
            i++;
            if(!(i%1000)){
                cout<<i<<endl;
            }
            unsigned char T[Max];
            {
                unsigned int t=i;
                for(unsigned int j=0;j<Max;j++){
                    T[j]=0;
                    while(!(t%P[j])){
                          T[j]++;
                          t/=P[j];
                    }
                }
                if(t!=1){
                    cout<<"Aumente os Primos, index="<<i<<endl;
                    cout<<"Ultimo primo="<<P[Max-1]<<endl;
                    return 0;
                }
            }
            for(unsigned int i=0;i<Nds-1;i++){
                unsigned int c_=0;
                for(unsigned int j=0;j<Max;j++){
                    N[i][j]=N[i+1][j];
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
                    N[Nds-1][j]=T[j];
                    if(N[Nds-1][j]){
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
    cout<<P047()<<endl;
    return 0;
}
