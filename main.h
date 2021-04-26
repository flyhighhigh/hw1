#include<stdio.h>
#include<stdlib.h>     // srand(), rand()
#include<sys/time.h>   // gettimeofday()
#include<time.h>
#include<string.h>
#include<ctype.h>

#define data_cnt 1000000
#define max_str 100
#define INT 1
#define STR 2

int option;
char *data_str[data_cnt+5];
char *temp_str[data_cnt+5];
int data_int[data_cnt+5];
int temp_int[data_cnt+5];

int firstpage();
void start();
void read_data();
void free_data();
void output(char*);

void swap_int(int *,int *);
void swap_str(char **,char **);
//quick
void quicksort();
void quick_int(int,int);
void quick_str(int,int);
//merge
void mergesort();
void rec_merge_int(int left,int right);
void mergearray_int(int a,int a_end,int b,int b_end);
void rec_merge_str(int left,int right);
void mergearray_str(int a,int a_end,int b,int b_end);
//radix
