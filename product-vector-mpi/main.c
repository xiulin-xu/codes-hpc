#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int lenArray=1000000;
    MPI_Comm comm = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    //initializing arrays randomly from 0~9
    int lenArrayThread=lenArray/(rank-1);
    int A[lenArrayThread], B[lenArrayThread],localProduct=0;
    randomize()
    int i;
    for(i=0;i<lenArrayThread;i++){
        A[i]=rand()%10;
        B[i]=rand()%10;
    }

    if(rank!=0)//working threads
    {
     for(i=0;i<lenArrayThread;i++)
     {
        localProduct+=A[i]*B[i];
     }
        MPI_Send(&localProduct,1,MPI_INT,0,1000,comm)
    }
    else{//master thread
        int sum=0;
        MPI_Recv(&localProduct,1,MPI_INT,0,1000,comm)
        sum+=localProduct;
    }
    MPI_Finalize();
    printf("Vector Product =", sum);
    return 0;
}
