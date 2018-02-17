#include <iostream>
#include <cstring>
using namespace std;
const unsigned int N=10000000;
unsigned int P052(){
    for(unsigned int i=1;i<N;i++){
        unsigned char D[10],D0[10];
        memset(D0,0,sizeof(D0));
        {
            unsigned int x=i;
            while(x){
                D0[x%10]++;
                x/=10;
            }
        }
        for(unsigned int j=2;j<=6;j++){
            unsigned int x=i*j;
            memset(D,0,sizeof(D));
            while(x){
                D[x%10]++;
                x/=10;
            }
            for(unsigned int k=0;k<10;k++){
                if(D[k]!=D0[k]){
                    goto end;
                }
            }
        }
        return i;
        end:;
    }
    return 0;
}
int main() {
    cout<<P052()<<endl;
    return 0;
}

