#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
signed int P029(unsigned int n){
    unsigned int R=0;
    bool M[n+1][(n+1)*8];
    bool Sets[n+1];
    memset(M,0,sizeof(M));
    memset(Sets,0,sizeof(Sets));
    for(unsigned int i=2;i<=n;i++){
        if(!Sets[i]){
            for(unsigned int k=1,c=1;i*k<=n;c++,k*=i){
                for(unsigned int j=2;j<=n;j++){
                    if(!M[i][j*c]){
                        M[i][j*c]=true;
                        R++;
                    }
                }
                Sets[k*i]=true;
            }
        }
    }
    return R;
}
int main(){
    cout<<P029(100)<<endl;
    return 0;
}
