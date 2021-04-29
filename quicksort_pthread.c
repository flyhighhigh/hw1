/*
void swap_all_p(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
*/

void quick_pthread(){
    
    pthread_t pid;

    if(option==STR){
        int input[2]={0,data_cnt-1};
        //pthread_create(&pid,NULL,quick_str_p,(void*)input);
        return;
    }
    else{
        pthread_barrier_init(&barrier, NULL, thread+1);
		for(int i=0;i<thread;i++){
			pthread_create(&pid, NULL, work, (void*)(i));
        }
		pthread_barrier_wait(&barrier);
        
        int* temp=(int*)malloc(sizeof(int)*data_cnt);
		merger_p(temp);
        free(temp);
    }
    
    return;
}

void *work(void *arg) {
    int i=(int)arg;
    int start = (i)*number_per_thread;
    int end = i!=thread-1 ? (i+1)*number_per_thread-1 : data_cnt-1;
    quick_int(start, end);
    printf("start end %d %d\n", start, end);
    pthread_barrier_wait(&barrier);
    //pthread_exit(NULL);
}

void merger_p(int *temp){

    int index[thread];
    for (int i = 0; i < thread; i++) {
        index[i] = i * number_per_thread;
        printf("idx %d\n",index[i]);
    }

    for (int i = 0; i < data_cnt; i++) {
        int min_index;
        int min_num = 0x3f3f3f3f;
        for (int j = 0; j < thread; ++j) {
            if ((index[j] < (j + 1) * number_per_thread) && (data_int[index[j]] < min_num)) {
                min_index = j;
                min_num = data_int[index[j]];
            }
        }
        temp[i] = data_int[index[min_index]];
        index[min_index]++;
    }
    for(int i=0;i<data_cnt;i++)
        data_int[i]=temp[i];
    
}
