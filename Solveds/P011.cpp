#include <iostream>
using namespace std;
unsigned int P011(void){
    unsigned int M[20][20];
    unsigned int N=0,n;
    unsigned int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            cin>>M[i][j];
        }
    }
    for(j=0;j<20;j++){
        for(i=3;i<20;i++){
            n=M[j][i]*M[j][i-1]*M[j][i-2]*M[j][i-3];
            if(n>N){
                N=n;
            }
            n=M[i][j]*M[i-1][j]*M[i-2][j]*M[i-3][j];
            if(n>N){
                N=n;
            }
        }
    }
    for(j=3;j<20;j++){
        for(i=3;i<20;i++){
            n=(M[j][i])*(M[j-1][i-1])*(M[j-2][i-2])*(M[j-3][i-3]);
            if(n>N){
                N=n;
            }
            n=M[j-3][i]*M[j-2][i-1]*M[j-1][i-2]*M[j][i-3];
            if(n>N){
                N=n;
            }
        }
    }
    return N;
}
int main(){
    cout<<"Requires text site's"<<endl;
    cout<<P011()<<endl;
    return 0;
}
