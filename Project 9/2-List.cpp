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
    node* temp = head->next;
    delete head;
    head = temp;
    length--;
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

int List::GetLength() const
{
    return length;
}

int List::Find(const itemType target) const
{
    int numberOfNodesWithItem = 0;
    if (length != 0) {
        node *cur = head;
        while (cur != NULL) {
            if (cur->item == target) {
                numberOfNodesWithItem++;
            }
            cur = cur->next;
        }
    }
    return numberOfNodesWithItem;
}

int List::DeleteItem(const itemType target)
{
    //there should be two loops, the first to check if the
    //target is at head.
    int numberNodesDeleted = 0;
    while (head->item == target)
    {
        DeleteItemH();
        numberNodesDeleted++;
    }

    node* prev = head;
    node* cur = head->next;

    while (cur != nullptr)
    {
        if (cur->item == target)
        {
            node* rmv = cur;
            cur = cur->next;
            prev->next = cur;
            rmv->next = nullptr;
            delete rmv;
            length--;
            numberNodesDeleted++;
        } else {
            prev = prev->next;
            cur = cur->next;
        }
    }
    return numberNodesDeleted;
}