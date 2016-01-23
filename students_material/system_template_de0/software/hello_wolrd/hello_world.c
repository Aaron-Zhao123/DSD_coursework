/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <unistd.h>

//Test case 1
//#define step 5
//#define N 52

//Test case 2
//#define step 0.1
//#define N 2551

//Test case 3
#define step 0.001
#define N 255001

// generate the vector x and stores it in the memory 
void generateVector (float x[N])
{
	int i;
	x[0] = 0;
	for (i=1;i<N;i++) {
		x[i] = x[i-1] + step;
	}
}
float sumVector (float x[], int M){
	float y = 0;
	int i;
	for (i=0; i<N; i++) {
		y = y + x[i] + x[i] * x[i];
	}
	return y;
}

int main()
{
	printf("Task 2! \n");

	float x[N];
	float y;
	printf("Hi \n");
	generateVector(x);
	printf("Hi again \n");
	// timing
	char buf[50];
	clock_t exec_t1, exec_t2;
	
	exec_t1 = times(NULL); // get system time before starting the process
	
	// code START
	y = sumVector (x, N);
	
	//code END
	
	exec_t2 = times(NULL); // get system time after finishing the process
	//gcvt((exec_t2 - exec_t1), 20, buf);
	// gcvt convert a number to a string with decimal including a point, gcvt(value,number of digits,buffer)
	// buffer 8,9 character longer than number, this is the memory block that stores the number
	//alt_putstr("proc time = "); 	alt_putstr(buf);	alt_putstr("ticks\n");
	//printf could be used if memory is enough
	float resultf;
	resultf = exec_t2 - exec_t1;

	printf("Proc time = %d\n",(int)resultf);

	int i;
	for (i=0; i<10; i++)
		y = y/2.0;
	//gcvt((int)y, 20, buf);
	//alt_putstr("Result (divided by 1014) = "); alt_putstr(buf);
	printf("Result = %d\n",(int)y);
	return 0;
}
