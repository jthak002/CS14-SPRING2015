/*
*
*Name: Jeet B Thakkar
*SID: 861189089
*Date: 4/21/15
*LAB 2
*/
#include <iostream>
#include<forward_list>
#include "lab2.h"

using namespace std;

bool isPrime(int i)
{
    if(i==0)
    {
        return false;
    }
    else if(i==1)
    {
        return false;
    }
    else
    {
        int ctr=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                ctr++;
                
            }
        }
        //cout<<ctr<<endl;
        if(ctr==2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int primeCount(forward_list<int> lst)
{
    if(lst.empty())
    {
        return 0;
    }
    else
    {
        bool result=isPrime(lst.front());
        if(result)
        {
            lst.pop_front();
            return 1+primeCount(lst);
        }
        else
        {
            lst.pop_front();
            return 0+primeCount(lst);
        }
    }
    return -1;// This is a test to see if the program works properly
}

template <typename T>
void listCopy(forward_list<T> L, forward_list <T>& P )
{
    if(L.empty())
    {
        return;
    }
    else
    {
        T temp=L.front();
        L.pop_front();
        listCopy(L,P);
        P.insert_after(P.size(), temp);
        return;
        
    }
}
template <typename T>
List<T>::List()
{
    head=0;
    tail=0;
}
template <typename T>
List<T>::~List()
{
    while(head!=0)
    {
        Node<T>* temp=head;
        head=head->next;
        delete temp;
    }
    tail=0;
    
}
template <typename T>
void List<T>::elementSwap(int pos)
{
    if(pos<1 || pos > (this->size()-1) )
    {
        cout<<"The position is out of Range"<<endl;
        return;
    }
    else if(pos==1)
    {
        Node<T>* exHead=this->head;
        Node<T>* nextToHead=exHead->next;
        exHead->next=nextToHead->next;
        nextToHead->next=exHead;
        head=nextToHead;
    }
    else
    {
        Node<T>* i=this->head;
        Node<T>* iprev=this->head;
        for(int j=0;j<pos-1;j++)
        {
            i=i->head;
            if(j>0)
            {
                iprev=iprev->next;
            }
        }
        Node<T>* nextToi=i->next;
        iprev->next=nextToi;
        i->next=nextToi->next;
        nextToi->next=i;
        if(pos==this->size()-1)
        {
            tail=i;
        }
    }
}
template <typename T>
int List<T>::size()
{
    if (head == 0)
    {
        return 0;
        
    }
    else
    {
        int ctr;
        for(Node<T>* i=this->head;i!=0;i=i->next)
        {
            ctr++;
        }
        return ctr;  
    }
}
template <typename T>
void List<T>::push_back(T value)
{
    if(head==0)
    {
        Node<T>* temp=new Node<T>(value);
        head=temp;
        tail=temp;
    }
    else
    {
        Node<T>* temp=new Node<T>(value);
        tail->next-temp;
        tail=temp;
    }
}
template <typename T>
void printLots(forward_list<T> L, forward_list<int> P)
{
    int k;
    for (auto i = P.begin(); i != P.end(); i++)
    {
        for (auto j = L.begin(); j != L.end(); j++)
        {
            if (k == *i)
            {
                cout << *j << ' ';
                k = 0;
                break;
            }
            k=k+1;
        }
    }
}

int main()
{
    forward_list<int> mylist = {1, 3, 3, 7, 80, 7, 15, 85, 52, 6};
    
    cout<<"checking for prime numbers in linked list: ";
    cout<<primeCount(mylist)<<endl;
    
    cout<<"Checking the List Class:"<<endl;
    
    

}

