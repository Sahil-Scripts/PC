#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int r, a[4] = {10, 20, 30, 40}, x;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    MPI_Scatter(a, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    x *= 2;

    MPI_Gather(&x, 1, MPI_INT, a, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (r == 0)
        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

    MPI_Finalize();
    return 0;
}
