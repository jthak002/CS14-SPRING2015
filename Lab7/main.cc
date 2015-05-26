//***********************************
//*Name: Jeet Thakkar
//*SID: 861189089
//*Date: May 26, 2015
//*Lab 7
//***********************************
#include<iostream>
#include "lab7.h"

using namespace std;

int main()
{
    vector <string>v;
    readWordList(v);
    ofstream output;
    string m = "data.txt";
    output.open(m.c_str());
    if(!output.is_open())
    {
        cout<<"Error: Opening File::Output to \"data.txt\" terminated!"<<endl;
        return 1;
    }
    unsigned index=5000;
    for(unsigned i=1;i<=10;i++)
    {
        double insertSet=0.0;
        double findSet=0.0;
        double insertUSet=0.0;
        double findUSet=0.0;
        unordered_set<string> timedUSet;
        set<string> timedSet;
        for(int j=0;j<10;j++)
        {
            insertSet=insertSet + (timed_insert_set(v,timedSet,index)/index);
            findSet=findSet + (timed_find_set(v,timedSet,index)/index);
            insertUSet=insertUSet + (timed_insert_uset(v,timedUSet,index)/index);
            findUSet=findUSet + (timed_insert_uset(v,timedUSet,index)/index);
            timedSet.clear();
            timedUSet.clear();
            scrambleVector(v,index);
        }
        insertSet=insertSet/10;
        findSet=findSet/10;
        insertUSet=insertUSet/10;
        findUSet=findUSet/10;
        output<<index<<" "<<insertSet<<" "<<insertUSet<<" "<<findSet<<" "<<findUSet<<endl;
        index=index+5000;
    }
    output.close();
    return 0;
}