//***********************************
//*Name: Jeet Thakkar
//*SID: 861189089
//*Date: May 18, 2015
//*Lab 5
//***********************************
#ifndef LAB6_H
#define LAB6_H
#include <iostream>
#include <cstdlib>
#include<utility>
#include<typeinfo>

using namespace std;

//This is an overloaded displayElement functionthat displays the elements of a list
//and not elements of a pair. since, pair and lists have different components
//they have to bedisplayed diffently
template<typename T1, typename T2>
void displayElement(pair<T1,T2> p)
{
    cout<<"("<<p.first<<","<<p.second<<") ";
}
//This is an overloaded displayElement functionthat displays the elements of a list
//and not elements of a pair. since, pair and lists have different components
//they have to bedisplayed diffently

template<typename T>
void displayElement(T element)
{
    cout<<element<<" ";
}

//Function to display the elements of the STL container that is sorted. 
//uses the overloaded displayElement functions to display pairs and list nodes 
//differently
template <typename L>
void display(L &l)
{
    for(auto i=l.begin();i!=l.end();++i)
    {
        displayElement(*i);
    }
    cout<<endl;
}

//This Function sorts the STL container using STL sort. The commented cout 
//statements have been used to debug the program and they do not have any 
//significance whatsoever
template <typename L>
void selectionsort(L &l)
{
    int moves=0;
    int copies=0;
    
    cout<<"pre:\t";
    display(l);
    typename L:: iterator i=l.begin();
    for(;i!=l.end();++i)
    {
        typename L::iterator min=i;
        typename L::iterator j=i;
        j++;
        for(;j!=l.end();++j)
        {
            //cout<<"Comparing min= "<<*min<<" to j= "<<*j<<endl; 
            if((*j)<(*min))
            {
                //cout<<"min= "<<*j<<endl;
                min=j;
            }
        }
        //cout<<"Swapping min: "<<endl;
        //cout<<"checking Min and i --> ";
        if(i!=min)
        {
            std::swap((*i),(*min));
            moves+=3;
        }
        //cout<<"*i= "<<*i<<" and *min= "<<*min<<endl;
        //cout<<"************Iteration complete**************"<<endl<<endl;
    }
    cout<<"post:\t";
    display(l);
    cout<<"copies = "<<copies<<", moves = "<<moves<<endl;
    return;
}
// This is a modified version of selection sort which displays the swaps as they
//happen in real time to demonstrate the working of a stable sort. It 
//differentiates betwee similar value elements by displaying the location in which
//they're stored, which are different for each element. Using location, we get
//to know the destination of each element during swap 
template <typename L>
void selectionsortDebug(L &l)
{
    int moves=0;
    int copies=0;
    
    cout<<"pre:\t";
    display(l);
    cout<<endl;
    typename L:: iterator i=l.begin();
    for(;i!=l.end();++i)
    {
        typename L::iterator min=i;
        typename L::iterator j=i;
        j++;
        for(;j!=l.end();++j)
        {
            //cout<<"Comparing min= "<<*min<<" to j= "<<*j<<endl; 
            if((*j)<(*min))
            {
                //cout<<"min= "<<*j<<endl;
                min=j;
            }
        }
        //cout<<"Swapping min: "<<endl;
        //cout<<"checking Min and i --> ";
        if(i!=min)
        {
            std::swap((*i),(*min));
            moves+=3;
            cout<<"Swapping value "<<(*i)<<" at location ["<<&(*min)<<"] with value "<<(*min)<<" at location ["<<&(*i)<<"] "<<endl;
        }
        //cout<<"*i= "<<*i<<" and *min= "<<*min<<endl;
        //cout<<"************Iteration complete**************"<<endl<<endl;
    }
    cout<<endl<<endl;
    cout<<"post:\t";
    display(l);
    cout<<"copies = "<<copies<<", moves = "<<moves<<endl;
    return;
}

#endif