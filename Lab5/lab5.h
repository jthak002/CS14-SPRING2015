
#ifndef LAB5_H
#define LAB5_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <queue>
#include <math.h>

using namespace std;
#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    class Node
    { // binary tree node
        public:
        Value value;
        Node* left;
        Node* right;
        bool cover;
        Node( const Value v = Value() )
        : value(v), left(nil), right(nil), cover(false){}
        Value& content()
        {
            return value;
        }
        bool isInternal() 
        {
            return left != nil && right != nil;
        }
        bool isExternal() 
        {
            return left != nil || right != nil;
            
        }
        bool isLeaf() 
        { 
            return left == nil && right == nil;
        }
        int height() 
        {
            if(this==0)
            {
                return 0;
            }
            else
            {
                int a = 0;
                int b = 0;
                a=1+left->height();
                b=1+right->height();
                return a>=b? a : b;
            }
            
        }
        int size()
        {
            if(isLeaf())
            {
                return 1;
            }
            else if(isInternal())
            {
                return 1 + this->left->size()+this->right->size();
            }
            else if(isExternal() && !isInternal())
            {
                if(left==nil)
                {
                    return 1 + right->size();
                }
                else if(right==nil)
                {
                    return 1 + left->size();
                }
            }
            return -1;
        }
        
    }; 
    // Node
    // const Node* nil; 
    // later nil will point to a sentinel node.
    
    int count;
    Node* root;
    vector<Node*> v;
    public:
    void preorder(Node* x)const
    {
        if(x->isLeaf())
        {
            cout<<x->content()<<" "<<endl;
            return;
        }
        else if(x->isExternal())
        {
            if(x->left==nil)
            {
                cout<<x->content()<<" ";
                cout<<endl;
                preorder(x->right);
                return;
            }
            else if(x->right==nil)
            {
                cout<<x->content()<<" ";
                cout<<endl;
                preorder(x->left);
                return;
            }
        }
        else if(x->isInternal())
        {
            cout<<x->content()<<" ";
            cout<<endl;
            preorder(x->left);
            preorder(x->right);
            return;
            
        }
    }
    void postorder(Node* x)const
    {
        if (x->left != nil){postorder(x->left);}
        if (x->right != nil){postorder(x->right);}
        cout << x->content() << endl;
    }
    void inorder(Node* x)const
    {
        if (x->left != nil){inorder(x->left);}
        cout << x->content() << endl;
        if (x->right != nil){inorder(x->right);}
    }
   void createqueue (queue<Value> &q, Node* x ){
        
        if (x->left != nil)
        {
            createqueue(q, x->left);
        }
        q.push(x->value);
        if (x->right != nil)
        {
            createqueue( q, x->right);
        }
    }
    int height()
    {
        if(root==nil)
        {
            return 0;
        }
        else
        {
            return root->height();
        }
    }
    int size() 
    {
        if(root==0)
        {
            return 0;
        }
        return root->size();
    }
    bool empty()
    { 
        return size() == 0;
    }
    void print_node( const Node* n )
    {
        // Print the node’s value.
        // FILL IN
        cout<<n->content()<<endl;
    }
    void printnode( Node* n ) const
    {
        // Print the node’s value.
        // FILL IN
        cout<<n->content();
    }
    
    bool search ( Value x )
    {
        return searchHelper(x,root);
    }
    bool searchHelper(Value x, Node* temp)
    {
        if(temp==0)
        {
            return false;
        }
        else if(temp->content()==x)
        {
            return true;
        }
        else
        {
            if(temp->content()>x)
            {
                return searchHelper(x,temp->left);
            }
            else if(temp->content()<x)
            {
                return searchHelper(x,temp->right);
            }
        }
        return false;
    }
    
    void preorder()const 
    {
        cout<<"preorder: \n";
        preorder(root);
    }
    void postorder()const
    {
        cout<<"postorder: \n";
        postorder(root);
    }
    void inorder()const
    {
    // Traverse and print the tree one Value per line in inorder.
    // FILL IN
        cout<<"inorder: \n";
        inorder(root);
    }
    Value& operator[] (int n) {
        // returns reference to the value field of the n-th Node. 
        // FILL IN
        queue<Value> q;
        createqueue (q,root);
        for (int i = 0; i < n; i++){
            //cout << temp.front();
            q.pop();
        }
        Node* newptr = new Node(q.front());
        return newptr->value;
    }
    
    BST() : count(0), root(nil) {}
    
    void insert( Value X )
    {
        root = insert( X, root ); 
    }
        Node* insert( Value X, Node* T ) 
        {
        // The normal binary-tree insertion procedure ...
        if ( T == nil )
        {
            T = new Node( X ); // the only place that T gets updated.
        } 
        else if ( X < T->value )
        {
            T->left = insert( X, T->left );
        } 
        else if ( X > T->value ) 
        {
            T->right = insert( X, T->right );
        } 
        else 
        {
            T->value = X;
        }
    // later, rebalancing code will be installed here
    return T;
    }
    
    void remove( Value X ) 
    {
        root = remove( X, root ); 
        
    }
    Node* remove( Value X, Node*& T )
    {
    // The normal binary-tree removal procedure ...
    // Weiss’s code is faster but way more intricate.
        if ( T != nil ) 
        {
            if ( X > T->value ) 
            {
                T->right = remove( X, T->right );
            } 
            else if ( X < T->value ) 
            {
            T->left = remove( X, T->left );
            } 
            else 
            { 
                // X == T->value
                if ( T->right != nil )
                {
                    Node* x = T->right;
                    while ( x->left != nil ) 
                        x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                }
                else if ( T->left != nil )
                {
                    Node* x = T->left;
                    while ( x->right != nil )
                        x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove( T->value, T->left );
                } 
                else 
                { 
                    // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void okay( ) 
    { 
        okay( root );
    }
    void okay( Node* T ) 
    {
        // diagnostic code can be installed here
        return;
    }
    void minCover()
    {
        minCover(root->left);
        minCover(root->right);
    }
    void minCover(Node *x) 
    {
        if (x == nil) 
        {
            return;
        }
        minCover(x->left);
        if (x->size() > 1) 
        {
            v.push_back(x);
            x->cover = true;
        }
        minCover(x->right);
    }
    void displayMinCover() 
    {
        int i;
        for (i = 0; i < v.size(); i++)
        {
            cout << v.at(i)->value << ' ';
        
        }
        cout << endl << i << endl;
    }
    void printSum(int temp[], int sz)
    {
        for(int i = 1; i <= sz; i++) 
        {
            for (int y = i + 1; y <= sz; y++) 
            {
                if (temp[y] > temp[i])
                {
                    int temp2 = temp[i];
                    temp[i] = temp[y];
                    temp[y] = temp2;
                }
            }
        }
        for (int x = sz; x > 0; x--)
        {
            cout << temp[x] << ' ';
        }
        cout << endl;
    }
        
    void findSumPath(Node* n, int sum, int array1[], int x, bool &boolvar)
    {
        // finds best path
        if (n == nil)
        {
            return;
        }
        array1[++x] = n->value; 
        if (n->isLeaf())
        {
            int num = 0;
            //int x;
            for (int i = 1; i <= x; i++)
            {
                num = num + array1[i];
            }
            if (num == sum)
            { // the path is found
                boolvar = true; 
                printSum(array1, x);
            }
            x = 1;
        }
        if (!boolvar)
        {
            findSumPath(n->left, sum, array1, x, boolvar);
            if (!boolvar)
            {
                findSumPath(n->right, sum, array1, x, boolvar);
            }
        }
    }
    void findSumPath(int sum)
    {
        if (root == nil)
        {
            cout << '0';
            return;
        }
        if (root->value == sum)
        {
                cout << root->value;
                return;
        }
        int temp = 0;
        int array1[1000];
        bool boolvar = false; 
        findSumPath(root, sum, array1, temp, boolvar);
        if (!boolvar)
        {
            cout << "Not Found!\n";
        }
    }
    void vertSum(Node* node, int i, std::map<int, int>& m)
    {
        m[i] = m[i] + node->value;
        if (node->right != nil)
        {
            i = i + 1;
            vertSum(node->right, i, m);
            i = i - 1;
        }
        if (node->left != nil)
        {
            i = i - 1;
            vertSum(node->left, i, m);
            i = i + 1;
        }
        return;
    }
    void displayVertSum(map<int, int> m)
    {
        map<int,int>::iterator mp = m.begin();
        for (; mp != m.end(); ++mp) 
        {
                cout << m[mp->first] << ' ';
        }
    }
    void vertSum()
    {
        if (root == nil)
        {
            cout << '0';
            return;
        }
        map<int, int> temp;
        vertSum(root, 0, temp);
        displayVertSum(temp);
    }
}; //END OF THE BINARY TREE CLASS
#endif