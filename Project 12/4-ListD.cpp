#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2); //enter 1 more than u want to find.
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//TODO: will I lose points for not using the Delete function
//  in the Destructor? (once finished, redo the constructor to use
//  the Delete function).
ListD::~ListD()
{
    while (head != nullptr) {
        doubleNode* cur = head;
        head = head->next;
        cur->next = nullptr;
        cur->prev = nullptr;
        delete cur;
    }
    head = nullptr;
    tail = nullptr;
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::PrintBackward()
{
    doubleNode* cur = tail->prev;
    int i = 0;
    while (i < length)
    {
        cout << cur->item << endl;
        cur = cur->prev;
        i++;
    }
}

void ListD::Delete(int pos)
{
    if (length != 0) {
        doubleNode *rmv = FindPosition(pos+1);
        doubleNode *nextNode = rmv->next;
        doubleNode *prevNode = rmv->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        rmv->next = nullptr;
        rmv->prev = nullptr;
        delete rmv;

        length--;
    }
}

//You don't have to deal with the case where you have
//to loop through multiple items at the head of the list.
//don't use the Delete() function because it makes things
//slower.
int ListD::DeleteAll(itemType item)
{
    int numberNodesDeleted = 0;
    doubleNode* prv = head;
    doubleNode* cur = head->next;

    while (cur != nullptr)
    {
        if (cur->item == item)
        {
            doubleNode* rmv = cur;
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

//Use Selection Sort;
void ListD::Sort()
{
    doubleNode* cur = head;

    //traversing the whole list
    while (cur != nullptr)
    {
        doubleNode* currentMin = cur;
        doubleNode* cur2 = cur->next;
        //traversing the unsorted region of the list
        while (cur2 != nullptr) {
            if (currentMin->item > cur2->item) {
                currentMin = cur2;
            }
            cur2 = cur2->next;
        }

        itemType temp = cur->item;
        cur->item = currentMin->item;
        currentMin->item = temp;
        cur = cur->next;
    }
}
