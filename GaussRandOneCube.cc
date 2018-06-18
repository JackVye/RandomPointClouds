/* Gaussian Random Cube of dimension 1 */

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <random>


int main(int argc, char *argv[])
{
    int Dim = atoi(argv[1]);            //initialise dimension of vectors
    int Length = atoi(argv[2]);           //Number of random points
    std::string Title = argv[3];        //initialise title of file saved to


    Title ="bin/" + Title + ".txt";
    const char* Title_Pointer=Title.c_str();
    std::ofstream File;
    File.open(Title_Pointer);

    std::mt19937 engine(42);
    std::normal_distribution<> normal(0.5, 0.125); //center 0.5, st deviation 0.125

    for(int i=0;i<Dim;i++)
    {
        for(int j=0;j<Length;j++)
        {
        File << normal(engine) - 0.5 << std::endl;
        }
    }


    File.close();



}


