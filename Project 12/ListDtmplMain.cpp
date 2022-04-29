#include <iostream>
using namespace std;

#include "ListDtempl.cpp"

int main()
{
//    ListD<string> lst;
//    lst.Insert("hello",1);
//    lst.Insert("world",2);
//    lst.Insert("testing",3);
//    lst.Insert("strings",4);
//    lst.PrintForward();

    ListD<int> lst;
    lst.Insert(69,1);
    lst.Insert(34,2);
    lst.Insert(24,3);
    lst.Insert(9,4);
    lst.PrintForward();

    return 0;
}

