#include <iostream>
using namespace std;

#include "2-List.h"


//Class-related functions
//Constructor
List::List()
{       
 length = 0;
 head = nullptr;
}

//Destructor
List::~List()
{
    node* curNode = head;
    while (curNode != nullptr)
    {
        node* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
    head = nullptr;
    delete head;
}

//Head-related functions
void List::PutItemH(itemType item)
{
    node* temp = new node;
    temp->item = item;
    temp->next = head;
    head = temp;
    length++;
}

itemType List::GetItemH() const
{
    return head->item;
}

void List::DeleteItemH()
{
}


//General operations on the class

void List::Print() const
{
    node* cur = head;
    while (cur != nullptr)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
    cur = nullptr;
    delete cur;
}

bool List::IsEmpty() const
{
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}



