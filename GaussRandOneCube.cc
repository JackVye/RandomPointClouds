/* Gaussian Random Cube of dimension 1 */

#include <iostream>
#include <malloc.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <random>

#define RANDLENGTH 100  //number of random points
#define DIM 3           //dimension of random point


int main(int argc, char *argv[])
{

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, INT_MAX);

    double *RandList = (double*)malloc(DIM*RANDLENGTH*sizeof(double));
    int Dim = atoi(argv[1]);
    std::string Title = argv[2];
    std::cout << Dim << std::endl;
    std::cout << Title << std::endl;

    for(int i=0;i<RANDLENGTH;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            double Rand = std::normal_distribution()/(float)INT_MAX 0.5;
            RandList[j*RANDLENGTH+i]=Rand;
            std::cout << i <<"     " << j << "     "<< RandList[j*RANDLENGTH+i] << std::endl;
        } 
    }       
    for(int i=0;i<Dim;i++)
    {
        std::cout << RandList[i*RANDLENGTH+5]<< "   ";
    }
    std::cout<<std::endl;
}


