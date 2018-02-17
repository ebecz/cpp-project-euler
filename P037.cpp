#include <iostream>
#include <cstring>
using namespace std;
#define milhao 1000000
bool Matriz[milhao];
bool Right(unsigned int i){
    if(i){
        if(Matriz[i]){
            return Right(i/10);
        }else{
            return false;
        }
    }else{
        return true;
    }
}
inline unsigned int doit(unsigned int i){
    unsigned int r=1,s=0;
    while(i/10){
        s+=r*(i%10);
        i/=10;
        r*=10;
    }
    return s;
}
bool Left(unsigned int i){
    if(i){
        if(Matriz[i]){
            return Left(doit(i));
        }else{
            return false;
        }
    }else{
        return true;
    }
}
unsigned int P037(){
    unsigned int S=0,Num=0;
    unsigned int i=1;
    memset(&Matriz,true,sizeof(Matriz));
    Matriz[0]=Matriz[1]=false;
    do{
        do{
            i++;
            if(i>=milhao){
                return S;
            }
        }while(!Matriz[i]);
        for(unsigned int j=2*i;j<milhao;j+=i){
            Matriz[j]=false;
        }
        if(i>9){
            if(Right(i) && Left(i)){
                S+=i;
                Num++;
                cout<<i<<endl;
            }
        }
    }while(Num<11);
    return S;
}
int main(){
    cout<<P037()<<endl;
    return 0;
}
