#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define MAX 10

int i = 12345;
double y = 1.23456;

void display_variables()
{
	double y = 4.352;
	printf("i=%d, y=%f\n", i,y);
}

struct arg_set {
	int only;
};

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return ( fib(n-1) + fib(n-2) );
}

void * start_routine(void *a) // This is the routine that the thread will execute --> it is the execution of the fib() function as before.
{
	int c,i=0;
	for (c = 1; c <= MAX; c++)
	{
		printf("%d\n", fib(i));
		i++;
	}
};

int main()
{
	struct arg_set args;
	args.only = 1;
	pthread_t t1;
	printf("i=%d, y=%f\n", i,y);
	display_variables();
	pthread_create(&t1, NULL, start_routine, (void *) &args); // this creates the thread and the start routing is start_routine function
	pthread_join(t1, NULL); // THE PROGRAM WILL NOT WORK WITHOUT THIS LINE!
	return 0;
}
