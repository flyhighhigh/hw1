void radixsort(){
    
    if(option==STR)
        ;//quick_str(0,data_cnt-1);
    
    else
        radix_int();
    return;
}

void radix_int(){
    int n=1;
    int zerocount=1;

    while(zerocount!=data_cnt){
        int count[10]={0};
        for(int i=0;i<10;i++){//¨C­Ó¼Æ¦r0~9
            for(int j=0;j<data_cnt;j++){
                if(data_int[j]/n%10==i){
                    radix_list[i][count[i]++]=data_int[j];
                }
            }
        }
        int idx=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<count[i];j++){
                data_int[idx++]=radix_list[i][j];
            }
        }
        n*=10;
        zerocount=count[0];
    }
    
    return;
}
