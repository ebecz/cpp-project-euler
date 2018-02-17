#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const unsigned long long int UM=1;
const char Cards[13]={'2','3', '4', '5', '6','7','8', '9', 'T', 'J', 'Q', 'K', 'A'};
const char Suit[4]={'H','C','S','D'};
unsigned long long int Hitter(char H[5][2]){
    unsigned int S[4];
    unsigned int C[13];
    memset(S,0,sizeof(S));
    memset(C,0,sizeof(C));
    for(unsigned int k=0;k<5;k++){
        unsigned int i,j;
        for(i=0;H[k][0]!=Cards[i];i++);
        for(j=0;H[k][1]!=Suit[j];j++);
        S[j]|=UM<<i;
        C[i]|=UM<<j;
    }{
        unsigned long long int V=0;
        for(unsigned int j=0;j<4;j++){
            V|=S[j];
        }
        for(unsigned int i=0;i<13;i++){
            unsigned int T=C[i],bits=0;
            while(T){
                bits++;
                T=T&(T-1);
            }
            switch(bits){
                case 4:
                    V|=UM<<42;
                    V|=i<<13;
                break;
                case 3:
                    V|=UM<<25;
                    V|=i<<19;
                break;
                case 2:
                    if(V&(UM<<18)){
                        V|=UM<<24;
                        V|=i<<19;
                    }else{
                        V|=UM<<18;
                        V|=i<<13;
                    }
                break;
                default:

                break;
            }
        }
        if((V&(UM<<18)) && (V&(UM<<25))){
            V|=UM<<41;
            V|=(V&0x1FFF)<<28;
        }{
            unsigned long long int T=(V&0x1FFF)<<1;
            if(((T&(T^(T-1)))*0x1F)==T){
                V|=UM<<26;
            }
        }{
            unsigned int s=0;
            for(unsigned int j=0;j<4;j++){
                if(S[j]){
                    s++;
                }
            }
            if(s==1){
                V|=UM<<27;
            }
        }
        if((V&(UM<<26)) && (V&(UM<<27))){
            V|=UM<<43;
            if((V&0x1F00)==0x1F00){
                V|=UM<<44;
            }
        }
        return V;
    }
    return 0;
}
unsigned int P054(){
    unsigned int c=0;
    char Line[3];
    ifstream X;
    X.open("P054.txt",ios::binary);
    while(!X.eof()){
        char H1[5][2],H2[5][2];
        unsigned long long int T1,T2;
        for(unsigned int k=0;k<5;k++){
            X>>Line;
            H1[k][0]=Line[0];
            H1[k][1]=Line[1];
        }
        for(unsigned int k=0;k<5;k++){
            X>>Line;
            H2[k][0]=Line[0];
            H2[k][1]=Line[1];
        }
        T1=Hitter(H1);
        T2=Hitter(H2);
        if(T1>T2){
            c++;
        }
    }
    X.close();
    return c;
}
int main(){
    cout<<P054()<<endl;
    return 0;
}
void Describe(unsigned long long int V){
    if(V&(UM<<46)){
        cout<<"Royal Flush"<<endl;
    }else if(V&(UM<<45)){
        cout<<"Straight Flush:";
        {
            unsigned int i=13;
            while(!(V&(UM<<--i)));
            cout<<Cards[i]<<endl;
        }

    }else if(V&(UM<<44)){
        cout<<"Four of a Kind:"<<Cards[((V>>13)&0x1F)]<<endl;
    }else if(V&(UM<<43)){
        cout<<"Full House:";
        {
            unsigned int i=13;
            while(!(V&(UM<<--i)));
            cout<<Cards[i]<<endl;
        }
    }else if(V&(UM<<28)){
        cout<<"Flush:";
        {
            unsigned int i=13;
            while(!(V&(UM<<--i)));
            cout<<Cards[i]<<endl;
        }
    }else if(V&(UM<<27)){
        cout<<"Straight:"<<endl;
        {
            unsigned int i=13;
            while(!(V&(UM<<--i)));
            cout<<Cards[i]<<endl;
        }
    }else if(V&(UM<<26)){
        cout<<"Three of a Kind:"<<Cards[((V>>20)&0x1F)]<<endl;

    }else if(V&(UM<<25)){
        cout<<"Two Pairs:"<<Cards[((V>>20)&0x1F)]<<" and "<<Cards[((V>>13)&0x1F)]<<endl;
    }else if(V&(UM<<19)){
        cout<<"One Pair:"<<Cards[((V>>13)&0x1F)]<<endl;
    }else{
        unsigned int i=13;
        while(!(V&(UM<<--i)));
        cout<<"Hight card:"<<Cards[i]<<endl;
    }
}
