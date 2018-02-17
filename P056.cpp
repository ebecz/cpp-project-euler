#include <iostream>
using namespace std;
template<unsigned int B>class BIG{
    private:
        unsigned char N[B];
    public:
        void operator=(unsigned int T){
            for(unsigned int i=0;i<B;i++){
                N[i]=T&0xFF;
                T>>=8;
            }
        }
        void operator*=(unsigned int X){
            unsigned long long int S=0;
            for(unsigned int i=0;i<B;i++){
                S+=((unsigned long long int)N[i])*X;
                N[i]=S&0xFF;
                S>>=8;
            }
            if(S){
                cout<<"OverFlow"<<endl;
            }
        }
        unsigned int operator/=(unsigned int X){
            unsigned long long int S=0,R=0;
            for(unsigned int i=0;i<B;i++){
                S=R<<8;
                S+=N[B-1-i];
                R=S%10;
                N[B-1-i]=S/10;
            }
            return R;
        }
        bool operator!=(unsigned int X){
            for(unsigned int i=0;i<B;i++){
                if(N[i]!=(X&0x100)){
                    return true;
                }
                X>>=8;
            }
            return false;
        }
        unsigned int DigitalSum(void){
            BIG T=(*this);
            unsigned int S=0;
            while(T!=0){
                S+=(T/=10);
            }
            return S;
        }
};
unsigned long long int P056(){
    unsigned int M=0;
    BIG<100>T;
    for(unsigned int i=0;i<100;i++){
        T=1;
        for(unsigned int j=1;j<100;j++){
            T*=i;
            M=max(T.DigitalSum(),M);
        }
    }
    return M;
}
int main(){
    cout<<P056()<<endl;
    return 0;
}
