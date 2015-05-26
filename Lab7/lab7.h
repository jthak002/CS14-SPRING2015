//***********************************
//*Name: Jeet Thakkar
//*SID: 861189089
//*Date: May 26, 2015
//*Lab 7
//***********************************
#ifndef LAB7_H
#define LAB7_H

#include<iostream>
#include<ctime>
#include<ratio>
#include<chrono>
#include<vector>
#include<set> 
#include<unordered_set>
#include<fstream>
#include<cstdlib>
#include<utility>


using namespace std;

void readWordList(vector<string> &v)
{
    ifstream input;
    string m="words.txt";
    input.open(m.c_str());
    
    if(!input.is_open())
    {
        cout<<"Error: in opening file"<<endl;
        return;
    }
    for(unsigned i=0;i<50000;i++)
    {
        string s;
        getline(input,s);
        v.push_back(s);
    }
    input.close();
    return;
}
void scrambleVector(vector<string> &v, unsigned index)
{
    srand(time(0));
    for(unsigned i=0;i<index;i++)
    {
        std::swap(v.at(i),v.at(static_cast<unsigned>(rand()%index) ));
    }
    return;
}
double timed_insert_set(vector<string> &v, set<string>& timedSet,unsigned index)
{
    std::chrono::steady_clock::time_point t1=std::chrono::steady_clock::now();
    for(unsigned i=0;i<index;i++)
    {
        timedSet.insert(v.at(i));
    }
    std::chrono::steady_clock::time_point t2=std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    double d=time_span.count();
    return d;
}
double timed_find_set(vector<string> &v, set<string>& timedSet,unsigned index)
{
    std::chrono::steady_clock::time_point t1=std::chrono::steady_clock::now();
    for(unsigned i=0;i<index;i++)
    {
        timedSet.find(v.at(i));
    }
    std::chrono::steady_clock::time_point t2=std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    double d=time_span.count();
    return d;
}
double timed_insert_uset(vector<string> &v, unordered_set<string>& timedUSet,unsigned index)
{
    std::chrono::steady_clock::time_point t1=std::chrono::steady_clock::now();
    for(unsigned i=0;i<index;i++)
    {
        timedUSet.insert(v.at(i));
    }
    std::chrono::steady_clock::time_point t2=std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    double d=time_span.count();
    return d;
}
double timed_find_uset(vector<string> &v, unordered_set<string> &timedUSet, unsigned index)
{
    std::chrono::steady_clock::time_point t1=std::chrono::steady_clock::now();
    for(unsigned i=0;i<index;i++)
    {
        timedUSet.find(v.at(i));
    }
    std::chrono::steady_clock::time_point t2=std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    double d=time_span.count();
    return d;
}
#endif