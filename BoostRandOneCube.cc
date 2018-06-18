/* Boost Random Cube of dimension 1 */


#include <iostream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#define RANDLENGTH 100  //number of random points
#define DIM 3           //dimension of random point

boost::random::mt19937 gen;

int main(int argc, char *argv[])
{
    double *RandList = (double*)malloc(DIM*RANDLENGTH*sizeof(double));
    int Dim = atoi(argv[1]);
    std::string Title = argv[2];
    std::cout << Dim << std::endl;
    std::cout << Title << std::endl;
    

    for(int i=0;i<RANDLENGTH;i++)
    {
        for(int j=0;j<Dim;j++)
        {
            boost::random::uniform_int_distribution<>dist(0,INT_MAX);
            RandList[j*RANDLENGTH+i]=dist(gen)/(float)INT_MAX - 0.5;
        } 
    }       
    for(int i=0;i<Dim;i++)
    {
        std::cout << RandList[i*RANDLENGTH+5]<< "   ";
    }
    std::cout<<std::endl;
}


