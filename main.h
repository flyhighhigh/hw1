#include<stdio.h>
#include<stdlib.h>     // srand(), rand()
#include<sys/time.h>   // gettimeofday()
#include<time.h>
#include<string.h>
#include<ctype.h>

#define data_cnt 10
#define max_str 100
#define INT 1
#define STR 2

int option;
char *data_str[data_cnt+5];
char *temp_str[data_cnt+5];
int data_int[data_cnt+5];
int temp_int[data_cnt+5];
int radix_list_int[10][data_cnt];
char *radix_list_str[52][data_cnt];

int firstpage();
void start();
void read_data();
void free_data();
void output(const char*);

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
void radixsort();
void radix_int();
void radix_str();
