/* Uniform Random(C++ inbuilt) Cube of dimension 1 */

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint

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
    std::string Title = "UROC";        //initialise title of file saved to


    for(int Length=128;Length<LENGTHMAX+1;Length+=128)
    {
        for(int Dim=1;Dim<DIMMAX+1;Dim++)
        {   
            Primer(Title,Dim,Length);
            for(int i=0;i<Dim;i++)
            {
                for(int j=0;j<Length;j++)
                {
                    double Rand = rand()/(float)INT_MAX - 0.5;//gen in [0,1]
                    File << Rand - 0.5 << std::endl;//map to [-.5,.5] and save
                } 
            } 
            File.close();      
        }
    }
}
