#include <iostream>
using namespace std;
unsigned int P006(unsigned int N){
    unsigned int S=N*(N+1)/2;
    return (S*(S*3-(2*N+1)))/3;
}
int main(){
    cout<<P006(100)<<endl;
    return 0;
}
