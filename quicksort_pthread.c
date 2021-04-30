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

    int *temp = (int *)malloc(sizeof(int) * data_cnt);
    merger_p(temp);
    free(temp);

    return;
}

void *work(void *arg) {
    int i=(int)arg;
    int start = (i)*number_per_thread;
    int end = i!=thread-1 ? (i+1)*number_per_thread-1 : data_cnt-1;
    //printf("start end %d %d\n",start,end);
    if(option==STR)
        quick_str(start, end);
    else
        quick_int_improve(start,end);
    
    pthread_barrier_wait(&barrier);
}

void merger_p(int *temp){

    int index[thread];
    for (int i = 0; i < thread; i++) {
        index[i] = i * number_per_thread;
        printf("idx %d\n",index[i]);
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
