#include <iostream>
#include <cstring>
using namespace std;
unsigned long long int s=0;
const unsigned long long int P[]={0,1,2,3,5,7,11,13,17};
bool Have_ThePropertie(unsigned long long int N){
    for(unsigned int i=8;i;i--){
        if((N%1000)%P[i]){
            return false;
        }
        N/=10;
    }
    return true;
}
void Mount_PanDigital(unsigned int Mbits,unsigned long long int N){
    if(!Mbits){
        if(Have_ThePropertie(N)){
            s+=N;
        }
    }else{
        for(unsigned long long int i=10;i>0;i--){
            if(Mbits&(1<<(i-1))){
                Mount_PanDigital(Mbits^(1<<(i-1)),N*10+(i-1));
            }
        }
    }
}
unsigned long long int P043(){
    Mount_PanDigital((1<<10)-1,0);
    return s;
}
int main(){
    cout<<P043()<<endl;
    return 0;
}
