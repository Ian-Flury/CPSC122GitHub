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
{
    node* curNode = head;
    //this loop will go through all of the nodes in the list,
    //and preform the necessary operations to delete them.
    while (curNode != nullptr)
    {
        node* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
    head = nullptr;
    delete head;
    tail = nullptr;
    delete tail;
}

void ListT::PutItemH(itemType item)
{
    //to put an item at the head of the list, create a new node
    //and assign the item of this node to the input item.
    //splice the node into the front of the list.
    node* temp = new node;
    temp->item = item;
    temp->next = head;
    head = temp;
    length++;
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

itemType ListT::GetItemH() const
{
    return head->item;
}

bool ListT::IsEmpty() const
{
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

int ListT::GetLength() const
{
    return length;
}

void ListT::DeleteItemH()
{
    node* temp = head->next;
    delete head;
    head = temp;
    length--;
}

int ListT::FindItem(const itemType target) const
{
    int numberOfNodesWithItem = 0;
    //first make sure the list isn't empty.
    if (length != 0) {
        node *cur = head;

        //loop through each node in the list.
        while (cur != nullptr) {
            if (cur->item == target) {
                numberOfNodesWithItem++;
            }
            //make sure to update cur
            cur = cur->next;
        }
    }
    return numberOfNodesWithItem;
}

int ListT::DeleteItem(const itemType target)
{
    //first take care of the case when the head contains
    //the target item. Loop in case the first few items
    //in the list are all targets.
    int numberNodesDeleted = 0;
    while (head->item == target)
    {
        DeleteItemH();
        numberNodesDeleted++;
    }

    //init the pointers that we will use to manipulate the
    //list.
    node* prev = head;
    node* cur = head->next;

    //at this point we know that the head of the
    //list is not the target.
    while (cur != nullptr)
    {
        //check if the current node's item is the target.
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

itemType ListT::GetItemT() const
{
    return tail->item;
}

void ListT::PutItemT(const itemType itemIn)
{
    if (length == 0)
    {
        node* temp = new node;
        temp->item = itemIn;
        temp->next = nullptr;

        head = temp;
        tail = temp;

        length++;
    } else {
        node* temp = new node;
        temp->item = itemIn;

        temp->next = nullptr;

        tail->next = temp;
        tail = temp;

        length++;
    }
}