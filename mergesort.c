void mergesort(){
    
    if(option==STR){
        char** temp_str=(char**)malloc(sizeof(char*)*data_cnt);
        rec_merge_str(0,data_cnt-1,temp_str);
        free(temp_str);
    }
    if(option==INT){
        int* temp_int=(int*)malloc(sizeof(int)*data_cnt);
        rec_merge_int(0,data_cnt-1,temp_int);
        free(temp_int);
    }
    return;
}

void rec_merge_int(int left,int right,int *temp_int){

    if(left>=right)return;
    int mid=(left+right)/2;

    rec_merge_int(left,mid,temp_int);
    rec_merge_int(mid+1,right,temp_int);

    mergearray_int(left,mid,mid+1,right,temp_int);

    for(int i=left;i<=right;i++){
        data_int[i]=temp_int[i];
    }

}
void mergearray_int(int a,int a_end,int b,int b_end,int* temp_int){
    int idx=a;

    while(idx<=b_end){
        if(b>b_end){
            temp_int[idx++]=data_int[a++];
            continue;
        }
        if(a>a_end){
            temp_int[idx++]=data_int[b++];
            continue;
        }
        temp_int[idx++]=data_int[a]<data_int[b]?data_int[a++]:data_int[b++];
    }
}

void rec_merge_str(int left,int right,char** temp_str){

    if(left>=right)return;
    int mid=(left+right)/2;

    rec_merge_str(left,mid,temp_str);
    rec_merge_str(mid+1,right,temp_str);

    mergearray_str(left,mid,mid+1,right,temp_str);

    for(int i=left;i<=right;i++){
        data_str[i]=temp_str[i];
    }

}

void mergearray_str(int a,int a_end,int b,int b_end,char** temp_str){
    int idx=a;

    while(idx<=b_end){
        if(b>b_end){
            temp_str[idx++]=data_str[a++];//
            continue;
        }
        if(a>a_end){
            temp_str[idx++]=data_str[b++];//
            continue;
        }
        if(strcmp(data_str[a],data_str[b])<0){
            temp_str[idx++]=data_str[a++];//
        }
        else{
            temp_str[idx++]=data_str[b++];//
        }
    }
}