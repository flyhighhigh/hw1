all:main.c quicksort.o mergesort.o radixsort.o quicksort_pthread.o quicksort_improve.o
	gcc main.c quicksort.o mergesort.o radixsort.o quicksort_pthread.o quicksort_improve.o -o gdb -pthread -g -Wall
	./gdb

quicksort.o:quicksort.c quicksort.h main.h
	gcc -c quicksort.c

mergesort.o:mergesort.c mergesort.h main.h
	gcc -c mergesort.c

radixsort.o:radixsort.c radixsort.h main.h
	gcc -c radixsort.c

quicksort_pthread.o:quicksort_pthread.c quicksort_pthread.h quicksort.h main.h
	gcc -c quicksort_pthread.c

quicksort_improve.o:quicksort_improve.c quicksort_improve.h quicksort.h main.h
	gcc -c quicksort_improve.c

clean:
	rm -f main quicksort.o mergesort.o radixsort.o quicksort_pthread.o quicksort_improve.o