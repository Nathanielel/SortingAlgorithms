Client: stack.o binsort.o
	gcc -g -Wall -o Client binsort.o stack.o

StackTest: stack.o stackTest.o
	gcc -g -Wall -o StackTest stack.o stackTest.o

stack.o: stack.c stack.h
	gcc -c -g -Wall stack.c

stackTest.o: stackTest.c stack.h
	gcc -c -g -Wall stackTest.c

binsort.o: binsort.c stack.h
	gcc -c -g -Wall binsort.c

clean:
	rm -f *.o StackTest Client

check: Client
	valgrind --leak-check=full ./Client

checkStack: StackTest
	valgrind --leak-check=full ./StackTest
