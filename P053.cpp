#include <iostream>
#include <cstring>
using namespace std;
unsigned int UM=1000000;
unsigned int P053(){
    unsigned int N[101][101];
    unsigned int C=0;
    for(unsigned int i=0;i<101;i++){
        N[i][0]=1;
        N[i][i]=1;
    }
    for(unsigned int i=2;i<101;i++){
        for(unsigned int j=1;j<i;j++){
            N[i][j]=N[i-1][j-1]+N[i-1][j];
            if(N[i][j]>UM){
                C++;
            }
        }
    }
    return C;
}
int main(){
    cout<<P053()<<endl;
    return 0;
}

