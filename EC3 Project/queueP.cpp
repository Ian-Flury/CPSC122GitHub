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

/* Description: This function puts adds a new item in the queue in
 *              sorted order (priority).
 * Inputs: itemtype newItem, the item that the user wants to add.
 * Outputs: none.
 */
void PQueue::Enqueue(itemType newItem)
{
    //if the length is 0, we can just Enqueue normally
    //just like we did in QueueI.
    if (length == 0) {
        QueueI::Enqueue(newItem);
    } else {
        //first check if the item at the head is of lower
        //priority than the newItem. If it is, insert at head.
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

/* Description: This function is used by Enqueue and returns a pointer
 *              to the node just before the place where the new node is
 *              to be inserted.
 * Inputs: itemtype newItem, the item that the user wants to add.
 * Outputs: node* follower, a pointer to the node where the new node will
 *          be inserted by Enqueue.
 */
node* PQueue::PtrTo(itemType newItem)
{
    //in this function, node* follower is just
    //behind target. When target->item is of lower priority
    //than newItem, follower (one node behind) will be
    //returned and the new node inserted just after.
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
	
