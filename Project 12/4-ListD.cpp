/* Name: Ian Flury
 * Class: CPSC 122, Section 02
 * Assignment: Project 12 Doubly Linked List
 * Date Submitted: 4/3/2022
 * Notes: See the header and test files.
 */
#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

//Constructor
template <typename T>
ListD<T>::ListD()
{
    InitializeVars();
}

//Copy Constructor
//Creates an exact copy of a pre-existing list.
template <typename T>
ListD<T>::ListD(ListD* lst)
{
    InitializeVars();
    //returns pointer to the first node, which is what we want here
    doubleNode<T>* cur = lst->FindPosition(2); //enter 1 more than u want to find.
    for (int i = 1; i <= lst->length; i++)
    {
        cout << cur->item << endl;
        Insert(cur->item,i);
        cur = cur->next;
    }
}

/* Description: This function initializes the head and tail
 *              dummy nodes.
 * Inputs: none.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::InitializeVars()
{
    length = 0;

//create dummy nodes;
    head = new doubleNode<T>;
    tail = new doubleNode<T>;

    //set values for head dummy node;
    head->prev = NULL;
    //head->item = INT_MIN;
    head->next = tail;

    //set values for tail dummy node;
    tail->prev = head;
    //tail->item = INT_MAX;
    tail->next = NULL;
}

/* Description: This function tears down the list and
 *              re-allocates any used memory.
 * Inputs: none.
 * Outputs: none.
 */
template <typename T>
ListD<T>::~ListD()
{
    //while there are still nodes, keep deleting
    //nodes.
    while (head != nullptr) {
        doubleNode<T>* cur = head;
        head = head->next;
        cur->next = nullptr;
        cur->prev = nullptr;
        delete cur;
    }
    head = nullptr;
    tail = nullptr;
}

/* Description: This function give a pointer to the node before
 *              the position given as an input. It is used in
 *              Insert() and Delete().
 *
 * Inputs: int pos, the position of the desired node in the list.
 * Outputs: a pointer to the node before the node at the input position.
 */
template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
    //Inserting at the tail is a special case.  It can be made much more efficient than
    //this.
    doubleNode<T>* cur = head;
    int i = 0;  //begin at the dummy node
    while (i < pos - 1)
    {
        cur = cur->next;
        i++;
    }
    return cur;
}

/* Description: This function puts new items into the list.
 *
 * Inputs: int pos, the position of where the item is to be inserted.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::Insert(T item, int pos)
{
    //when putting things at the end of the list, just use
    //the fact that we have a tail pointer to avoid traversing
    //the list every time you want to put a new item at the end.
    //this makes the operation orders of magnitude faster when
    //inserting at the end of a large list.
    if (pos == length + 1)
    {
        doubleNode<T>* temp = new doubleNode<T>;
        temp->item = item;
        doubleNode<T>* tailPrev = tail->prev;

        tailPrev->next = temp;
        temp->prev = tailPrev;

        temp->next = tail;
        tail->prev = temp;

        length++;
    } else {
        //new node goes between these two nodes
        doubleNode<T> *insertPtA = FindPosition(pos);
        doubleNode<T> *insertPtB = insertPtA->next;

        //create new node and set its values
        doubleNode<T> *tmp = new doubleNode<T>;
        tmp->prev = insertPtA;
        tmp->item = item;
        tmp->next = insertPtB;

        //set pointers for nodes before and after the insertion point
        insertPtA->next = tmp;
        insertPtB->prev = tmp;
        length++;
    }
}

/* Description: This function prints the list, first element first.
 *
 * Inputs: none.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::PrintForward()
{
    doubleNode<T>*  cur = head->next;

    int i = 0;
    while (i < length)
    {
        cout << cur->item << endl;
        cur = cur->next;
        i++;
    }
}

/* Description: This function prints the list last item first.
 * Inputs: none.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::PrintBackward()
{
    doubleNode<T>* cur = tail->prev;
    int i = 0;
    while (i < length)
    {
        cout << cur->item << endl;
        cur = cur->prev;
        i++;
    }
}

/* Description: This function deletes the item at a given position in the list.
 *
 * Inputs: int pos, the position of the node you want to delete.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::Delete(int pos)
{
    if (length != 0) {
        doubleNode<T> *rmv = FindPosition(pos+1);
        doubleNode<T> *nextNode = rmv->next;
        doubleNode<T> *prevNode = rmv->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        rmv->next = nullptr;
        rmv->prev = nullptr;
        delete rmv;

        length--;
    }
}

/* Description: This function give deletes all the instances of
 *              a specific item in the list.
 * Inputs: T item, the item you want to remove from the list.
 * Outputs: int, the number of nodes deleted from the list.
 */
template <typename T>
int ListD<T>::DeleteAll(T item)
{
    int numberNodesDeleted = 0;
    doubleNode<T>* prv = head;
    doubleNode<T>* cur = head->next;

    while (cur != nullptr)
    {
        if (cur->item == item)
        {
            doubleNode<T>* rmv = cur;
            cur = cur->next;
            cur->prev = prv;
            prv->next = cur;

            rmv->next = nullptr;
            rmv->prev = nullptr;
            delete rmv;
            length--;
            numberNodesDeleted++;
        } else {
            cur = cur->next;
            prv = prv->next;
        }
    }
    return numberNodesDeleted;
}

/* Description: This function give uses the selection sort
 *              algorithm to sort the list in ascending order.
 * Inputs: none.
 * Outputs: none.
 */
template <typename T>
void ListD<T>::Sort()
{
    doubleNode<T>* cur = head;

    //traversing the whole list
    while (cur != nullptr)
    {
        doubleNode<T>* currentMin = cur;
        doubleNode<T>* cur2 = cur->next;
        //traversing the unsorted region of the list
        while (cur2 != nullptr) {
            //if you find an item that is smaller than the current min,
            //set that node at the current min.
            if (currentMin->item > cur2->item) {
                currentMin = cur2;
            }
            cur2 = cur2->next;
        }

        //do the item swap.
        T temp = cur->item;
        cur->item = currentMin->item;
        currentMin->item = temp;
        cur = cur->next;
    }
}
