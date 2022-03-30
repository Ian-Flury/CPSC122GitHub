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
    if (length == 0) {
        node *temp = new node;
        temp->item = item;
        temp->next = head;
        head = temp;
        tail = temp;
        length++;
    } else {
        node *temp = new node;
        temp->item = item;
        temp->next = head;
        head = temp;
        length++;
    }
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
    if (length == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    } else {
        node *temp = head->next;
        delete head;
        head = temp;
        length--;
    }
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
    int numNodesDeleted = 0;
    while (head->item == target) {

        DeleteItemH();
        numNodesDeleted++;

    }


    node* prev = head;
    node* cur = head->next;

    if (length != 0) {
        while (cur != nullptr) {
            if (cur->item == target) {
                if (length == 1) {
                    DeleteItemT();
                    numNodesDeleted++;
                } else {
                    node *rmv = cur;
                    cur = cur->next;
                    prev->next = cur;
                    rmv->next = nullptr;
                    delete rmv;
                    length--;
                    numNodesDeleted++;
                }
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
    }
    return numNodesDeleted;
}

itemType ListT::GetItemT() const
{
    if (length != 0) {
        return tail->item;
    } else {
        return -1;
    }
}

void ListT::PutItemT(const itemType itemIn)
{
    if (length == 0)
    {
        PutItemH(itemIn);
    } else {
        node* temp = new node;
        temp->item = itemIn;
        tail->next = temp;
        tail = temp;
        temp->next = nullptr;
        temp = nullptr;
        delete temp;
        length++;
    }
}

void ListT::DeleteItemT()
{
    if (length != 0) {
        if (length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length--;
        } else {
            node *prev = PtrTo();
            prev->next = nullptr;

            tail->next = nullptr;
            delete tail;

            tail = prev;
            length--;
        }
    }
}

//returns a pointer to the node just before the tail.
node* ListT::PtrTo()
{
    node* cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    return cur;
}