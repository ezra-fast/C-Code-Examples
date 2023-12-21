#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>

int main(int argc, char *argv[]) {

	int pid = atoi(argv[1]);

	struct timespec def;

	int quantum_calculation = sched_rr_get_interval(pid, &def);

	printf("Current Quantum: %ld", def.tv_nsec / 1000000); // this will show the quantum in milliseconds;

	return 0;
}
