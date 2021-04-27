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
    if(end>start+1){
        int middle=data_int[start];
        int left=start+1;
        int right=end;

        while (left < right){
            if (data_int[left]>middle){
                while(data_int[right]>middle && left<right)right--;

                if(left==right)break;
                else swap_int(&data_int[left++],&data_int[right]);
            }
            else left++;
        }
        
        swap_int(&data_int[left-1], &data_int[start]);
        quick_int(start,left-1);
        quick_int(right,end);
    }
    else if(data_int[start]>data_int[end])swap_int(&data_int[start], &data_int[end]);
    return;

}

void quick_str(int start, int end){
    if(end>start+1){
        char *middle=data_str[start];
        int left=start+1;
        int right=end;

        while (left < right){
            if (strcmp(data_str[left],middle)>0){
                while(strcmp(data_str[right],middle)>0 && left<right)right--;

                if(left==right)break;
                else swap_str(&data_str[left++],&data_str[right]);
            }
            else left++;
        }
        
        swap_str(&data_str[left-1], &data_str[start]);
        quick_str(start,left-1);
        quick_str(right,end);
    }
    else if(strcmp(data_str[start],data_str[end])>0)swap_str(&data_str[start], &data_str[end]);
    return;
}