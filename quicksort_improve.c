#include "main.h"
#include "quicksort.h"
#include "quicksort_improve.h"

void quicksort_improve(){
    if(option==STR)
        quick_str_improve(0,data_cnt-1);
    else
        quick_int_improve(0,data_cnt-1);
    return;
}

void quick_int_improve(int start, int end){

    if(start+10>end){
        insert_int(start,end);
        return;
    }

        threenumber(start,end);//此時start是 start middle end 之中位數
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
        quick_int_improve(start,right-1);
        quick_int_improve(right+1,end);

}

void insert_int(int start,int end){
	int i,j;
    
	for(i=start+1;i<=end;i++){
		int key=data_int[i];

		for(j=i-1;data_int[j]>key&&j>=start;j--){
			data_int[j+1]=data_int[j];
		}
		data_int[j+1]=key;
	}
	return;
}

void quick_str_improve(int start, int end){

    if(start+10>end){
        insert_str(start,end);
        return;
    }
        
        threenumber(start,end);//此時start是 start middle end 之中位數
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
        quick_str_improve(start,right-1);
        quick_str_improve(right+1,end);

}

void insert_str(int start,int end){
	int i,j;
    
	for(i=start+1;i<=end;i++){
		char* key=data_str[i];

		for(j=i-1;strcmp(data_str[j],key)>0&&j>=start;j--){
			data_str[j+1]=data_str[j];
            //因為strcmp j=-1時會出錯 要避免J=-1的情況
            if(j==0){j--;break;}
		}
		data_str[j+1]=key;
	}
	return;
}


void threenumber(int start,int end){
    //將start訂為中位數
	int mid=(start+end)/2;

	if (cmp_idx(mid,end)>0)
		swap_idx(mid,end);

	if (cmp_idx(start,end)>0)
		swap_idx(start,end);
    //此時end必為最大
	if (cmp_idx(mid,start)>0) 
		swap_idx(mid,start);
    //mid最小 start中 end大
	return;
}
