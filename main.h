#include<stdio.h>
#include<stdlib.h>     // srand(), rand()
#include<sys/time.h>   // gettimeofday()
#include<time.h>
#include<string.h>
#include<ctype.h>
#include <pthread.h>

#define data_cnt 1000000
#define max_str 100
#define sort_cnt 5
#define INT 1
#define STR 2

typedef struct{
    int i;
    char *s;
}Data;

int option;
char *data_str_const[data_cnt+5];
char *data_str[data_cnt+5];

int data_int_const[data_cnt+5];
int data_int[data_cnt+5];

int radix_list_int[10][data_cnt];
char *radix_list_str[52][data_cnt];

Data *data_all[data_cnt+5];
Data *data_all_const[data_cnt+5];

int firstpage();
void start();
void read_data();
void free_data();
void output(const char*);
void reset();

void swap_int(int *,int *);
void swap_str(char **,char **);
//quick
void quicksort();
void quick_int(int,int);
void quick_str(int,int);

void quick_pthread();
void *quick_int_p(void*);
void *quick_str_p(void*);
void *work(void*);
void create_thread(int start,int end);

void quicksort_improve();
void insert(int,int);
void quick_int_improve();
void threenumber(int,int);
//merge
void mergesort();
void rec_merge_int(int left,int right,int*);
void mergearray_int(int a,int a_end,int b,int b_end,int*);
void rec_merge_str(int left,int right,char**);
void mergearray_str(int a,int a_end,int b,int b_end,char**);

//char *temp_str[data_cnt+5];
//int temp_int[data_cnt+5];
//radix
void radixsort();
void radix_int();
void radix_str();

char sortname[sort_cnt][20]={"quick","merge","radix","quicksort_improve","p_quick"};
typedef void (*Fptr)();
Fptr functions[sort_cnt]={quicksort,mergesort,radixsort,quicksort_improve,quick_pthread};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier;