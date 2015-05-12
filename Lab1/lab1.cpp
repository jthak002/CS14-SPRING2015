//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1.cpp 
/// @brief Lab 1
///
/// @author Jeet Thakkar [jthak002@ucr.edu]
/// @date April 11, 2015
//  ================== END ASSESSMENT HEADER ===============
#include<iostream>
#include<list>
#include<string>
using namespace std;

template <typename T>
//typedef string T;
//typedef int T
//typedef double T
void mergeList(list<T>& l1, list <T>& l2)
{
    typename list<T> :: iterator i;
    typename list<T> :: iterator j;
    //This 'if statement' checks for size zero of list1 
    if(l1.size()==0)
    {
        for(i=l2.begin(); i != l2.end() ; i++)
        {
            l1.push_back(*i);
        }
        return;
    }
    //This if statement checks if the the size of list 2 is zero
    else if(l2.size()==0)
    {
        return;
    }
    //If the size of l2 is smaller than l1
    else if(l1.size()>=l2.size()-1)
    {
        i=l1.begin();
        i++;
        j=l2.begin();
        for(;i!=l1.end(),j!=l2.end();i++,j++)
        {
            l1.insert(i,*j);    
        }
    }
    //if the size of l2 is greater than l1
    else if(l1.size()<=l2.size())
    {
        i=l1.begin();
        i++;
        j=l2.begin();
        for(;i!=l1.end();i++,j++)
        {
            l1.insert(i,*j);
        }
        while(j!=l2.end())
        {
            l1.push_back(*j);
            j++;
        }
        return;
    }
}
template <typename T>
//typedef string T;
//typedef int T
//typedef double T
void mergeSortList(list<T>& l1, list <T>& l2)
{
    typename list<T> :: iterator i;
    typename list<T> :: iterator j;
    if(l1.size()==0)
    {
        for(i=l2.begin(); i != l2.end() ; i++)
        {
            l1.push_back(*i);
        }
    }
    else if(l1.size()>=l2.size()-1)
    {
        i=l1.begin();
        i++;
        j=l2.begin();
        for(;i!=l1.end(),j!=l2.end();i++,j++)
        {
            l1.insert(i,*j);    
        }
    }
    else if(l1.size()<=l2.size())
    {
        i=l1.begin();
        i++;
        j=l2.begin();
        for(;i!=l1.end();i++,j++)
        {
            l1.insert(i,*j);
        }
        while(j!=l2.end())
        {
            l1.push_back(*j);
            j++;
        }
    }
    //Sorting the Linked list 1 using selection sort
    T temp;
    typename list<T> :: iterator tempPos;
    for(i=l1.begin();i!=l1.end();i++)
    {
        tempPos=i;
        j=i;
        j++;
        for(;j!=l1.end();j++)
        {
            if(*tempPos>*j)
            {
                tempPos=j;
            }
        }
        temp=*i;
        *i=*tempPos;
        *tempPos=temp;
    }
    
}

template <typename T>
//typedef string T;
//typedef int T
//typedef double T
void rotateList(int x, list <T>& l1)
{
    //rotates the list by pop back and pysh back. each and every rotation 
    //consists of popping the last element and pushing it in front.
    for(int i=0;i<x;i++)
    {
        T temp=l1.front();
        l1.pop_front();
        l1.push_back(temp);
    }
        
}


int main()
{
    list <string> list1;
    list <string> list2;
    list1.push_back("apple");
    list1.push_back("cat");
    list1.push_back("elephant");
    list1.push_back("free");
    list2.push_back("bhutan");
    list2.push_back("chorizo");
    list2.push_back("rig");
    list2.push_back("freaky");
    list2.push_back("stealy");
    list2.push_back("darth");
    //mergeList(list1 , list2);
    mergeSortList(list1 , list2);
    list<string>::iterator i;
    
    for(i=list1.begin();i!=list1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    
    cout<<endl<<"Rotating the list by 3 elements: "<<endl;
    rotateList(3,list1);
    for(i=list1.begin();i!=list1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}