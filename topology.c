#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
/*Run with 8 processes*/
void main (int argc, char *argv[])
{
  int rank;
  MPI_Comm vu;
  int dim[2], period[2], reorder;
  int coord[2], id;
  MPI_Init (&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  dim[0]=4;
  dim[1]=2;
  period[0]=1;
  period[1]=1;
  reorder=1;
  MPI_Cart_create(MPI_COMM_WORLD,2,dim,period,reorder,&vu);
  if(rank==5){
   MPI_Cart_coords(vu,rank,2,coord);
   printf("P:%d My coordinates are %d %d\n",rank,coord[0],coord[1]);
  } 
  MPI_Finalize();
}
