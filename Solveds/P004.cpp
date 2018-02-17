unsigned int P004(void){
    int j,k,i=90;
    int M[6],r,s,N=0;
    do{
        j=999;
        do{
            s=r=j*i*11;
            if(s && (i*11<=999 && j<=999)){
                for(k=0;k<6;k++){
                    M[k]=r%10;
                    r/=10;
                }
                if(M[0]==M[5] && M[1]==M[4] && M[2]==M[3]){
                    if(s>N){
                        N=s;
                    }else{
                        break;
                    }
                }
            }
        }while(j--);
    }while(i--);
    return N;
}
