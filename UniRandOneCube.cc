/* Uniform Random(C++ inbuilt) Cube of dimension 1 */


#include <iostream>
#include <malloc.h>
#include <stdlib.h> //rand
#include <limits.h> //maxint
#include <fstream>
#include <string.h>


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
            double Rand = rand()/(float)INT_MAX - 0.5;
            File << Rand - 0.5 << std::endl;
        } 
    }       

}

