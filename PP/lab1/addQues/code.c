#include "mpi.h"
#include <stdio.h>

int main(int argc, char * argv[]){
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int isPrime(int a){
		for(int i = 2; i <= a / 2; i++){
			if(a % i == 0)
				return 0;
		}
		return 1;
	}

	void printPrime(int x, int y){
		for(int i = x; i <= y; i++){
			if(isPrime(i))
				printf("%d ", i);
		}
		printf("\n");
	}

	if(rank)
		printPrime(51, 100);
	else
		printPrime(1, 50);

	MPI_Finalize();
	return 0;
}
