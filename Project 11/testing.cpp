#include <iostream>
using namespace std;

#include "3-ListT.h"

int main() {
//Static list
    ListT lst;

    for (int i = 0; i < 5; i++)
    {
        lst.PutItemH(5);
    }

    cout << "list before: " << endl;
    lst.Print();

    cout << "list empty status: " << lst.IsEmpty() << endl;



    cout << "list after: " << endl;
    cout << "nodes found: " << lst.FindItem(5) << endl;
    lst.Print();

    return 0;
}