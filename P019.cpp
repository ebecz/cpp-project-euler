#include <iostream>
using namespace std;
unsigned char DaysEachMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
enum {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
unsigned short int GetDays(unsigned short int Year,unsigned short int Month){
    return DaysEachMonth[Month]+
    ((Month==1)?(
        ((Year%4)?(
            0
        ):(
            ((Year%100)?(
                1
            ):(
                ((Year%400)?(
                    0
                ):(
                    1
                ))
            ))
        ))
    ):(
        0
    ));
}
unsigned int P019() {
    unsigned int S,i,j,Sundays=0;
    for (i=0,S=0;i<12;i++) {
        S+=GetDays(1900,i);
    }
    for(j=1901;j<=2000;j++){
        for(i=0;i<12;i++){
            S%=7;
            if(S==Sunday){
                Sundays++;
            }
            S+=GetDays(j,i);
        }
    }
    return Sundays;
}
int main() {
    cout<<P019()<<endl;
    return 0;
}
