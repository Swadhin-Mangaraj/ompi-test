# ompi-test
This repository comprises of some very basic 'C' programming examples using OpenMPI. The examples have been tested in Ubuntu 19.04.

# How to install OpenMPI on Ubuntu
$ sudo apt-get install libopenmpi-dev openmpi-bin openmpi-doc

# How to compile an OpenMPI program
$ mpicc basic_mpi.c -o basic_mpi

# How to execute the compiled OpenMPI program
$ mpiexec -n 2 MPI_Hello

Note: "mpirun" can also be used instead of "mpiexec". In mpiexec command, the digit "2" represents the number of processor cores you can utilize to execute the example programs. 
