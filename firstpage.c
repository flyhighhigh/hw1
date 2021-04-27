#include "main.h"
#include "quicksort.c"
#include "mergesort.c"
#include "radixsort.c"

int firstpage(){

    char input[100];

    printf("-------------\n");
    printf("What do you want to do?\n");

    printf("(s) sort string\n");
    printf("(i) sort int\n");
    printf("(e) exit\n");
    printf("Your option -> ");
    scanf("%s",input);

    if(*input=='s'){
        option=STR;
        start();
    }
    else if(*input=='i'){
        option=INT;
        start();
    }
    else if(*input=='e'||*input=='c')return 0;
    else{
        printf("Invalid input!\n");
    }
    return 1;
}

void start(){

    srand(time(NULL));
    
    FILE* fp;

    if(option==INT){
        printf("[integers compare]\n");
        fp=fopen("dataset1.txt","w+t");

        printf("generating data...\n");
        for(int i=0;i<data_cnt;i++){
            fprintf(fp,"%d\n",rand());
        }
    }
    else{
        printf("[strings compare]\n");
        fp=fopen("dataset2.txt","w+t");

        printf("generating data...\n");
        for(int i=0;i<data_cnt;i++){
            for(int j=0;j<max_str;j++){
                int r=rand()%52;
                if(r<26)fprintf(fp,"%c",'a'+r);
                else fprintf(fp,"%c",'A'+r%26);
            }
            fprintf(fp,"\n");
        }
    }
    printf("finish generate!\n");
    fclose(fp);

    


    struct  timeval start;
    struct  timeval end;       
    unsigned long timediff;

   
    read_data();
    for(int i=0;i<sort_cnt;i++){
        reset();
        printf("-------------\n");
        gettimeofday(&start, NULL);
            functions[i]();
        gettimeofday(&end, NULL);
        timediff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("%ssort = %f sec\n",sortname[i],timediff/1000000.0);
        output(sortname[i]);
    }
    free_data();

}

void read_data(){
    printf("reading data...\n");

    FILE* fp;
    if(option==INT){
        fp=fopen("dataset1.txt","rt");
        /*
        int data;
        for(int i=0;i<data_cnt;i++){
            fscanf(fp,"%d",&data);
            data_int[i] = data;
        }
        */
    }
    else{
        fp=fopen("dataset2.txt","rt");
        /*
        char data[120];
        for(int i=0;i<data_cnt;i++){
            fscanf(fp,"%s",data);
            *(data_str+i) = strdup(data);
        }
        */
    }
    char data[120];
    for(int i=0;i<data_cnt;i++){
        fscanf(fp,"%s",data);
        *(data_str_const+i) = strdup(data);
    }
    fclose(fp);
    
}

void reset(){
    for(int i=0;i<data_cnt;i++)
        data_str[i]=data_str_const[i];
    printf("reset finished!\n");
}

void output(const char* sort){

    FILE* fp;
    char *filename=(char*)calloc(100,sizeof(char));
    

    if(option==STR){
        strcat(filename,"output_str_");
        strcat(filename,sort);
        strcat(filename,".txt");
        fp=fopen(filename,"w+t");
        for(int i=0;i<data_cnt;i++){
            fprintf(fp,"%s\n",*(data_str+i));
        }
    }
    else{
        strcat(filename,"output_int_");
        strcat(filename,sort);
        strcat(filename,".txt");
        fp=fopen(filename,"w+t");
        for(int i=0;i<data_cnt;i++){
            fprintf(fp,"%d\n",data_int[i]);
        }
    }
    fclose(fp);
    free(filename);

    printf("output [%ssort] data finished!!\n",sort);
}
void free_data(){
    printf("free...\n");
    if(option==STR)
        for(int i=0;i<data_cnt;i++)
            free(*(data_str_const+i));
}