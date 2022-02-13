build: main.o stack.o stack_test.o
	gcc --coverage main.o stack.o stack_test.o
	#gcov main.c -m -b
	#gcov stack_test.c -m -b
	gcov stack.c -m -b
	#
	./a.exe

main.o: main.c
	gcc -c --coverage main.c

stack.o: stack.c
	gcc -c --coverage stack.c

stack_test.o: stack_test.c
	gcc -c --coverage stack_test.c

clean: stack.o stack_test.o main.o
	rm stack.o stack_test.o main.o
	rm stack.gcno stack_test.gcno main.gcno
	rm stack.c.gcov stack_test.c.gcov main.c.gcov