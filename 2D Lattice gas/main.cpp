#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <cmath>
using namespace std;
// random numbers generator for probability in Metropolis
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0.0,1.0);
//parameters
#define N 20 // net size parameter
int net[N][N]; //define net as NxN array
int bc[N][2]; // pbc matrix
int x[N];
int y[N];
float W; // W/k_B T --- bond energy
int ncycle=10000; // number of cycles
int seed;

void initialise() // random initial spins
{
    // pbc
    for (int i=0; i<N; i++)
    { bc[i][0] = i+1;
      bc[i][1] = i-1;
    }
    bc[N-1][0] = 0;
    bc[0][1] = N-1;
    
    // lattice matrix
    for (int i=0; i<N; i++)
        {for (int j=0; j<N; j++)
            {//int r = rand()%2;  //generate 0 or 1 with equal probability

            //if ( r == 0)       // generate initial values 0 or 1
                {net[i][j] = rand()%2;}
        //    else
        //        {net[i][j] = 1;}
                cout << net[i][j] << endl;
            }
            }
    // x y coordinates of molecules on lattice
    
}

int main(int argc, char *argv[])
{
    // W parameter as command-line argument
    if (argc >2)
    {W = atof(argv[1]);
        seed = atof(argv[2]);
    srand(seed);   // seed for random number generator
    
    initialise();

}
else {cout << "Wrong arguments!";}
    return 0;
}
