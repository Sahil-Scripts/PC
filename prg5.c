#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int r, x = 10;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    if (r == 0) {
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Sent %d\n", x);
    } else if (r == 1) {
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received %d\n", x);
    }

    MPI_Finalize();
    return 0;
}
