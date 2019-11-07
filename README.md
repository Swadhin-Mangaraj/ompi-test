# MPI
MPI (Message Passing Interface) is a communication library API used for parallel programming using languages like C, C++, FORTRAN and Python (Source: C.S.R Prabhu. Grid and Cluster computing. Prentice Hall of India, Pages:111-113. New Delhi 2008). The MPI standard defines a message passing library with emphasis on portability and performance efficiency for application, library and compiler developers. It leaves the task of “problem decomposition, scheduling and mapping details and inter-processor communication setup” to the programmer (Source: Marco Danelutto. Efficient support for skeletons on workstation clusters. Parallel Processing Letters, 11(1):41-56, March 2001). MPI provides several  mechanisms to perform point-to-point and collective communication operations along with other notable features such as derived data types, persistent communication and group concept.

# Open MPI
MPI is only a standard with many existing implementations. For the examples in this repository, Open MPI (Source: OpenMPI Team, "Open MPI:Open Source High Performance Computing," Indiana University , 2004. [Online]. Available: http://www.open-mpi.org/) has been chosen which
represents mainly the merger among three well-known MPI implementations; FT-MPI, LA-MPI and LAM-MPI.

# ompi-test
This repository comprises of some very basic 'C' programming examples using Open MPI. The examples have been tested in Ubuntu 19.04.

<b>How to install OpenMPI on Ubuntu</b>
$ sudo apt-get install libopenmpi-dev openmpi-bin openmpi-doc

<b>How to compile an OpenMPI program</b>
$ mpicc basic_mpi.c -o basic_mpi

<b>How to execute the compiled OpenMPI program</b>
$ mpiexec -n 2 MPI_Hello

<b>Note</b>: "mpirun" can also be used instead of "mpiexec". In mpiexec command, the digit "2" represents the number of processor cores you can utilize to execute the example programs. 
