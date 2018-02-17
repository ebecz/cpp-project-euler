#include <iostream>
#include <cstring>
using namespace std;
#define milhao 1000000
unsigned int inline Rot(unsigned int x){
    unsigned int R,t;
    R=x%10;
    x/=10;
    t=x;
    while(t){
        R*=10;
        t/=10;
    }
    return R+x;
}
inline bool IsRotP(bool*Matriz,unsigned int i){
    unsigned int i2=i;
    do{
        if(!Matriz[i2]){
            return false;
        }
        i2=Rot(i2);
    }while(i!=i2);
    return true;
}
unsigned int P035(){
    bool Matriz[milhao];
    unsigned int i=1;
    memset(&Matriz,true,sizeof(Matriz));
    do{
        do{
            i++;
            if(i>=milhao){
                unsigned int S=0;
                for(i=2;i<milhao;i++){
                    if(IsRotP(&Matriz[0],i)){
                        S++;
                    }
                }
                return S;
            }
        }while(!Matriz[i]);
        for(unsigned int j=2*i;j<milhao;j+=i){
            Matriz[j]=false;
        }
    }while(true);
}
int main(){
    cout<<P035()<<endl;
    return 0;
}
