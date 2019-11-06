/****************************************************************************************/
/*	(c) Copyright 2011-2019								*/
/*	Swadhin K Mangaraj, swadhin.mangaraj@gmail.com					*/
/*											*/
/*	SPDX-License-Identifier: MIT							*/
/*											*/
/*	Description: This is a basic MPI program that prints the rank of each processor	*/
/*				and the total number of participating processors.	*/
/*	Input: None									*/
/*	Output: Identification number for each processor and total # of processors	*/
/*                                                                                      */
/****************************************************************************************/

#include <stdio.h>
#include <mpi.h>

static const int MASTER = 0;

int main (int argc, char **argv) 
{
	int number_of_processors, my_rank;

  	MPI_Init(&argc, &argv);   // starts the MPI execution environment
	MPI_Comm_size(MPI_COMM_WORLD, &number_of_processors);
  	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if(MASTER == my_rank)	// for the root rank
  	{
		printf("Total number of participating processes is ===> %d\n", number_of_processors); 
		printf("Hello, this is process: %d\n", my_rank);   // returns the rank of the master process
  	} 
	else		// for all non-root ranks
  	{	// since the following message is printed from different processor cores other than the master, 
		// OpenMPI does not guarantee any specific order for this message and the message from the master
		// in above if(...) block
		printf("Hello, this is process: %d\n", my_rank);   // returns the rank of the non-master processes
	}
 	
    
  	MPI_Finalize();   // terminates the MPI execution environment
	return 0;
}
