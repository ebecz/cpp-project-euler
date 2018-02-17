#include <iostream>
#include <cstring>
using namespace std;
unsigned long long int P049(){
    const unsigned int max=9999;
    bool Pr[max]={0,0};
    for(unsigned int i=2;i<max;i++){
        Pr[i]=true;
    }
    for(unsigned int i=0;i<max;i++){
        if(Pr[i]){
            for(unsigned int j=2;j*i<max;j++){
                Pr[i*j]=false;
            }
        }
    }
    {
        unsigned int i=999;
        while(true){
            unsigned int L[24];
            unsigned int Lm=0;
            while(!Pr[++i]){
                if(i>max){
                    cout<<"Fim"<<endl;
                    return 0;
                }
            }{
                unsigned int Lt[24];
                unsigned int Ltm=0;
                unsigned char N[4]={(i/1000)%10,(i/100)%10,(i/10)%10,i%10};
                for(unsigned int a=0;a<4;a++){
                    for(unsigned int b=0;b<4;b++){
                        if(b!=a){
                            for(unsigned int c=0;c<4;c++){
                                if(c!=a && c!=b){
                                    for(unsigned int d=0;d<4;d++){
                                        if(d!=a && d!=b && d!=c){
                                            unsigned r=N[a]*1000+N[b]*100+N[c]*10+N[d]*1;
                                            if(Pr[r]){
                                                Lt[Ltm]=r;
                                                Ltm++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    Lt[Ltm]=(unsigned int)-1;
                    unsigned int aux=Ltm;
                    Ltm++;
                    do{
                        for(unsigned int j=0;j<Ltm;j++){
                            if(Lt[j]<Lt[aux]){
                                aux=j;
                            }
                        }
                        if(Lt[aux]==(unsigned int)-1){
                            break;
                        }
                        if(!Lm || L[Lm-1]!=Lt[aux]){
                            L[Lm]=Lt[aux];
                            Lm++;
                        }
                        Lt[aux]=(unsigned int)-1;
                    }while(true);
                }
            }
            /*
            cout<<i<<":";
            for(unsigned int j=0;j<Lm;j++){
                cout<<L[j]<<"\t";
            }
            cout<<endl;
            */
            if(Lm<2){
                continue;
            }
            for(unsigned int j=0;j<Lm-2;j++){
                for(unsigned int k=j+1;k<Lm;k++){
                    unsigned int r=2*L[k]-L[j];
                    for(unsigned int l=k+1;l<Lm;l++){
                        if(r<L[l]){
                            break;
                        }else if(r==L[l]){
                            cout<<"ACHEI"<<endl;
                            cout<<L[j]<<"\t"<<L[k]<<"\t"<<r<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    cout<<"A resposta estara no segundo, pois o primeiro foi desconsiderado por nao ter 3330 como diferenca na progrecao"<<endl<<endl;
    cout<<P049()<<endl;
    return 0;
}

