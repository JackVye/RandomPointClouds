/* Boost Random Cube of dimension 1 */


#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#define RANDLENGTH 100  //number of random points

boost::random::mt19937 gen;

int main(int argc, char *argv[])
{
    int Dim = atoi(argv[1]);            //initialise dimension of vectors
    int Length = atoi(argv[2]);           //Number of random points
    std::string Title = argv[3];        //initialise title of file saved to

    Title ="bin/" + Title + ".txt";
    const char* Title_Pointer=Title.c_str();
    std::ofstream File;
    File.open(Title_Pointer);


    for(int i=0;i<Dim;i++)
    {
        for(int j=0;j<Length;j++)
        {
            boost::random::uniform_int_distribution<>dist(0,INT_MAX);
            File << dist(gen)/(float)INT_MAX - 0.5 << std::endl;
        } 
    }       
    File.close();



}


