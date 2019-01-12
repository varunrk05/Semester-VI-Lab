#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size;
	MPI_Status status;
	int a[50];
	int n = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int buffer[100];
	int bufSize = 100;
	MPI_Buffer_attach(buffer, bufSize);

	if(rank == 0){
		printf("Enter %d elements:\n", size);
		for(int i = 0; i < size; i++){
			scanf("%d", &a[i]);
		}

		for(int i = 1; i < size; i++)
			MPI_Bsend(&a[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);

		printf("Process %d changed value from %d to %d\n", rank, a[0], a[0]*a[0]);
	}
	else if(rank % 2 == 0){
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		printf("Process %d changed value from %d to %d\n", rank, n, n*n);
	}
	else{
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		printf("Process %d changed value from %d to %d\n", rank, n, n*n*n);
	}

	MPI_Buffer_detach(&buffer, &bufSize);

	MPI_Finalize();
	return 0;
}
