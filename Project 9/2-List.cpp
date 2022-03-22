/*
Name: Ian Flury
Class: CPSC 122, Section 1
Date Submitted: March 22, 2022
Assignment: Project 9 Writing a Linked List Class
Description: This file implements a linked list class.
Notes: See the class other two related files, 2-ListTst.cpp
       and 2-List.h
*/
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
}

//Head-related functions

/* Description: This function puts an item at the head
 *              of a list.
 * Inputs: itemType item, (the item to be placed at the
 *         beginning of the list).
 * Outputs: none.
 */
void List::PutItemH(itemType item)
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

/* Description: This function returns to the main program
 *              the value of the item at the head of the lst.
 * Inputs: none.
 * Outputs: itemType head->item (the item at the head of the lst).
 */
itemType List::GetItemH() const
{
    return head->item;
}

/* Description: This function deletes the item at the head
 *              of the lst.
 * Inputs: none.
 * Outputs: none.
 */
void List::DeleteItemH()
{
    node* temp = head->next;
    delete head;
    head = temp;
    length--;
}


//General operations on the class

/* Description: This function prints the contents of
 *              the list to the console.
 * Inputs: none.
 * Outputs: none.
 */
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

/* Description: This function returns a boolean value
 *              indicating whether the list is empty or
 *              not.
 * Inputs: none.
 * Outputs: none.
 */
bool List::IsEmpty() const
{
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

/* Description: This function returns the length of the list.
 * Inputs: none.
 * Outputs: none.
 */
int List::GetLength() const
{
    return length;
}

/* Description: This function searches through the list
 *              for a target value. It will count the
 *              number of places the target exits in
 *              the list.
 * Inputs: itemType target (the value we are looking for).
 * Outputs: returns the number of occurrences in the list.
 */
int List::Find(const itemType target) const
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

/* Description: This function deletes all the nodes in the
 *              list that contain the target item.
 * Inputs: itemType target (the value we are looking for).
 * Outputs: returns the number of nodes deleted.
 */
int List::DeleteItem(const itemType target)
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