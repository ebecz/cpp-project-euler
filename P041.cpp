#include <iostream>
#include <cstring>
using namespace std;
bool Is_Prime(unsigned int N){  //Works fine, except for the two number
    for(unsigned int i=2;i<N/2;i++){
        if(!(N%i)){
            return false;
        }
    }
    return true;
}
unsigned int Big_PanDigital_Prime(unsigned int Mbits,unsigned int N){
    if(!Mbits){
        if(Is_Prime(N)){
            return N;
        }else{
            return 0;
        }
    }
    for(unsigned int i=9;i>0;i--){
        if(Mbits&(1<<(i-1))){
            unsigned int x=Big_PanDigital_Prime(Mbits^(1<<(i-1)),N*10+i);
            if(x){
                return x;
            }
        }
    }
    return 0;
}
unsigned int P041(){
    for(unsigned int i=9;i>0;i--){
        cout<<"Testando com "<<i<<" digitos"<<endl;
        unsigned int x=Big_PanDigital_Prime((1<<i)-1,0);
        if(x){
            return x;
        }
    }
    return 0;
}
int main(){
    cout<<P041()<<endl;
    return 0;
}
