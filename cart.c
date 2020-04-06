#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
/*Run with 8 processes*/
void main (int argc, char *argv[])
{
  int rank;
  MPI_Comm vu;
  int dim[2], period[2], reorder;
  int coord[2], idr, idl, idu, coordn[2];
  MPI_Init (&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  dim[0]=4;
  dim[1]=2;
  period[0]=1;
  period[1]=1;
  reorder=1;
  MPI_Cart_create(MPI_COMM_WORLD,2,dim,period,reorder,&vu);
  MPI_Cart_coords(vu,rank,2,coord);
  /*Neighbour to the left*/
  coordn[0]=coord[0]-1;
  coordn[1]=coord[1];
  MPI_Cart_rank(vu, coordn, &idl);
  /*Neighbour to the right*/
  coordn[0]=coord[0]+1;
  MPI_Cart_rank(vu, coordn, &idr);	
  /*Y neighbour*/
  coordn[0]=coord[0];
  coordn[1]=coord[1]+1;  
  MPI_Cart_rank(vu, coordn, &idu); 
  printf("P:%d My neighbours in x direction are to the left %d and to the right %d, in the y direction %d\n", rank, idl, idr, idu);
  MPI_Finalize();
}
