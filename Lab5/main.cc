//***********************************
//*Name: Jeet Thakkar
//*SID: 861189089
//*Date: May 1, 2015
//*Lab 4
//***********************************

#include "lab5.h"

using namespace std;

int main (){

    BST <int>test2;
    cout << "Testcase: 1" << endl;
    test2.insert(50);
    test2.insert(20);
    test2.insert(10);
    test2.insert(40);
    test2.insert(35);
    test2.insert(45);
    test2.insert(60);
    test2.insert(70);
    cout << "Part 1" << endl;
    test2.minCover();
    test2.displayMinCover();
    cout << "Part 2" << endl;
    test2.findSumPath(80);
    cout << "Part 3" << endl;
    test2.vertSum();
    cout << endl;
    return 0;
}
