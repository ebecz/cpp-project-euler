#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAXNAME 13
struct Text{
    char Nome[13];
    bool operator<(const Text&b)const{
    unsigned int c=0;
    do{
        if(this->Nome[c]<b.Nome[c]){
            return true;
        }else if(this->Nome[c]>b.Nome[c]){
            return false;
        }
    }while(++c<MAXNAME);
    return false;
}
}Tmp;
unsigned int P022(){
    ifstream File("P022.txt",ios::in|ios::binary|ios::ate);
    if(File.is_open()){
        File.seekg (0, ios::beg);
        vector<Text>Lista;
        unsigned char c;
        unsigned int i=0;
        do{
            if(File.eof()){
                c=0;
            }else{
                File.read ((char*)(&c),sizeof(char));
            }
            switch(c){
                case '"':
                    break;
                case 0:
                case ',':
                    Tmp.Nome[i++]=0;
                    if(i>=MAXNAME){
                        throw("Aumente o MAXNAME");
                    }
                    Lista.push_back(Tmp);
                    i=0;
                    break;
                default:
                    if(c>='A' && c<='Z'){
                        Tmp.Nome[i++]=c;
                    }
                    break;
            }
        }while(c);
        sort(Lista.begin(), Lista.end());
        vector<Text>::iterator iter;
        unsigned int Sg=0;
        for(iter=Lista.begin(),i=1;iter!=Lista.end();iter++,i++){
            unsigned int j=0,S=0;
            do{
                S+=iter->Nome[j]-'A'+1;
            }while(iter->Nome[++j]);
            Sg+=S*i;
        }
        File.close();
        return Sg;
    }else{
        throw("Arquivo não existe");
        return 0;
    }
}
/*
#define MAXNAME 13
struct Text{
    char*Nome;
    bool operator<(const Text&b)const{
        unsigned int c=0;
        do{
            if(this->Nome[c]<b.Nome[c]){
                return true;
            }else if(this->Nome[c]>b.Nome[c]){
                return false;
            }
        }while(++c<MAXNAME);
        return false;
    }
}Names[]={
    #include "P022.txt"
};
unsigned int P022(){
    unsigned int i;
    vector<Text>Lista;
    for(i=0;i<sizeof(Names)/sizeof(Text);i++){
        Lista.push_back(Names[i]);
    }
    sort(Lista.begin(), Lista.end());
    vector<Text>::iterator iter;
    unsigned int Sg=0;
    for(iter=Lista.begin(),i=1;iter!=Lista.end();iter++,i++){
        unsigned int j=0,S=0;
        do{
            S+=iter->Nome[j]-'A'+1;
        }while(iter->Nome[++j]);
        Sg+=S*i;
    }
    return Sg;
}
*/
int main() {
    cout<<P022()<<endl;
    return 0;
}
