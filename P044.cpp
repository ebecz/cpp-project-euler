#include <iostream>
#include <cstring>
using namespace std;
const unsigned int Max=10000;
unsigned int L[Max];
bool Find(unsigned int n){
    unsigned int k=Max/4,i=Max/2;
    do{
        if(L[i]<n){
            i+=k;
        }else{
            i-=k;
        }
        k/=2;
    }while(k);
    if(L[i]<n){
        while(L[i]<n){
            if(i==Max){return false;}
            i++;
        };
    }else{
        while(L[i]>n){
            if(i==0){return false;}
            i--;
        };
    }
    if(L[i]==n){
        return true;
    }else{
        return false;
    }
}
unsigned int P044(){
    unsigned int MMin=(unsigned int)-1,Min=MMin;
    //Fill the sequence
    for(unsigned int n=0;n<Max;n++){
        L[n]=(n+1)*(3*n+2)/2;
    }
    //Testing diferences
    for(unsigned int i=0;i<Max;i++){
        for(unsigned int j=i;j+i<Max;j++){
            if(Min>(L[j]-L[i])){
                if(Find(L[j]-L[i])){
                    if(Find(L[j]+L[i])){
                        Min=L[j]-L[i];
                    }
                }
            }
        }
    }
    if(MMin==Min){
        cout<<"Aumente o Buffer"<<endl;
        return 0;
    }
    return Min;
}
int main(){
    cout<<P044()<<endl;
    return 0;
}
