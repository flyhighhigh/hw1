#ifndef MERGE_H
#define MERGE_H

//merge
void mergesort();
void rec_merge_int(int left,int right,int*);
void mergearray_int(int a,int a_end,int b,int b_end,int*);
void rec_merge_str(int left,int right,char**);
void mergearray_str(int a,int a_end,int b,int b_end,char**);

#endif