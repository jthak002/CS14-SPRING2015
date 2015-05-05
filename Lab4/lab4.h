/*
*Name: Jeet Thakkar
*SID: 861189089
*Date: May 1, 2015
*Lab 4
*/
#ifndef LAB4_H
#define LAB4_H
#include <iostream>
#include <list>
#include <vector>
using namespace std;
struct co_ord
{
    int n1;
    int n2;
    co_ord( int n1val, int n2val ) : n1(n1val), n2(n2val)
    {
    }
};
typedef pair<int,int> T;

class priority_queue
{
    
    public:
    vector<T> in;
    
    T& front()
    { 
        return in.back(); 
    }
    
    void push(T input)
    {
    
        in.push_back(input);
        int i = in.size() -1;
        for (i = i; i != 0; i--)
        {
            if (in[i - 1].first + in[i - 1].second > in[i].second + in[i].first)
            {
                break;
            }
            swap(in[i], in[i-1]);
        }
    }
    
    void print()
    {
        int i = in.size()-1;
        while(i>=0)
        {
            cout << in.at(i).first <<' '<< in.at(i).second << endl;
            i--;
        }
    }
};

// Used same as assignment 3 of trees 
void preorderHelper(int first, int last, list<co_ord> &tree_list, int i)
{
    if (i < first + last)
    {
        return;
    }
    co_ord temp(first,last);
    tree_list.push_back(temp);
    preorderHelper((2*first)-last, first, tree_list, i);
    preorderHelper((2*first)+last, first, tree_list, i);
    preorderHelper(first + (2 * last), last, tree_list, i);
}
void postorderHelper(int first, int last, list<co_ord> &tree_list, int i)
{
    if (i < first+last)
    {
        return;
    }
    postorderHelper((2 * first) - last, first, tree_list, i);
    postorderHelper((2 * first) + last, first, tree_list, i);
    postorderHelper(first + (2 * last), last, tree_list, i);
    co_ord temp(first,last);
    tree_list.push_back(temp);
}
void preorder(list<co_ord> &tree_list, int i)
{
    preorderHelper(2, 1, tree_list, i);
    preorderHelper(3, 1, tree_list, i);
}
void postorder(list<co_ord> &tree_list, int i)
{
    postorderHelper(2, 1, tree_list, i);
    postorderHelper(3, 1, tree_list, i);
}
void sorted(list<co_ord> &tree_list)
{
    T temp;
    priority_queue p_queue;
    list<co_ord>::iterator start;
    for (start = tree_list.begin(); start != tree_list.end(); ++start){
        temp.first = (*start).n1;
        temp.second = (*start).n2;
        p_queue.push(temp);
    }
    p_queue.print();
}
void print(list<co_ord> tree_list)
{
    list<co_ord>::iterator start = tree_list.begin();
    for (; start != tree_list.end(); ++start)
    {
        cout << (*start).n1 << ' ' << (*start).n2 << endl;
    }
}
#endif