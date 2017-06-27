#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Comm comm = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    int threads_num = omp_get_num_procs();
    omp_set_num_threads(threads_num);

    int j;
    #pragma omp parallel for schedule(static, 1)
    for (j = 0; j < threads_num; ++j) {
	printf("Thread #%d from %d threads from MPI-process #%d from "
	       "%d MPI-processes\n", omp_get_thread_num(), threads_num,
	       rank, size);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
