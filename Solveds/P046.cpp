#include <iostream>
#include <cstring>
using namespace std;
unsigned int const Max=10000;
bool Numbers[Max]={false,false};
bool IsPerfectSquare(unsigned int N){
    for(unsigned int i=2;i<Max;i++){
        if(Numbers[i]){
            unsigned int c=0;
            while(!(N%i)){
                N/=i;
                c++;
            }
            if(c%2){
                return false;
            }
        }
        if(N==1){
            return true;
        }
    }
    return true;
}
unsigned int P046(){
    for(unsigned int i=2;i<Max;i++){
        Numbers[i]=true;
    }
    for(unsigned int i=0;i<Max;i++){
        if(Numbers[i]==true){
            for(unsigned int j=2;j*i<Max;j++){
                Numbers[j*i]=false;
            }
        }
    }
    for(unsigned int i=3;i<Max;i+=2){
        if(!Numbers[i]){
            unsigned int n=i,j=0;
            do{
                n-=2;
                j++;
                if(n==1){
                    return i;
                }
                while(!Numbers[n]){
                    n-=2;
                    j++;
                }
            }while(!IsPerfectSquare(j));
        }
    }
    cout<<"Aumente o buffer"<<endl;
    return 0;
}
int main(){
    cout<<P046()<<endl;
    return 0;
}
