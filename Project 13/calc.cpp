/* Name: Ian Flury
 * Class: CPSC 122, S02
 * Date: 4/22/2022
 * Assignment: Project 13
 * Notes: Simple calculator that implements the stack.
 */
#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    inFix = argvIn;
    postFix = argvIn;
    stk = new Stack;
    if (CheckParens() && CheckTokens()) {
        MakeValueTbl();
        Parse();
        postFix = new char[51];
        InFixToPostFix();
    } else {
        if (!CheckParens()) {
            cout << "Error Parens" << endl;
        }
        if (!CheckTokens()) {
            cout << "Error Tokens" << endl;
        }
        exit(EXIT_FAILURE);
    }
}

Calc::~Calc()
{
    delete[] inFix;
    delete[] stk;
    delete[] valueTbl;
    delete[] postFix;
}

//return true if each of the chars in the instring are
//valid characters. 1. uppercase letter. 2. digit (0-9). 3. left or right paren.
//4. one of the 4 arithmetic operations.
bool Calc::CheckTokens()
{
    //get the number of elements in argvIn.
    int length = getStringLength(inFix);
    bool valid = true;
    int asciiVal;

    for (int i = 0; i < length; i++) {
        //using the ascii value of the current input char,
        //check to see if the char is a digit (0-9).
        asciiVal = inFix[i] - 48;

        if (isupper(inFix[i])) {
            valid = true;
        } else if (inFix[i] == ')' || inFix[i] == '(') {
            valid = true;
        } else if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '/' || inFix[i] == '*') {
            valid = true;
        } else if (asciiVal < 10 && asciiVal > 0) {
            valid = true;
        } else {
            return false;
        }
    }
    return valid;
}

void Calc::MakeValueTbl()
{
    //allocate space.
    valueTbl = new int[26];
    //init the array with 0's.
    for (int i = 0; i < 26; i++) {
        valueTbl[i] = 0;
    }
    cout << endl;
}

void Calc::Parse()
{
    int index = 0;
    int indexFinal = 0;
    int tempD = 0;
    int tempV = 0;
    char *argIn = inFix;

    inFix = new char[101];
    for (int i = 0; argIn[i] != '\0'; i++)
    {
        tempD = 0;
        tempV = 0;
        if (argIn[i] == '(' || argIn[i] == ')')
        {
            inFix[index] = argIn[i];
            index++;
        }
        if (argIn[i] == '+' || argIn[i] == '-' || argIn[i] == '*' || argIn[i] == '/')
        {
            inFix[index] = argIn[i];
            index++;
        }
        if (argIn[i] >= '0' && argIn[i] <= '9')
        {
            indexFinal = FindLast(i);
            for (int j = i; j < indexFinal; j++)
            {
                tempD = argIn[j] - '0';
                tempV = tempV * 10;
                tempV = tempD + tempV;
            }
            valueTbl[valueIdx] = tempV;
            inFix[index] = valueIdx + 'A';
            index++;
            valueIdx++;
            i = indexFinal - 1;
        }
    }
}

int Calc::FindLast(int cur) {
    char *argIn = postFix;
    int i = cur;
    while (argIn[i] >= '0' && argIn[i] <= '9')
    {
        i++;
    }
    return i;
}

bool Calc::CheckParens()
{
    bool done = true;
    for (int i = 0; inFix[i] != '\0'; i++)
    {
        if (inFix[i] == '(')
        {
            stk->Push(1);
        }
        if (inFix[i] == ')')
        {
            if (stk->IsEmpty())
            {
                done = false;
            }
            else
            {
                stk->Pop();
            }
        }
    }
    if (done && stk->IsEmpty())
    {
        return true;
    }
    return false;
}

void Calc::DisplayInFix()
{
    cout << inFix << endl;
}

void Calc::InFixToPostFix()
{
    char* temp = new char[getStringLength(postFix)];
    int postIdx = 0;
    int inIdx = 0;
    while (temp[inIdx] != '\0') {

        if (temp[inIdx] >= 'A' && temp[inIdx] <= 'Z') {
            postFix[postIdx] = temp[inIdx];
            postIdx++;
        } else if (temp[inIdx] == '(' || temp[inIdx] == '*' || temp[inIdx] == '-'|| temp[inIdx] == '/' || temp[inIdx] == '+') {
            stk->Push(temp[inIdx]);
        } else {
            while (stk->Peek() != '\0') {
                postFix[postIdx] = stk->Peek();
                postIdx++;
                stk->Pop();
            }
            stk->Pop();
        }
        inIdx++;
    }
}

void Calc::DisplayPostFix()
{
    cout << postFix << endl;
}

int Calc::Evaluate()
{
    int A, B = 0;
    int result = 0;
    for (int i = 0; postFix[i] != '\0'; i++)
    {
        if (postFix[i] >= 'A' && postFix[i] <= 'Z')
        {
            stk->Push(valueTbl[postFix[i] - 'A']);
        }
        else
        {
            A = stk->Peek();
            stk->Pop();
            B = stk->Peek();
            stk->Pop();
            if (postFix[i] == '+')
            {
                stk->Push(A + B);
            }
            if (postFix[i] == '-')
            {
                stk->Push(B - A);
            }
            if (postFix[i] == '*')
            {
                stk->Push(A * B);
            }
            if (postFix[i] == '/')
            {
                stk->Push(B / A);
            }
        }
    }
    result = stk->Peek();
    return result;
}

int Calc::getStringLength(char *strIn)
{
    int i = 0;
    while (strIn[i] != '\0') {
        i++;
    }
    return i;
}