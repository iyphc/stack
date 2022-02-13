build: main.o stack.o stack_test.o
	gcc main.o stack.o stack_test.o
	./a.exe

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

stack_test.o: stack_test.c
	gcc -c stack_test.c


clean: stack.o stack_test.o main.o
	rm stack.o stack_test.o main.o
