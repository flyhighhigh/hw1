/*
void swap_all_p(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
*/

void quick_pthread(){
    int input[2]={0,data_cnt-1};
    pthread_t pid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    if(option==STR)
        pthread_create(&pid, &attr,quick_str_p,(void*)input);
    else{
        pthread_create(&pid, &attr,quick_int_p,(void*)input);
    }
        
    
    //pthread_join(t, NULL);
    return;
}

void *quick_int_p(void* input){
    int start=((int*)input)[0];
    int end=((int*)input)[1];

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

        int input1[2]={start,right-1};
        int input2[2]={right+1,end};
        
        pthread_t t1;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr ,PTHREAD_CREATE_DETACHED);

        pthread_create(&t1, &attr ,quick_int_p,(void*)input1);
        quick_int_p((void*)input2);
        
        //pthread_join(t1, NULL);
        
    }
    return NULL;
}

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