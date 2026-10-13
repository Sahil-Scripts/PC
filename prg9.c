#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int r, x, s, p, mx, mn;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    x = r + 1;

    MPI_Reduce(&x, &s, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &p, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &mx, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &mn, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if (r == 0)
        printf("SUM=%d PROD=%d MAX=%d MIN=%d\n", s, p, mx, mn);

    MPI_Allreduce(&x, &s, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Process %d: SUM=%d\n", r, s);

    MPI_Finalize();
    return 0;
}
