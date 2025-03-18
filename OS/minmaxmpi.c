#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<time.h>
#include<limits.h>

#define Array_size 1000

int main(int argc,char *argv){
	int rand,size;
	int local_array(Array_size);
	int local_min,local_max;
	int global_min,global_max;
	int i;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)+rank);
	for(i=0;i<Array_size;i++){
		local_array[i]=rand();
	}
	local_min=local_array[0];
	local_max=local_array[0];
	for(i=1;i<Array_size;i++){
		if(local_array[i]<local_min){
			local_min=local_array[i];
		}
		if(local_array[i]>local_max){
			local_max=local_array[i];
		}
	}
	MPI_Reduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
	MPI_Reduce(&local_max,&global_max,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);

	if(rank==0){
		printf("Global minimum:%d/n",global_min);
		printf("Global maximum:%d/n",global_max);
	}
	MPI_Finalize();
	return 0;
}

