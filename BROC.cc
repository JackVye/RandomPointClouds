/* Boost Random Cube of Boundary 1 */

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#define DIMMAX 15
#define LENGTHMAX 1280

boost::random::mt19937 gen;
std::ofstream File;

void Primer(std::string Name, int Dim, int Length)
{
    std::string Title = "bin/";
    Title+= Name;
    Title+= "_";
    Title+= std::to_string(Dim);
    Title+= "_";
    Title+= std::to_string(Length);
    std::cout <<"Writing file:     " << Title << std::endl;
    
    const char* Title_Pointer=Title.c_str();
    File.open(Title_Pointer);    
};

int main()
{

    std::string Title = "BROC";        //initialise title of file saved to

    for(int Length=128;Length<LENGTHMAX+1;Length+=128)
    {
        for(int Dim=1;Dim<DIMMAX+1;Dim++)
        {   
            Primer(Title,Dim,Length);
            for(int i=0;i<Dim;i++)
            {
                for(int j=0;j<Length;j++)
                {
                boost::random::uniform_int_distribution<>dist(0,INT_MAX);
                    //boosts version of rand()
                File << dist(gen)/(float)INT_MAX - 0.5 << std::endl;
                } 
            }       
            File.close();
        }
    }

}


