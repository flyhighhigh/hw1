void mergesort(){
    
    if(option==STR)
        rec_merge_str(0,data_cnt-1);
    
    if(option==INT)
        rec_merge_int(0,data_cnt-1);

    return;
}

void rec_merge_int(int left,int right){

    if(left>=right)return;
    int mid=(left+right)/2;

    rec_merge_int(left,mid);
    rec_merge_int(mid+1,right);

    mergearray_int(left,mid,mid+1,right);

    for(int i=left;i<=right;i++){
        data_int[i]=temp_int[i];
    }

}
void mergearray_int(int a,int a_end,int b,int b_end){
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

void rec_merge_str(int left,int right){

    if(left>=right)return;
    int mid=(left+right)/2;

    rec_merge_str(left,mid);
    rec_merge_str(mid+1,right);

    mergearray_str(left,mid,mid+1,right);

    for(int i=left;i<=right;i++){
        data_str[i]=temp_str[i];
    }

}

void mergearray_str(int a,int a_end,int b,int b_end){
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