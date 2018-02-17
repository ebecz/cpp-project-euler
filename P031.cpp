#include <iostream>
using namespace std;
unsigned int P031(){
    unsigned long long int R=0;
    for(unsigned int g=0;g<=200;g+=200){
        for(unsigned int a=0;a+g<=200;a+=100){
            for(unsigned int b=0;g+a+b<=200;b+=50){
                for(unsigned int c=0;g+a+b+c<=200;c+=20){
                    for(unsigned int d=0;g+a+b+c+d<=200;d+=10){
                        for(unsigned int e=0;g+a+b+c+d+e<=200;e+=5){
                            for(unsigned int f=0;g+a+b+c+d+e+f<=200;f+=2){
                                R++;
                            }
                        }
                    }
                }
            }
        }
    }
    return R;
}
int main(){
    cout<<P031()<<endl;
    return 0;
}
