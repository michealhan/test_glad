#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define random(x) (rand()%x)
using namespace std;
double gaussrand()
{
    static double V1, V2, S;
    static int phase = 0;
    double X;
    V1=0.0;
    V2=0.0;
    S=0.0;
    X=0.0;
    phase = 0;
    //srand(time(0));
    if ( phase == 0 ) {
        do {
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;

            V1 = 2 * U1 - 1;
            V2 = 2 * U2 - 1;
            S = V1 * V1 + V2 * V2;
        } while(S >= 1 || S == 0);

        X = V1 * sqrt(-2 * log(S) / S);
    } else
        X = V2 * sqrt(-2 * log(S) / S);

    phase = 1 - phase;

    return X;
}


int main()
{

    ofstream out("test_item.txt");
    //srand((int)time(0));
    for(int x=0;x<1000;x++)
    {
        out<<x<<"  "<<fabs(gaussrand()+1)<<endl;

    }
    cout<<"1"<<endl;
    out.close();
    return 0;
}
