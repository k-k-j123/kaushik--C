#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<time.h>

#define ARRAY_SiZE 1000
int main(int argc,char *argc){
	int rank;
	int local_array(ARRAY_SIZE);
	int local_sum=0;
	int global_sum=0;
	int i;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)+rank);
	for(i=0;i<ARRAY_SIZE;i++){
		local_array[i]=rand()%1000;
	}
	MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		printf("Global sum of 1000 random number :%d/n",global_sum);
	}
	MPI_Finalize();
	return 0;
}

