//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queueP.h"

PQueue::PQueue() : QueueI()
{
    cout << "constructor priority queue" << endl;
}

PQueue::PQueue(PQueue* q) : QueueI(q)
{
}

void PQueue::Enqueue(itemType newItem)
{
    if (length == 0) {
        QueueI::Enqueue(newItem);
    } else {
        if (head->item > newItem) {
            PutItemH(newItem);
        } else {
            node* follower = PtrTo(newItem);
            node* newNode = new node;
            newNode->item = newItem;
            newNode->next = follower->next;
            follower->next = newNode;
            length++;
        }
    }
}

//will return a pointer to the node just before the
//node with a higher or same value. This means lower or
//same priority.
node* PQueue::PtrTo(itemType newItem)
{
    node* follower = head;
    node* target = head;

    while (true) {
        target = target->next;
        if (target == nullptr) {
            target = tail;
            return target;
        } else if (target->item > newItem) {
            return follower;
        } else {
            follower = follower->next;
        }
    }

}
	
