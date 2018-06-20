/* Gaussian Random Sphere of Radius 1 */

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <math.h>
#include <string.h>
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
    std::string Title = "GROS";        //initialise title of file saved to
    double *Cloud = (double*)malloc(LENGTHMAX*DIMMAX*sizeof(double));

    std::mt19937 engine(42);
    std::normal_distribution<> normal(0.5, 0.125); //center 0.5, SD 0.125

    for(int Length=128;Length<LENGTHMAX+1;Length+=128)
    {
        for(int Dim=1;Dim<DIMMAX+1;Dim++)
        {   
            Primer(Title,Dim,Length);
            for(int i=0;i<Length;i++)
            {

                double norm = 1.0;
                while(norm>0.5)
                {
                    double sum = 0.0;
                    for(int j=0;j<Dim;j++)
                    {
                        Cloud[i+j*Length]=normal(engine)-0.5;
                        sum = sum + Cloud[i+j*Length]*Cloud[i+j*Length];
                    }
                    norm = sqrt(sum);
                }

            }
            for(int i=0;i<Dim*Length;i++)
            {
                File << Cloud[i] << std::endl; //Save the random points
            }
            File.close();  
        }
    }
}


