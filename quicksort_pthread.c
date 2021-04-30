#include "main.h"
#include "quicksort.h"
#include "quicksort_improve.h"
#include "quicksort_pthread.h"

void quick_pthread(){

    pthread_t pid;

    pthread_barrier_init(&barrier, NULL, thread + 1);
    for (int i = 0; i < thread; i++) {
        pthread_create(&pid, NULL, work, (void *)(i));
    }
    pthread_barrier_wait(&barrier);

    if(option==INT){
        int *temp = (int *)malloc(sizeof(int) * data_cnt);
        merger_int(temp);
        free(temp);
    }
    if(option==STR){
        char **temp = (char**)malloc(sizeof(char*)*data_cnt);
        merger_str(temp);
        free(temp);
    }
}

void *work(void *arg) {
    int i=(int)arg;
    int start = (i)*number_per_thread;
    int end = i!=thread-1 ? (i+1)*number_per_thread-1 : data_cnt-1;
    //printf("start end %d %d\n",start,end);
    if(option==STR)
        quick_str_improve(start, end);
    else
        quick_int_improve(start,end);
    
    pthread_barrier_wait(&barrier);
}

void merger_int(int *temp){

    int index[thread];
    for (int i = 0; i < thread; i++) {
        index[i] = i * number_per_thread;
        //printf("idx %d\n",index[i]);
    }

    for (int i = 0; i < data_cnt; i++) {
        int min_thread=-1;
        for (int j = 0; j < thread; j++) {
            if(index[j]<(j+1)*number_per_thread){
                if(min_thread==-1)  min_thread=j;

                if(data_int[index[j]]<data_int[index[min_thread]]){
                    min_thread = j;
                }
            }
        }
        temp[i] = data_int[index[min_thread]];
        index[min_thread]++;
    }
    for(int i=0;i<data_cnt;i++)
        data_int[i]=temp[i];
}
void merger_str(char **temp){

    int index[thread];
    for (int i = 0; i < thread; i++) {
        index[i] = i * number_per_thread;
        //printf("idx %d\n",index[i]);
    }

    for (int i = 0; i < data_cnt; i++) {
        int min_thread=-1;
        for (int j = 0; j < thread; j++) {
            if(index[j]<(j+1)*number_per_thread){
                if(min_thread==-1)  min_thread=j;

                if(cmp_idx(index[j],index[min_thread])<0){
                    min_thread = j;
                }
            }
        }
        temp[i] = data_str[index[min_thread]];
        index[min_thread]++;
    }
    for(int i=0;i<data_cnt;i++)
        data_str[i]=temp[i];
}