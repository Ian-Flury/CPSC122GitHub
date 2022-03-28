#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
    length = 0;
    head = nullptr;
    tail = nullptr;
}

ListT::~ListT()
{}

void ListT::PutItemH(itemType item)
{
}

void ListT::Print() const
{
    node* cur = head;
    while(cur != NULL)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}
