#include <iostream>
using namespace std;
unsigned int P008(void){
    unsigned int i,M,N,length;
    unsigned char Ns[1024];
    cin>>Ns;
    for(i=0;Ns[i];i++){
        Ns[i]=Ns[i]-'0';
    }
    length=i;
    for(i=4;i<length;i++){
        N=Ns[i]*Ns[i-1]*Ns[i-2]*Ns[i-3]*Ns[i-4];
        if(N>M){
            M=N;
        }
    }
    return M;
}
int main(){
    cout<<"Requires text site's"<<endl;
    cout<<P008()<<endl;
    return 0;
}
