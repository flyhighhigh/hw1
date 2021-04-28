all:main.c
	gcc main.c -o main -pthread
	./main
clean:
	rm -f main
