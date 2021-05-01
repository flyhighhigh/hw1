#include <stdio.h>
#include "main.h"
#include "quicksort.h"
#include "mergesort.h"
#include "radixsort.h"
#include "quicksort_pthread.h"
#include "quicksort_improve.h"

char sortname[sort_cnt][20]={"quicksort","mergesort","radixsort","quick_impv","quick_pthd"};
typedef void (*Fptr)();
Fptr functions[sort_cnt]={quicksort,mergesort,radixsort,quicksort_improve,quick_pthread};

int main(int argc, char **argv) {

    printf("# Welcome to sorting wizard #\n");

    while (firstpage());

    printf("\n*** Thank You ***\n");
    printf("from flyhighhigh_vc :)\n\n");

    return 0;
}

int firstpage(){

    char input[100];

    printf("-------------\n");
    printf("What do you want to do?\n");

    printf("(s) sort string\n");
    printf("(i) sort int\n");
    printf("(h) do 100 times\n");
    printf("(x) exit\n");
    printf("Your option -> ");
    scanf("%s",input);

    if(*input=='s'){ option=STR;start(); }
    else if(*input=='i'){ option=INT;start(); }
    else if(*input=='h'){ custom(INT,100); custom(STR,100); }
    else if(*input=='x'||*input=='c')return 0;
    else printf("Invalid input!\n");
    return 1;
}

void start(){
    
    struct  timeval start;
    struct  timeval end;
    unsigned long timediff;

    generate();
    //read_data();
    for(int i=0;i<sort_cnt;i++){
        reset();
        printf("-------------\n");
        gettimeofday(&start, NULL);
            functions[i]();
        gettimeofday(&end, NULL);
        timediff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("performance of [%s] = %f sec\n",sortname[i],timediff/1000000.0);
        output(sortname[i]);
    }
    free_data();

}

void generate(){
    srand(time(NULL));

    FILE* fp;
    
    if(option==INT){
        printf("INT data generating ...\n");
        fp=fopen("dataset1.txt","w+t");
        if(fp==NULL){ printf("Failed to open [dataset1.txt]!!\n"); return; }

        for(int i=0;i<data_cnt;i++){
            int temp=rand();
            fprintf(fp,"%d\n",temp);
            data_int_const[i]=temp;
        }

    }
    else{
        printf("STR data generating ...\n");
        fp=fopen("dataset2.txt","w+t");
        if(fp==NULL){ printf("Failed to open [dataset2.txt]!!\n"); return; }

        char temp[max_str+5];

        for(int i=0;i<data_cnt;i++){
            for(int j=0;j<max_str;j++){
                int r=rand()%52;
                if(r<26){
                    fprintf(fp,"%c",'a'+r);
                    temp[j]='a'+r;
                }
                else{
                    fprintf(fp,"%c",'A'+r%26);
                    temp[j]='A'+r%26;
                }
            }
            fprintf(fp,"\n");
            temp[max_str]='\0';
            *(data_str_const+i)=strdup(temp);
        }
    }
    
    fclose(fp);
}
void reset(){
    if(option==STR)
        for(int i=0;i<data_cnt;i++)
            data_str[i]=data_str_const[i];
    if(option==INT)
        for(int i=0;i<data_cnt;i++)
            data_int[i]=data_int_const[i];
    //printf("reset finished!\n");
}

void output(const char* sort){

    FILE* fp;
    char *filename=(char*)calloc(100,sizeof(char));
    

    if(option==STR){
        strcat(filename,"output_str_");
        strcat(filename,sort);
        strcat(filename,".txt");
        fp=fopen(filename,"w+t");
        if(fp==NULL){ printf("Failed to open [%s]!!\n",filename); return; }

        for(int i=0;i<data_cnt;i++){
            fprintf(fp,"%s\n",*(data_str+i));
        }
    }
    if(option==INT){
        strcat(filename,"output_int_");
        strcat(filename,sort);
        strcat(filename,".txt");
        fp=fopen(filename,"w+t");
        if(fp==NULL){ printf("Failed to open [%s]!!\n",filename); return; }

        for(int i=0;i<data_cnt;i++){
            fprintf(fp,"%d\n",data_int[i]);
        }
    }
    fclose(fp);
    free(filename);

    printf("output [%s] data finished!!\n",sort);
}
void free_data(){
    if(option==STR){
        for(int i=0;i<data_cnt;i++)
            free(*(data_str_const+i));
        printf("free...\n");
    }   
}

void custom(int opt,int times){
    option=opt;

    struct  timeval start;
    struct  timeval end;
    unsigned long timediff[sort_cnt]={0};

    for(int k=0;k<times;k++){
        printf("--------------------\n");
        printf("test ( %d / %d )\n",k+1,times);
        
        generate();
        for(int i=0;i<sort_cnt;i++){
            reset();

            gettimeofday(&start, NULL);
            functions[i]();
            gettimeofday(&end, NULL);
            
            timediff[i]+=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
        }
        free_data();
    }
    printf("--------------------\n");
    printf("outputing performance result...\n");
    FILE* fp;
    
    if(option==INT)fp=fopen("performance_int.txt","w+t");
    if(option==STR)fp=fopen("performance_str.txt","w+t");
    if(fp==NULL){ printf("Failed to open [performance.txt]!!\n"); return; }

    for(int i=0;i<sort_cnt;i++){
        fprintf(fp,"[ %-10s ] sum = %11f sec,  avg = %9f sec\n",\
        sortname[i],timediff[i]/1000000.0,timediff[i]/100000000.0);
        printf("[ %-10s ] sum = %11f sec,  avg = %9f sec\n",\
        sortname[i],timediff[i]/1000000.0,timediff[i]/100000000.0);
    }
    
    fclose(fp);
}