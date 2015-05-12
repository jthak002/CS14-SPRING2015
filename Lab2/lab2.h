/*
*
*Name: Jeet B Thakkar
*SID: 861189089
*Date: 4/21/15
*LAB 2
*/


#ifndef LAB2_H
#define LAB2_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
struct Node
{
    Node* next;
    T value;
    Node(T value): value(value), next(0) {}
};
template <typename T>
class List
{
    private:
    Node<T>* head;
    Node<T>* tail;
    
    public:
    List();
    ~List();
    void push_back(T value);
    int size();
    void elementSwap(int pos); 
};
#endif

