#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, a;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		a = 5;
		printf("Hello, world!!!(master)\n");
		printf("a = %d\n", a);
	}
	else{
		a = 3;
		printf("Hello world from %d\n", rank);
		printf("My value of 'a' is %d\n", a);
	}

	MPI_Finalize();
}



