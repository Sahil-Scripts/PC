#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int r, x = 100;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d: %d\n", r, x);

    MPI_Finalize();
    return 0;
}
