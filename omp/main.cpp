//#include "scale.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <math.h>       /* fabs */
#include <string.h>
#include <stdlib.h>


int parallel_sk(int *xadj, int *adj, int *txadj, int* tadj,
	     double *rv, double *cv, int nov, int siter) {


  double start = omp_get_wtime();
  
  //TO DO: implement the algorithm
  for(int i = 0; i < sizeof(xadj)-1;i++){
    printf("%d",i);
  }

  double end = omp_get_wtime();
  printf("%d", nov);
  //std::cout << nt << " Threads  --  "<<"Time: " <<  end-start << " s." << std::endl;
    
  return 1;
}


void* read_mtxbin(std::string bin_name){

  const char* fname = bin_name.c_str();
  FILE* bp;
  bp = fopen(fname, "rb");
  
  int* nov = new int;
  int* nnz = new int;
  
  fread(nov, sizeof(int), 1, bp);
  fread(nnz, sizeof(int), 1, bp);

  int* adj = new int[*nnz];
  int* xadj = new int[*nov];
  int* tadj = new int[*nnz];
  int* txadj = new int[*nov];

  fread(adj, sizeof(int), *nnz, bp);
  fread(xadj, sizeof(int), *nov + 1, bp);

  fread(tadj, sizeof(int), *nnz, bp);
  fread(txadj, sizeof(int), *nov + 1, bp);

  
  int inov = *nov + 1;

  double* rv = new double[inov];
  double* cv = new double[inov];
  
  parallel_sk(xadj, adj, txadj, tadj, rv, cv, *nov, 20); //or no_col

}


int main(int argc, char* argv[]){
  
  read_mtxbin(fname);
  
}
