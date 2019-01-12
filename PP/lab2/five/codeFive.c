#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int n;

	if(rank == 0){
		printf("Enter a number:\n");
		scanf(" %d", &n);

		n += 1;
		MPI_Send(&n, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
		printf("Process %d sent the value %d to the process %d\n", rank, n, (rank + 1) % size);
		MPI_Recv(&n, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, &status);
		printf("Value %d received from process %d\n", n, size - 1);
	}
	else{
		MPI_Recv(&n, 1, MPI_INT, (rank - 1), 0, MPI_COMM_WORLD, &status);
		printf("Value %d received from process %d\n", n, rank - 1);
		n += 1;
		MPI_Send(&n, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
		printf("Process %d sent the value %d to the process %d\n", rank, n, (rank + 1) % size);
	}

	MPI_Finalize();
	return 0;
}
