#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
using namespace std;


int main()
{

    ofstream out("test_item_true.txt");
    srand((int)time(0));
    for(int x=0;x<1000;x++)
    {
        out<<x<<"  "<<random(2)<<endl;

    }
    cout<<"1"<<endl;
    out.close();
    return 0;
}
