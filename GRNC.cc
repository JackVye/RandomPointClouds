/* Gaussian Random Normalised Cube*/

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <random>

#define DIMMAX 15
#define LENGTHMAX 1280

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
    std::string Title = "GROC";        //initialise title of file saved to


    std::mt19937 engine(42);
    std::normal_distribution<> normal(0.5, 0.125); //center 0.5, SD 0.125

    for(int Length=128;Length<LENGTHMAX+1;Length+=128)
    {
        for(int Dim=1;Dim<DIMMAX+1;Dim++)
        {   
            Primer(Title,Dim,Length);
            for(int i=0;i<Dim;i++)
            {
                for(int j=0;j<Length;j++)
                {
                double Point = normal(engine);
                while(Point>1)
                {
                   Point =  normal(engine);
                }
                File << (Point -0.5)* 1/sqrt(Dim) << std::endl; //Save the random points
                }
            }
            File.close();
            
        }
    }
}


