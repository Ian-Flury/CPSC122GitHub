#include <iostream>
using namespace std;

#include "3-ListT.h"

int main() {
//Static list
    ListT lst;

    for (int i = 0; i < 5; i++)
    {
        lst.PutItemH(i);
    }
    cout << "list before: " << endl;
    lst.Print();





    cout << "list after: " << endl;
    cout << "nodes deleted: " << lst.DeleteItem(0) << endl;
    lst.Print();

    return 0;
}