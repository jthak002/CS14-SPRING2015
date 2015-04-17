#include<iostream>
#include<list>

using namespace std;

//template <typename T>
typedef int T;
void mergeList(list<T>& l1, list <T>& l2)
{
    list<T> :: iterator i;
    list<T> :: iterator j;
    if(l1.size()==0)
    {
        for(i=l2.begin(); i != l2.end() ; i++)
        {
            l1.push_back(*i);
        }
        return;
    }
    else if(l2.size()==0)
    {
        return;
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
        return;
    }
}
typedef int T;
void mergeSortList(list<T>& l1, list <T>& l2)
{
    list<T> :: iterator i;
    list<T> :: iterator j;
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
    //Sorting the Linked list 1
    T temp;
    list<T> :: iterator tempPos;
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

typedef int T;
void rotateList(int x, list <T>& l1)
{
    for(int i=0;i<x;i++)
    {
        T temp=l1.back();
        l1.pop_back();
        l1.push_front(temp);
    }
        
}

int main()
{
    list <int> list1;
    list <int> list2;
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(12);
    list1.push_back(56);
    list2.push_back(2);
    list2.push_back(45);
    list2.push_back(66);
    //mergeList(list1 , list2);
    mergeSortList(list1 , list2);
    list<int>::iterator i;
    
    for(i=list1.begin();i!=list1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    
}
