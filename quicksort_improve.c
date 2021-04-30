#include "main.h"
#include "quicksort.h"
#include "quicksort_improve.h"

void quicksort_improve(){
    if(option==STR)
        quick_str(0,data_cnt-1);
    else
        quick_int_improve(0,data_cnt-1);
    return;
}

void quick_int_improve(int start, int end){

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
        quick_int(start,right-1);
        quick_int(right+1,end);

}

void insert(int start,int end){
	int i,j;
	for(i=start+1;i<=end;i++){
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
    //盢start璹い计
	int mid=(start+end)/2;
 
	if (data_int[mid] > data_int[end])
		swap_int(&data_int[mid],&data_int[end]);

	if (data_int[start] > data_int[end])
		swap_int(&data_int[start],&data_int[end]);
    //endゲ程
	if (data_int[mid] > data_int[start]) 
		swap_int(&data_int[mid],&data_int[start]);
    //mid程 startい end
	return;
}