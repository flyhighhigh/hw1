void quicksort_improve(){
    if(option==STR)
        quick_str(0,data_cnt-1);
    else
        quick_int_improve(0,data_cnt-1);
    return;
}

void quick_int_improve(int start, int end){

    if(start+5<end){
        threenumber(start,end);//����start�O start middle end �������
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
    else insert(start,end);
    return;
}
/*
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
*/
void insert(int start,int end){
	int i,j;
	for(i=start;i<=end;i++){
		int key=data_int[i];

		for(j=i-1;data_int[j]>key&&j>=0;j--){
			data_int[j+1]=data_int[j];
		}
		data_int[j+1]=key;
	}
	//printf("insert finish\n");
	return;
}


void threenumber(int start,int end){
    //�Nstart�q�������
	int mid=(start+end)/2;
 
	if (data_int[mid] > data_int[end])
		swap_int(&data_int[mid],&data_int[end]);

	if (data_int[start] > data_int[end])
		swap_int(&data_int[start],&data_int[end]);
    //����end�����̤j
	if (data_int[mid] > data_int[start]) 
		swap_int(&data_int[mid],&data_int[start]);
    //mid�̤p start�� end�j
	return;
}