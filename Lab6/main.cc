//***********************************
//*Name: Jeet Thakkar
//*SID: 861189089
//*Date: May 18, 2015
//*Lab 5
//***********************************

#include "lab6.h"
#include <vector>
#include<utility>
#include <list>
#include<cstdlib>
using namespace std;

// main function contains multiple test harnesses to check for selection sort 
//in different containers. The presence of the rand function is to check, if it
//works for all values during multiple test runs. 
//NOTE to Future Jeet: DO NOT GET ALARMED BY THE PRESENCE OF RAND FUNCTION>ITS
//THERE JUST TO CHECK FOR test runs
int main()
{
    vector<int> a;
    a.push_back(49);
    a.push_back(69);
    a.push_back(6);
    a.push_back(9);
    a.push_back(43);
    a.push_back(-8);
    a.push_back(24);
   
    selectionsort(a);
    
    cout<<"Creating a list with 10 random integers and sorting them"<<endl;
    
    srand(time(NULL));
    list <int> l;
    
    for(int i=0;i<10;i++)
    {
        int c=static_cast<int>((rand()%32768));
        l.push_back(c);
    }
    
    selectionsort(l);
    
    //Test Harness working with arrays
    
    cout<<"**********TEST HARNESS FOR STABLE SORT*************"<<endl;
    vector<int> m;
    cout<<"Defining a vector with 10 random numbers"<<endl;
    for(int i=0;i<10;i++)
    {
        int c=static_cast<int>((rand()%32768));
        m.push_back(c);    
    }
    m.push_back(m.at(5));
    
    cout<<"Displaying the vector"<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"m["<<&m[i]<<"] = "<<m.at(i)<<endl;
    }
    cout<<endl;
    cout<<"Now sorting the vector..."<<endl;
    selectionsortDebug(m);
    cout<<endl;
    cout<<"Displaying the sorted vector"<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"m["<<&m[i]<<"] = "<<m.at(i)<<endl;
    }
    cout<<endl<<endl;
    
    cout<<"Now Creating a test harness to work with pairs: "<<endl;
    list<pair <int,int>> l2;
    l2.push_back(pair<int,int>(5,6));
    l2.push_back(pair<int,int>(10,2));
    l2.push_back(pair<int,int>(-3,1));
    l2.push_back(pair<int,int>(-8,0));
    ;l2.push_back(pair<int,int>(1,1));
    l2.push_back(pair<int,int>(1,2));
    l2.push_back(pair<int,int>(0,0));
    l2.push_back(pair<int,int>(10,2));
    l2.push_back(pair<int,int>(5,5));
    l2.push_back(pair<int,int>(5,-5));
    l2.push_back(pair<int,int>(0,0));
    l2.push_back(pair<int,int>(5,6));
    l2.push_back(pair<int,int>(10,2));
    
    selectionsort(l2);
    return 0;
    
}