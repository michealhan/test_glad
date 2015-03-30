#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define random(x) (rand()%x)
using namespace std;


int main()
{
    srand((unsigned)time(0));
    double item_read[1000],person_read[50],item_true[1000];
    ifstream in1("test_person.txt");
    ifstream in2("test_item.txt");
    ifstream in3("test_item_true.txt");
    ofstream out("test_item_person.txt");
    //=======================================================================================================================
    char buffer[256];
    double b,c;
    int a,counter;
    counter=0;
    while(!in1.eof())
    {
        in1.getline(buffer,50);
        sscanf(buffer,"%d %lf",&a,&b);
        cout<<a<<" "<<b<<endl;
        person_read[a]=b;
        //cout<<a<<" "<<b<<endl;
        counter++;
    }
    cout<<person_read[0]<<endl;
    cout<<"1111111"<<endl;
    //==========================================================================================================================
    counter=0;
    while(!in2.eof())
    {
        in2.getline(buffer,50);
        sscanf(buffer,"%d %lf",&a,&b);
        item_read[a]=b;
        //cout<<a<<" "<<b<<endl;
        counter++;
    }
    cout<<"2222222"<<endl;
    //==========================================================================================================================
    counter=0;
    while(!in3.eof())
    {
        in3.getline(buffer,50);
        sscanf(buffer,"%d %lf",&a,&b);
        item_true[a]=b;
        //cout<<a<<" "<<b<<endl;
        counter++;
    }
    cout<<"3333333"<<endl;
    //==========================================================================================================================
    double true_para;
    for (int j=0;j<1000;j++)
    {
        for (int i=0;i<50;i++)
        {
              true_para=1/(1+exp(-person_read[i]*item_read[j]));
              int score;
              double judge;
              judge = true_para*10000;
              if (random(10000)<judge)
              {
                  score=item_true[j];
              }
              else
              {
                  score=1-item_true[j];
              }
              out<<j<<" "<<i<<" "<<score<<endl;
        }
    }
    /*ofstream out("test_item_person_score.txt");
    srand((int)time(0));
    out<<"i  "<<"zj"<<endl;
    for(int x=0;x<10000;x++)
    {
        out<<x<<"  "<<random(100)<<endl;

    }
    cout<<"1"<<endl;
    out.close();*/
    in1.close();
    in2.close();
    in3.close();
    out.close();
    return 0;
}
