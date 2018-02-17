#include <iostream>
using namespace std;
signed int P028(const unsigned int n){
    unsigned int T=1,R=1;
    for(unsigned int i=1;i<=(n/2);i++){
        for(unsigned int j=0;j<4;j++){
            T+=2*i;
            R+=T;
        }
    }
    return R;
}
int main(){
    cout<<P028(1001)<<endl;
    return 0;
}
