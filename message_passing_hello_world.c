/****************************************************************************************/
/*	(c) Copyright 2011-2019								*/
/*	Swadhin K Mangaraj, swadhin.mangaraj@gmail.com					*/
/*											*/
/*	SPDX-License-Identifier: MIT							*/
/*											*/
/*	Description: This MPI program prints the "Hello World !!!" from each processor core.*/
/*	Input: None																			*/
/*	Output: A "Hello World !!!" message from all the processor cores.					*/
/*	Remarks: Since the non-master processor cores send their message text to the master	*/
/*			processor core and it is only the master that prints the message, the order	*/
/*			is always preserved i.e. first master processor's message is printed 		*/
/*			followed by the message from non-master processors.							*/ 
/*																						*/
/****************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <mpi.h>

static const int MASTER = 0;

int main (int argc, char **argv) 
{
	double startTime, endTime;
	int number_of_processors, my_rank, name_length, itr, tag=1;
	// The pre-defined constant MPI_MAX_PROCESSOR_NAME is the maximum length of name returned by MPI_GET_PROCESSOR_NAME
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	char greeting[MPI_MAX_PROCESSOR_NAME + 80];
	MPI_Status status;

  	MPI_Init(&argc, &argv);   // starts the MPI execution environment
	startTime = MPI_Wtime();
	MPI_Comm_size(MPI_COMM_WORLD, &number_of_processors);
  	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  	MPI_Get_processor_name(processor_name, &name_length);   // returns the name of the processing node
  	// The following print statement stores into the character array greeting, the given C string 
  	// in the desired format (as mentioned in the second argument).
  	sprintf(greeting, "Hello world from process %d of %d on %s", my_rank, number_of_processors, processor_name);
  	
  	if(MASTER == my_rank)
  	{
  		// if the process is the root, it receives the message from all other processes
  		printf("%s\n", greeting); 
  		for (itr=1 ; itr < number_of_processors ; itr++) 
  		{
			MPI_Recv(greeting,   		// starting adress of the receive buffer
					sizeof(greeting),  // size of the received data
					MPI_CHAR,           // type of the received
					itr,   				// source process from where data is received
					tag,   				// tag
					MPI_COMM_WORLD,     // communicator (the default one)  
					&status);   		// indicates the status of the receive operation
			printf("%s\n",greeting);
		}
  	}
  	else
  	{
		// if the process is not the root process, it sends the message to the root
  		MPI_Send(greeting,   			// starting address of the send buffer
  				strlen(greeting)+1,   	// size of the data to be sent
  				MPI_CHAR,    			// type of the data sent
  				0,           			// destination process to which the data is sent
  				tag,           			// tag
  				MPI_COMM_WORLD);     	// input communicator (default)

	}
	
	endTime = MPI_Wtime();
	//printf("Simulation took: %g secs\n", endTime  - startTime);		// Commented this line as simulation time is irrelevant in this context
  	MPI_Finalize();   // terminates the MPI execution environment
	
	return 0;
}
