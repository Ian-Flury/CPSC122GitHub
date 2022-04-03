/* Name: Ian Flury
 * Class: CPSC 122, Section 02
 * Assignment: Project 12 Doubly Linked List
 * Date Submitted: 4/3/2022
 * Notes: See the header and implementation files.
 */
#include <iostream>
using namespace std;

#include "4-ListD.cpp"

void TestInsert();
void TestCopyConstructor();
void TestPrintBackward();
void TestDelete();
void TestDeleteAll();
void TestSort();
void TestType();

int main()
{
    TestInsert();
    //TestCopyConstructor();
    //TestPrintBackward();
    //TestDelete();
    //TestDeleteAll();
    //TestSort();
    //TestType();

    return 0;
}

void TestType()
{
    cout << "This test will fill the list with "
            "a different type: (string)" << endl;
    ListD<string> lst;
    lst.Insert("Hello",1);
    lst.Insert("World",2);
    lst.PrintForward();
}

void TestSort()
{
    ListD<int> lst;
    lst.Insert(3,1);
    lst.Insert(4,1);
    lst.Insert(23,1);
    lst.Insert(1,1);
    lst.Insert(8,1);
    lst.Insert(56,1);
    lst.Insert(9,1);
    cout << "The unsorted list:" << endl;
    lst.PrintForward();
    cout << endl;
    cout << "The (selection) sorted list:" << endl;
    lst.Sort();
    lst.PrintForward();
}

void TestDeleteAll()
{
    ListD<int> lst;
    lst.Insert(2,1);
    lst.Insert(2,2);
    lst.Insert(4,3);
    lst.Insert(2,4);
    lst.Insert(3,5);
    lst.Insert(2,6);
    lst.PrintForward();
    int nodeDel = lst.DeleteAll(2);
    cout << "after delete: " << endl;
    lst.PrintForward();
    cout << endl << "there were " << nodeDel << " nodes deleted" << endl;
}

void TestDelete()
{
    ListD<int> lst;
    for (int i = 1; i <= 6; i++)
    {
        lst.Insert(i,i);
    }
    cout << "The list before deletion:" << endl;
    lst.PrintForward();
    cout << "The list after deleting item 3:" << endl;
    lst.Delete(3);
    lst.PrintForward();
}

void TestPrintBackward()
{
    ListD<int> lst;
    cout << "here is the list 'printed forward':" << endl;
    for (int i = 1; i <= 5; i++)
    {
        lst.Insert(i,i);
    }
    lst.PrintForward();

    cout << "here is the list 'printed backward':" << endl;
    lst.PrintBackward();
}

void TestInsert()
{

 ListD<int>* lst = new ListD<int>;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);
 lst->PrintForward();

 cout << "What's wrong with this test suite?" << endl;
 //answer: we've not tested the tail pointer
 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 //delete lst;
}

void TestCopyConstructor()
{
 ListD<int>* lst1 = new ListD<int>;
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD<int>* lst2(lst1);
 
 cout << "Traverse lst1" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse lst2" << endl;
 lst2->PrintForward();
 delete lst1;
}
