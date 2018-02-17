#include <iostream>
using namespace std;
template<int Max>class Seq{
    private:
        char N[Max];
        unsigned int periodo,offset,termos;
    public:
        unsigned int GETPeriodo(unsigned int div){
            bool S;
            unsigned int Ttermos,NUso=10;
            periodo=1;
            offset=10;
            termos=0;
            do{
                Ttermos=periodo*3+offset;
                for(;termos<Ttermos;termos++){
                    N[termos]=NUso/div;
                    NUso%=div;
                    NUso*=10;
                }
                S=false;
                for(unsigned int i=0;i<periodo;i++){
                    if(N[i+offset]!=N[i+periodo+offset] || N[i+offset]!=N[i+2*periodo+offset]){
                        periodo++;
                        S=true;
                        break;
                    }
                }
            }while(S);
            return periodo;
        }
};
unsigned int P026(unsigned int N_){
    unsigned int Max=0,N;
    unsigned int i;
    Seq<3000>Num;
    for(i=1;i<N_;i++){
        unsigned int t=Num.GETPeriodo(i);
        if(t>Max){
            Max=t;
            N=i;
        }
    }
    return N;
}
int main(){
    cout<<P026(1000)<<endl;
    return 0;
}
