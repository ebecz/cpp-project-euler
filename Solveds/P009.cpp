#include <iostream>
#include <cmath>
using namespace std;
unsigned int P009(void){
    unsigned int i,B;
    unsigned int A=500000;
    for(i=1;i<1000;i++){
        B=1000-i;
        if(!(A%B)){
            A=(1000-(A/B));
            B=i;
            return A*B*((int)sqrt((double)(A*A+B*B)));
        }
    }
    return 0;
}
int main(){
    cout<<P009()<<endl;
    return 0;
}
