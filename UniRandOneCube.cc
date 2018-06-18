/* Uniform Random(C++ inbuilt) Cube of dimension 1 */


#include <iostream>
#include <malloc.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint

#define RANDLENGTH 100  //number of random points
#define DIM 3           //dimension of random point

int main()
{
    double *RandList = (double*)malloc(DIM*RANDLENGTH*sizeof(double));
    for(int i=0;i<RANDLENGTH;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            double Rand = rand()/(float)INT_MAX - 0.5;
            RandList[j*RANDLENGTH+i]=Rand;
            std::cout << i <<"     " << j << "     "<< RandList[j*RANDLENGTH+i] << std::endl;
        } 
    }       

    std::cout << RandList[5]<<" "<< RandList[RANDLENGTH+5] <<" "<< RandList[2*RANDLENGTH+5]<< std::endl;
}


# RandomPointClouds
# RandomPointClouds
