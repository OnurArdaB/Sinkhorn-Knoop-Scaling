#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <math.h>       /* fabsf */
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

//Error check-----
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
  if (code != cudaSuccess) 
    {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
    }
}
//Error check-----
//This is a very good idea to wrap your calls with that function.. Otherwise you will not be able to see what is the error.
//Moreover, you may also want to look at how to use cuda-memcheck and cuda-gdb for debugging.

__global__ void scalesk(){
  
  //TO DO: GPU SCALE
  
}

void wrapper(int* adj, int* xadj, int* tadj, int* txadj, double* rv, double* cv, int* nov, int* nnz, int siter){
  
  printf("Wrapper here! \n");
  
  //TO DO: DRIVER CODE
  
  cudaEventCreate(&start);
  cudaEventRecord(start, 0);
  
  scalesk<<<NO_BLOCKS,NO_THREADS>>>();
  gpuErrchk( cudaDeviceSynchronize() );
  
  
  cudaEventCreate(&stop);
  cudaEventRecord(stop, 0);
  cudaEventSynchronize(stop);
  
  cudaEventElapsedTime(&elapsedTime, start, stop);
  printf("GPU scale took: %f s\n", elapsedTime/1000);
  
    
}

