#include <iostream>
#include <cstring>
using namespace std;
unsigned long long int P013(void){
    unsigned char X[61];
    unsigned char Y[61];
    unsigned int i,j;
    unsigned long long int S;
    memset(Y,0,sizeof(Y));
    memset(X,'0',sizeof(char)*10);
    for(i=0;i<100;i++){
        cin>>&X[10];
        for(j=59;j>0;j--){
            Y[j]+=(X[j]-'0');
            Y[j-1]+=Y[j]/10;
            Y[j]%=10;
        }
    }
    for(i=0;!Y[i];i++);
    for(S=0,j=0;j<10;j++){
        S*=10;
        S+=Y[i+j];
    }
    return S;
}
int main(){
    cout<<"Requires text site's"<<endl;
    cout<<P013()<<endl;
    return 0;
}
