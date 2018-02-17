#include <iostream>
#include <cmath>
using namespace std;
class fraction{
    public:
        unsigned int dem,num;
        fraction operator*(unsigned int x){
            fraction R=*this;
            R.num*=x;
            return R;
        }
        fraction(){};
        fraction(unsigned int x){
            num=x;
            dem=1;
        }
        fraction operator+(fraction that){
            fraction R;
            R.dem=this->dem*that.dem;
            R.num=this->num*that.dem+that.num*this->dem;
            return R;
        }
        fraction operator/(fraction that){
            fraction R;
            R.dem=this->dem*that.num;
            R.num=this->num*that.dem;
            return R;
        }
        fraction operator*(fraction that){
            fraction R;
            R.dem=this->dem*that.dem;
            R.num=this->num*that.num;
            return R;
        }
        void operator++(int){
            num++;
        }
        bool operator<=(unsigned int x){
            return num<=x;
        }
        bool operator==(fraction that){
            return (this->num*that.dem==this->dem*that.num);
        }
        bool operator<(fraction that){
            return (this->num*that.dem<this->dem*that.num);
        }
        bool operator !=(unsigned int x){
            return (num)!=(x*dem);
        }
        void Simple(void){
            for(unsigned int i=2;i<=num;i++){
                if(!(num%i) && !(dem%i)){
                    num/=i;
                    dem/=i;
                    i--;
                }
            }
        }
};
ostream&operator<<(ostream&a,fraction b){
    a<<'('<<b.num<<'/'<<b.dem<<')';
    return a;
}
unsigned int P033(){
    fraction P=fraction(1);
    for(fraction i=1;i<=9;i++){
        for(fraction j=0;j<=9;j++){
            for(fraction k=1;k<=9;k++){
                if(!(k==j && k==i)){
                    if(j<k){
                        if((j/k)==(j*10+i)/(i*10+k)){
                            //cout<<j/k<<'='<<(j*10+i)/(i*10+k)<<endl;
                            P=P*(j/k);
                        }else if((j/k)==(i*10+j)/(k*10+i)){
                            //cout<<j/k<<'='<<(i*10+j)/(k*10+i)<<endl;
                            P=P*(j/k);
                        }
                    }
                }
            }
        }
    }
    //cout<<P<<endl;
    P.Simple();
    return P.dem;
}
int main(){
    cout<<P033()<<endl;
    return 0;
}
