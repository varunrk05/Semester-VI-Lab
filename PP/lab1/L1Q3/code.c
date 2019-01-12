#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, x = 10 , y = 8;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	switch(rank){
		case 0: printf("The sum x + y is: %d\n", x + y);
				break;

		case 1: printf("The difference x - y is: %d\n", x - y);
				break;

		case 2: printf("The product x * y is: %d\n", x * y);
				break;

		case 3: printf("The quotient of x / y is: %d\n", x / y);
				break;

		default: printf("Incorrect case");
	}

	MPI_Finalize();
}
