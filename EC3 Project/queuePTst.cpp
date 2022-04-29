#include <iostream>
using namespace std;

#include "queueP.h"


int main()
{


    PQueue* que = new PQueue;
    for (int i = 5; i >= 0; i--)
        que->Enqueue(i);

    cout << endl << "The Priority Queue initially:" << endl;
    que->Print();

    cout << endl << "The Queue after a Dequeue operation:" << endl;
    que->Dequeue();
    que->Print();

    cout << endl << "Value obtained by peeking: " << que->Peek() << endl << endl;

    cout << "The queue after Enqueuing 3, a value that belongs in the";
    cout << " middle of the queue." << endl;
    que->Enqueue(3);
    que->Print();

    delete que;
 
}
