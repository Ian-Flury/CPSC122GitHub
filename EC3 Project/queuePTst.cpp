#include <iostream>
using namespace std;

#include "queueP.h"


int main()
{

    PQueue* que = new PQueue;
    for (int i = 5; i >= 0; i--)
        que->Enqueue(i);
    que->Print();
    cout << endl << endl;
    que->Dequeue();
    que->Print();
    cout << "Peaked: " << que->Peek() << endl;

    cout << endl << endl;

    que->Enqueue(69);
    que->Print();
    cout << endl << endl;

    que->Enqueue(23);
    que->Print();
    que->Dequeue();
    cout << endl << endl;
    que->Print();

    delete que;
 
}
