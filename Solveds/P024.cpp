#include <iostream>
using namespace std;
unsigned int Result=0;
inline void PN(unsigned int n){
    static char Seq[10]={'0','1','2','3','4','5','6','7','8','9'};
    unsigned int i,c;
    for(c=-1,i=0;c!=n;i++){
        if(Seq[i]){
            c++;
        }
    }
    Result*=10;
    Result+=Seq[i-1]-'0';
    Seq[i-1]=0;
}
unsigned int P024(unsigned int n){
    n--;
    unsigned int N=n;
    static unsigned int Factorial=362880;//=9!
    for(unsigned int i=10;i>0;i--){
        PN(N/Factorial);
        N%=Factorial;
        Factorial/=(i-1)?(i-1):1;
    }
    return Result;
}
int main(){
    cout<<P024(1000000)<<endl;
    return 0;
}
