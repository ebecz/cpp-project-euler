#include <iostream>
using namespace std;
unsigned long long  P015(unsigned int N){
    unsigned long long int M[N+1][N+2];
    unsigned int i,j;
    for(i=0;i<N+1;i++){
        M[0][i]=1;
        M[i][0]=1;
    }
    for(i=1;i<N+1;i++){
        for(j=1;j<N+2;j++){
            M[i][j]=M[i-1][j]+M[i][j-1];
        }
    }
    return M[N][N];
}
int main(){
    cout<<P015(20)<<endl;
    return 0;
}
