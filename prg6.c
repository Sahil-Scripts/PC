#include<stdio.h>
#include<mpi.h>


int main(int argc, char **argv)
{
   int rank, data_src, data_recv;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   data_src=rank;


   if (rank==0)
   {
       MPI_Send(&data_src, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
       printf("Process %d sends data", rank);


       MPI_Recv(&data_recv, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
       printf("Process %d receives data", rank);


   }
   else
   {
       MPI_Send(&data_src, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
       print("Process %d sends data", rank);


       MPI_Recv(&data_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
       printf("PRocess %d receives data", rank)


   }


   printf("%d receives data %d", rank, data_recv);
   MPI_Finalize();
   return 0;
}

#Deadlock
#include<stdio.h>
#include<mpi.h>


int main(int argc, char** argv) {
int rank,size,data_src,data_recv;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);


data_src=rank;


if (rank ==0) {
MPI_Ssend(&data_src,1,MPI_INT,1,0,MPI_COMM_WORLD);
printf("Process %d sends\n",rank);
MPI_Recv(&data_recv,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("Process %d receives\n",rank);
}
else if (rank == 1) {
MPI_Ssend(&data_src,1,MPI_INT,0,0,MPI_COMM_WORLD);
printf("Process %d sends\n",rank);
MPI_Recv(&data_recv,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("Process %d receives\n",rank);
}
printf("Process %d receives data %d\n",rank,data_recv);
MPI_Finalize();
return 0;
}
