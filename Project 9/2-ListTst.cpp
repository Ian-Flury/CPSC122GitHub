/*
Name: Ian Flury
Class: CPSC 122, Section 1
Date Submitted: March 22, 2022
Assignment: Project 9 Writing a Linked List Class
Description: This project is a linked list class
             implementation with a number
             of useful public member functions.
Notes: See the class other two related files, 2-List.cpp
       and 2-List.h
*/
#include <iostream>
using namespace std;

#include "2-List.h"


int main()
{
    //Static list
    List lst;
    List* lst1 = new List;

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
    */
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
    */
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
    */
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
    */
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
    */
    //End Test of DeleteItemH()
//-------------------------------------------------------------------------------
    //Test of Find()
    /*
    cout << "***************************************" << endl;
    cout << "*****Test 1 Find()*****" << endl;
    cout << "static test" << endl;
    cout << "output: the number of nodes that store the target" << endl;
    for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
    cout << lst.Find(4) << endl;

    cout << "*****Test 2  Find()*****" << endl;
    cout << "dynamic test" << endl;
    cout << "output: the number of nodes that store the target" << endl;
    for (int i = 0; i < 5; i++)
        lst1->PutItemH(i);
    cout << lst1->Find(4) << endl;
    cout << "***************************************" << endl;
    */
    //End Test of Find()
//-------------------------------------------------------------------------------
    //Test of DeleteItem()
    ///*
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


    delete lst1; //necessary to invoke destructor on dynamic list
    cout << endl;

 return 0;
}
