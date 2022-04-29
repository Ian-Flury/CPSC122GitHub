/*
    Name: Ian Flury
    Class: CPSC 122
    Assignment: Project 11, Linked list with tail pointer
    Date Submitted: 3/31/2022
    Notes: Please see the other two project files,
           3-List.cpp and 3-List.h
*/
#include <iostream>
using namespace std;

#include "3-ListT.h"


int main()
{
//Static list
    ListT lst;
    ListT* lst1 = new ListT;

    //Test of PutItemH() & Print()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 PutItemH & Print()*****" << endl;
    cout << "static test" << endl;
    cout << "output: a list holding the numbers 0-4" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    lst.Print();

    cout << "*****Test 2  PutItemH & Print()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: a list holding the numbers 0-4" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    lst1->Print();
    cout << "***************************************" << endl;
    //*/
    //End Test of PutItemH() & Print()
//-------------------------------------------------------------------------------
    //Test of IsEmpty()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 IsEmpty()*****" << endl;
    cout << "static test" << endl;
    cout << "output: 1 if empty, 0 if not." << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.IsEmpty() << endl;

    cout << "*****Test 2  IsEmpty()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: 1 if empty, 0 if not." << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->IsEmpty() << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of IsEmpty()
//-------------------------------------------------------------------------------
    //Test of GetLength()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 GetLength()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the length of the list" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.GetLength() << endl;

    cout << "*****Test 2  GetLength()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the length of the list" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->GetLength() << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of GetLength()
//-------------------------------------------------------------------------------
    //Test of GetItemH()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 GetItemH()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the item at the head of the list" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.GetItemH() << endl;

    cout << "*****Test 2  GetItemH()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the item at the head of the list" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->GetItemH() << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of GetItemH()
//-------------------------------------------------------------------------------
    //Test of DeleteItemH()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 DeleteItemH()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the new list without the old head item." << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << "before head item deletion:" << endl;
    lst.Print();
    lst.DeleteItemH();
    cout << "after head item deletion:" << endl;
    lst.Print();

    cout << "*****Test 2  DeleteItemH()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the new list without the old head item." << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << "before head item deletion:" << endl;
    lst1->Print();
    lst1->DeleteItemH();
    cout << "after head item deletion:" << endl;
    lst1->Print();
    cout << "***************************************" << endl;
    //*/
    //End Test of DeleteItemH()
//-------------------------------------------------------------------------------
    //Test of FindItem()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 FindItem()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes that store the target" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.FindItem(4) << endl;

    cout << "*****Test 2  FindItem()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes that store the target" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->FindItem(4) << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of FindItem()
//-------------------------------------------------------------------------------
    //Test of DeleteItem()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 DeleteItem()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.DeleteItem(2) << endl;

    cout << "*****Test 2  DeleteItem()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->DeleteItem(2) << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of DeleteItem()
//-------------------------------------------------------------------------------
    //Test of PutItemT()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 PutItemT()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    lst.Print();
    cout << "list after insert at tail:" << endl;
    lst.PutItemT(2);
    lst.Print();

    cout << "*****Test 2  PutItemT()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    lst1->Print();
    cout << endl;
    lst1->PutItemT(2);
    lst1->Print();
    cout << "***************************************" << endl;
    //*/
    //End Test of PutItemT()
//-------------------------------------------------------------------------------
    //Test of GetItemT()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 GetItemT()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    lst.Print();
    cout << "item: " << endl;
    cout << lst.GetItemT() << endl;

    cout << "*****Test 2  GetItemT()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    lst1->Print();
    cout << "item: " << endl;
    cout << lst1->GetItemT() << endl;
    cout << "***************************************" << endl;
    //*/
    //End Test of GetItemT()
//-------------------------------------------------------------------------------
    //Test of DeleteItemT()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 DeleteItemT()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    lst.PutItemH(3);
    lst.Print();
    cout << "list after DeleteItemT: " << endl;
    lst.DeleteItemT();
    lst.Print();

    cout << "*****Test 2  DeleteItemT()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    lst1->PutItemH(3);
    lst1->Print();
    cout << "list after DeleteItemT: " << endl;
    lst1->DeleteItemT();
    lst1->Print();
    cout << "***************************************" << endl;
    //*/
    //End Test of DeleteItemT()
//-------------------------------------------------------------------------------
    //Test of DeleteItem()
    ///*
    cout << "***************************************" << endl;
    cout << "*****Test 1 DeleteItem()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    lst.Print();
    cout << "list after DeleteItem: " << endl;
    lst.DeleteItem(3);
    lst.Print();

    cout << "*****Test 2  DeleteItem()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes deleted" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    lst1->Print();
    cout << "list after DeleteItem: " << endl;
    cout << "nodes deleted: " << lst1->DeleteItem(3) << endl;
    lst1->Print();
    cout << "***************************************" << endl;
    //*/
    //End Test of DeleteItem()
//-------------------------------------------------------------------------------

    delete lst1; //necessary to invoke destructor on dynamic list
    cout << endl;

    return 0;
}
