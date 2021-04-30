#ifndef MAIN_H
#define MAIN_H

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
#define thread 12
#define number_per_thread data_cnt/thread

int option;
char *data_str_const[data_cnt+5];
char *data_str[data_cnt+5];

int data_int_const[data_cnt+5];
int data_int[data_cnt+5];

int radix_list_int[10][data_cnt];
char *radix_list_str[52][data_cnt];


int firstpage();
void start();
void read_data();
void free_data();
void output(const char*);
void reset();


pthread_barrier_t barrier;

#endif