#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Comm comm = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    int *i = NULL;
    *i = argc;

    printf("(%04d, %d): Hello, MPI world!\n", rank, size);

    MPI_Finalize();
    return 0;
}
