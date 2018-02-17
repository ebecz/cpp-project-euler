#include <iostream>
using namespace std;
#define MAX 1000000
bool is10Palindrome(unsigned int n){
    unsigned int R=0,m=n;
    do{
        R*=10;
        R+=n%10;
        n/=10;
    }while(n);
    return (R==m);
}
bool is2Palindrome(unsigned int n){
    unsigned int R=0,m=n;
    do{
        R<<=1;
        R|=(n&1);
        n>>=1;
    }while(n);
    return (R==m);
}
unsigned int P036(){
    unsigned int N=0;
    for(unsigned int i=0;i<MAX;i++){
        if(is10Palindrome(i) && is2Palindrome(i)){
            N+=i;
        }
    }
    return N;
}
int main(){
    cout<<P036()<<endl;
    return 0;
}
