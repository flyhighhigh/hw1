all:main.c
	gcc main.c -o main -l pthread
	./main
clean:
	rm -f main
