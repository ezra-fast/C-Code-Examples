// This program is made by Ezra Fast for OSI Lab 4 Part 4
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define _GNU_SOURCE
#include <unistd.h>

pid_t gettid(void); // needs to be declared for some reason

struct arg_set { int only; }; // declared for the thread

void * start_routine(void *a) { // This is the routine of the thread; it reads from STDIN and prints to STDOUT 
	printf("\n");
	pid_t self = gettid(); // this will not return the same thing as pthread_self()!
	printf("TID: %ld\n", self);
	char * output = malloc(sizeof(char) * 50);
	printf("Enter the text to be printed: ");
	fgets(output, sizeof(char) * 50, stdin);
	printf("Output: %s", output);
};

int main(void)
{
	pthread_t t1;
	struct arg_set args;
	args.only = 1;
	
	pthread_create(&t1, NULL, start_routine, (void *) &args);
	pthread_join(t1, NULL);

	return 0;
}
