#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size, n, num;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = 1234;
		//printf("Master sending number\n");
		for(int i = 1; i < size; i++){
			MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
		printf("Number sent\n");
	}
	else{
		//printf("Slave receiving number\n");
		MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		printf("Process %d received number %d\n", rank, num);
	}

	MPI_Finalize();

	return 0;
}
