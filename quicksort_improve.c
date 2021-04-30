#include "main.h"
#include "quicksort.h"
#include "quicksort_improve.h"

void quicksort_improve(){
    if(option==STR)
        ;//quick_str_improve(0,data_cnt-1);
    else
        quick_int_improve(0,data_cnt-1);
    return;
}

void quick_int_improve(int start, int end){
/*
    if(start+10>end){
        insert(start,end);
        return;
    }
*/
        if(start>=end)return;

        threenumber(start,end);//start琌 start middle end ぇい计
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

void insert(int start,int end){
	int i,j;
    
	for(i=start;i<=end;i++){
		int key=data_int[i];

		for(j=i-1;data_int[j]>key&&j>=start;j--){
			data_int[j+1]=data_int[j];
		}
		data_int[j+1]=key;
	}
	return;
}


void threenumber(int start,int end){
    //盢start璹い计
	int mid=(start+end)/2;
 
	if (cmp_idx(mid,end)>0)
		swap_idx(mid,end);

	if (cmp_idx(start,end)>0)
		swap_idx(start,end);
    //endゲ程
	if (cmp_idx(mid,start)>0) 
		swap_idx(mid,start);
    //mid程 startい end
	return;
}
/*
void quick_str_improve(int start, int end){

    if(start+10>end){
        insert(start,end);
        return;
    }
    
        threenumber(start,end);//start琌 start middle end ぇい计
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
*/