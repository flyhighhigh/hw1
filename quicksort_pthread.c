/*
void swap_all_p(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
*/

void quick_pthread(){
    
    pthread_t pid;
    int thread=12;
    int number_per_thread=data_cnt/thread;
    if(option==STR){
        int input[2]={0,data_cnt-1};
        //pthread_create(&pid,NULL,quick_str_p,(void*)input);
        return;
    }
    else{
        
        //pthread_barrier_init(&barrier, NULL, thread+1);
        //int input[thread][2];
        int temp,temp2=-1;
		for(int i=1;i<=thread;i++){
            temp = temp2+1;              //第一次是0
            temp2= i!=thread?number_per_thread*i:data_cnt-1;
            int *input=(int*)malloc(sizeof(int)*2);
            input[0]=temp;
            input[1]=temp2;
            
			pthread_create(&pid, NULL, work, (void*)input);
        }
 
		//pthread_barrier_wait(&barrier);
		//meger();
        
        //create_thread(0,data_cnt-1);
        /*
        int *input=(int*)malloc(sizeof(int)*2);
        input[0]=0;
        input[1]=data_cnt-1;
        pthread_create(&pid,NULL,quick_int_p,(void*)input);
        */
    }
    
    return;
}

        

void *work(void *arg)  //?程排序函?
{
        int *input=(int*)arg;
		int start=input[0];
        int end=input[1];
		quick_int(start,end);
		//pthread_barrier_wait(&barrier);
		pthread_exit(NULL);
}

void create_thread(int start,int end){
    if(start>=end)return;
    int *input=(int*)malloc(sizeof(int)*2);
    input[0]=start;
    input[1]=end;
    pthread_t pid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    pthread_create(&pid,NULL,quick_int_p,(void*)input);

    pthread_attr_destroy(&attr);
}
/*
void meger()        //最?合并函?
{
		long index[thread];
		for (int i = 0; i < thread; ++i)
		{
				index[i] = i * NumberOfSort;
		}
 
		for(long i = 0; i < MaxNumber; ++i)
		{
				long min_index;
				long min_num = MAX;
				for(int j = 0; j < thread; ++j)
				{
				    if((index[j] < (j + 1) * NumberOfSort)&& (array_a[index[j]] < min_num))
						{
								min_index = j;
								min_num = array_a[index[j]];
						}
				}
				array_b[i] = array_a[index[min_index]];
				index[min_index]++;
		}
}
*/
void *quick_int_p(void* arg){
    int *input=(int*)arg;
    int start=input[0];
    int end=input[1];
    //printf("start end %d %d\n",start,end);

    if(start<end){
        int mid=data_int[start];
        int left=start;
        int right=end;

        
        while (left < right){
            while(data_int[left]<=mid && left<end)
                left++;
            while(data_int[right]>mid)
                right--;
            if(left<right){
                swap_int(&data_int[left],&data_int[right]);
            }
        }
        swap_int(&data_int[start],&data_int[right]);
        //create_thread(start,right-1);
        //create_thread(right+1,end);

        
        int *input1=(int*)malloc(sizeof(int)*2);
        input1[0]=start;    input1[1]=right-1;
        int *input2=(int*)malloc(sizeof(int)*2);
        input2[0]=right+1;  input2[1]=end;
        
        pthread_t t1;
        pthread_attr_t attr;
        //pthread_attr_init(&attr);
        //pthread_attr_setdetachstate(&attr ,PTHREAD_CREATE_DETACHED);
        
        //pthread_mutex_unlock(&mutex);
        //pthread_create(&t1, NULL ,quick_int_p,(void*)input1);
        quick_int_p((void*)input1);        
        quick_int_p((void*)input2);
        
        //pthread_join(t1, NULL);
    }
}
/*
void *quick_str_p(void* input){
    int start=((int*)input)[0];
    int end=((int*)input)[1];

    if(start<end){
        char* mid=data_str[start];
        int left=start;
        int right=end;

        while (left < right){
            while(strcmp(data_str[left],mid)<=0 && left<end)
                left++;
            while(strcmp(data_str[right],mid)>0)
                right--;
            if(left<right){
                
                swap_str(&data_str[left],&data_str[right]);
            }
        }
        swap_str(&data_str[start],&data_str[right]);

        pthread_t t1,t2;
        int *input1=(int*)malloc(2*sizeof(int));
        int *input2=(int*)malloc(2*sizeof(int));
        input1[0]=start;    input1[1]=right-1;
        input2[0]=right+1;  input2[1]=end;

        pthread_create(&t1, NULL,quick_str_p,(void*)input1);
        pthread_create(&t2, NULL,quick_str_p,(void*)input2);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        free(input1);free(input2);
    }
    return NULL;
}
*/