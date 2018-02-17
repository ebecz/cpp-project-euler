#include <iostream>
using namespace std;
unsigned long long int P003(unsigned long long int x) {
    unsigned long long int i=1;
    while (x!=1) {
        i++;
        while (!(x%i)) {
            x/=i;
        }
    }
    return i;
}
int main(){
    cout<<P003(600851475143LL)<<endl;
    return 0;
}
