void swap_str(char **a,char **b){
	char *temp=*a;
	*a=*b;
	*b=temp;
}

void swap_int(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quicksort(){
    if(option==STR)
        quick_str(0,data_cnt-1);
    else
        quick_int(0,data_cnt-1);
    return;
}

void quick_int(int start, int end){

    if(start<end){
        int mid=data_int[start];
        int left=start;
        int right=end;

        while (left < right){
            while(data_int[left]<=mid && left<end)
                left++;
            while(data_int[right]>mid)
                right--;
            if(left<right)
                swap_int(&data_int[left],&data_int[right]);
        }
        swap_int(&data_int[start],&data_int[right]);
        quick_int(start,right-1);
        quick_int(right+1,end);
    }
    return;
}

void quick_str(int start, int end){
    if(start<end){
        char* mid=data_str[start];
        int left=start;
        int right=end;

        while (left < right){
            while(strcmp(data_str[left],mid)<=0 && left<end)
                left++;
            while(strcmp(data_str[right],mid)>0)
                right--;
            if(left<right)
                swap_str(&data_str[left],&data_str[right]);
        }
        swap_str(&data_str[start],&data_str[right]);
        quick_str(start,right-1);
        quick_str(right+1,end);
    }
    return;
}