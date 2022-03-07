build: main.o stack.o stack_test.o
	gcc -g main.o stack.o stack_test.o
	./a.out

main.o: main.c
	gcc -c -g main.c

stack.o: stack.c
	gcc -c -g stack.c

stack_test.o: stack_test.c
	gcc -c -g stack_test.c


clean: 
	rm stack.o stack_test.o main.o ./a.out
