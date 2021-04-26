void radixsort(){
    
    if(option==STR)
        radix_str();
    
    else
        radix_int();
    return;
}

void radix_int(){
    long n=1;
    int len=10;

    while(len--){
        int count[10]={0};
        for(int j=0;j<data_cnt;j++){
            int i=data_int[j]/n%10;
            radix_list_int[i][count[i]++]=data_int[j];
        }
        int idx=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<count[i];j++){
                data_int[idx++]=radix_list_int[i][j];
            }
        }
        n*=10;
    }
    return;
}

void radix_str(){

    for(int k=99;k>=0;k--){
        int count[52]={0};
        for(int j=0;j<data_cnt;j++){
            int c=isupper(data_str[j][k])?data_str[j][k]-'A':data_str[j][k]-'a'+26;
            radix_list_str[c][count[c]++]=data_str[j];
        }
        int idx=0;
        for(int i=0;i<52;i++){
            for(int j=0;j<count[i];j++){
                data_str[idx++]=radix_list_str[i][j];
            }
        }
    }
    return;
}