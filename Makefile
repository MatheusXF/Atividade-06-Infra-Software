all:
	gcc main.c -o main -lpthread

make run:
	./main


clean:
	$(RM) main
