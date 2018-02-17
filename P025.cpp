#include <iostream>
using namespace std;
template<int Max>class GNumber{
    char N[Max];
    public:
        enum{Normal,OverFlow,UnderFlow};
        char state;
        void operator+=(GNumber<Max>&that){
            unsigned int r=0;
            for(unsigned int i=0;i<Max;i++){
                r=this->N[i]+that.N[i]+r;
                this->N[i]=r%10;
                r/=10;
            }
            if(r){
                state=OverFlow;
            }
        }
        void operator-=(GNumber<Max>&that){
            unsigned int i;
            signed int r=0;
            for(i=0;i<Max;i++){
                r=((signed int)that.N[i])-((signed int)this->N[i])+r;
                if(r>=0){
                    this->N[i]=r%10;
                    r/=10;
                }else{
                    this->N[i]=(10+r)%10;
                    r=-1;
                }
            }
        }
        GNumber(int n){
            state=Normal;
            for(unsigned int i=0;i<Max;i++){
                N[i]=n%10;
                n/=10;
            }
        }
};
unsigned int P025(){
    GNumber<999> a(1),b(1);
    unsigned int i=2;
    do{
        i++;
        a+=b;
        b-=a;
    }while(GNumber<999>::OverFlow!=a.state);
    return i;
}
int main(){
    cout<<P025()<<endl;
    return 0;
}
