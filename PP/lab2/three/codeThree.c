#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size;
	MPI_Status status;
	double t1, t2;
	int n;
	int a[20];
	int sum1 = 0, sum2 = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	t1 = MPI_Wtime();
	if(rank == 0){
		printf("Enter the size of the array:");
		scanf("%d", &n);
		printf("Enter the array: \n");
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(&a, n, MPI_INT, 1, 1, MPI_COMM_WORLD);

		for(int i = 0; i < n; i += 2)
			sum1 += a[i];

		MPI_Recv(&sum2, 1, MPI_INT, 1, 2, MPI_COMM_WORLD, &status);

		printf("The sum of the array is: %d\n", sum1 + sum2);
	}
	else{
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&a, n, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

		for(int i = 1; i < n; i += 2)
			sum2 += a[i];

		MPI_Send(&sum2, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
	}

	t2 = MPI_Wtime();
	printf("Time taken by process %d is: %1.2f\n", rank, t2 - t1);

	MPI_Finalize();
	return 0;
}
