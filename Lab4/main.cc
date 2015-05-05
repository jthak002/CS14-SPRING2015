/*
*Name: Jeet Thakkar
*SID: 861189089
*Date: May 1, 2015
*Lab 4
*/
#include "lab4.h"
#include<cstdlib>

using namespace std;

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Error: not enough arguments" << endl;
        exit(-1);
    }
    list<co_ord> t1;
    list<co_ord> t2;
    int k=atoi(argv[1]);
    cout<<"pre order values"<< endl;
    preorder(t1, k);
    print(t1);
    cout<<"post order values"<< endl;
    postorder(t2, k);
    print(t2);
    cout <<" the sorted list"<<endl;
    sorted(t2);
    return 0;
}