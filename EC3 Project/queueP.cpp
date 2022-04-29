//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queueP.h"

PQueue::PQueue() : QueueI()
{
    cout << "constructor priority queue" << endl;
    Enqueue(55);
    Enqueue(1);
    Enqueue(36);
    Enqueue(54);
    Enqueue(14);
    Enqueue(32);
    Print();
    cout << "peeked: " << Peek() << endl;
    Print();
}

PQueue::PQueue(PQueue* q) : QueueI(q)
{
}

void PQueue::Enqueue(itemType newItem)
{
    if (length == 0) {
        QueueI::Enqueue(newItem);
    } else {
        node* nodeJBeforeInsert = PtrTo(newItem);
        node* temp = new node;
        temp->next = nodeJBeforeInsert->next;
        nodeJBeforeInsert->next = temp;
        temp->item = newItem;
        length++;
    }
}

//will return a pointer to the node just before the
//node with a higher or same value. This means lower or
//same priority.
node* PQueue::PtrTo(itemType newItem)
{
    cout << "funct reached" << endl;
    node* follower = head;
    node* target = head;
    if (head->item > newItem) {
        return head;
    }

    while (true) {
        if (target == nullptr) {
            return tail;
        }
        target = target->next;
        if (target->item > newItem) {
            return follower;
        } else {
            follower = follower->next;
        }
    }
}
	
