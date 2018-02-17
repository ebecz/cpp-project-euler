#include <iostream>
#include <cstring>
using namespace std;
const char*words[]={
#include "P042.txt"
};
unsigned int P042(){
    unsigned int S;
    const int MAX=20;
    unsigned int Tn[MAX];
    for(unsigned int i=0;i<MAX;i++){
        Tn[i]=(i+1)*(i+2)/2;
    }
    unsigned int i=0;
    while(words[i]){
        unsigned int s=0;
        {
            unsigned int i2=0;
            while(words[i][i2]){
                s+=1+words[i][i2]-'A';
                i2++;
            }
        }{
            unsigned int j=0;
            while(Tn[j]<=s){
                if(Tn[j]==s){
                    S++;
                }
                j++;
            }
        }
        i++;
    };
    return S;
}
int main(){
    cout<<P042()<<endl;
    return 0;
}
