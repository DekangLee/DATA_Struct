#pragma once
#ifndef _LINKEDSTACKH_
#define _LINKEDSTACKH_
#include <iostream>
#include "linearList.hpp"
#include <sstream>
using namespace std;
template <class T>
class linkedStack : public stack<T>
{
public:
    linkedStack(int initialCapacity = 10)
    {
        this->stackTop = nullptr;
        this->stackSize = 0;
    }
    linkedStack(const linkedStack<T> &);
    ~linkedStack();
    bool empty() const
    {
        return this->stackSize == 0;
    }
    int size() const
    {
        return this->stackSize;
    }
    T &top()
    {
        if (this->stackSize == 0)
        {
            throw stackEmpty("Stack is empty!");
        }
        return this->stackTop->element;
    }
    void push(const T &theElement)
    {
        chainNode<T> *Node = new chainNode<T>(theElement);
        Node->next = this->stackTop;
        this->stackTop = Node;
        this->stackSize++;
    }
    void pop();
    void output() const;
    linkedStack<T> &operator=(const linkedStack<T> &);
    linkedStack<T> merge(const linkedStack<T> &);

private:
    chainNode<T> *stackTop;
    int stackSize;
};
template <class T>
linkedStack<T>::linkedStack(const linkedStack<T> &RightStack)
{
    this->stackSize = RightStack.stackSize;
    this->stackTop = nullptr;
    chainNode<T> *Node = RightStack.stackTop;
    if (Node != nullptr)
    {
        this->stackTop = new chainNode<T>(Node->element);
        this->stackTop->next = nullptr;
    }
    else
        return;
    Node = Node->next;
    chainNode<T> *preNode = this->stackTop;
    while (Node != nullptr)
    {
        chainNode<T> *newNode = new chainNode<T>(Node->element);
        preNode->next = newNode;
        preNode = preNode->next;
        Node = Node->next;
    }
    preNode->next = nullptr;
}
template <class T>
linkedStack<T> &linkedStack<T>::operator=(const linkedStack<T> &RightStack)
{
    while (this->stackTop != nullptr)
    {
        chainNode<T> *nextNode = this->stackTop->next;
        delete this->stackTop;
        this->stackTop = nextNode;
    }
    this->stackSize = RightStack.stackSize;
    this->stackTop = nullptr;
    chainNode<T> *Node = RightStack.stackTop;
    if (Node != nullptr)
    {
        this->stackTop = new chainNode<T>(Node->element);
        this->stackTop->next = nullptr;
    }
    else
        return *this;
    Node = Node->next;
    chainNode<T> *preNode = this->stackTop;
    while (Node != nullptr)
    {
        chainNode<T> *newNode = new chainNode<T>(Node->element);
        preNode->next = newNode;
        preNode = preNode->next;
        Node = Node->next;
    }
    preNode->next = nullptr;
    return *this;
}
template <class T>
linkedStack<T>::~linkedStack()
{
    while (this->stackTop != nullptr)
    {
        chainNode<T> *nextNode = this->stackTop->next;
        delete this->stackTop;
        this->stackTop = nextNode;
    }
    this->stackTop = nullptr;
}
template <class T>
void linkedStack<T>::pop()
{
    if (this->stackSize == 0)
    {
        throw stackEmpty("Stack is empty!");
    }
    chainNode<T> *nextNode = this->stackTop->next;
    delete this->stackTop;
    this->stackTop = nextNode;
    this->stackSize--;
}
template <class T>
void linkedStack<T>::output() const
{
    chainNode<T> *Node = this->stackTop;
    while (Node != nullptr)
    {
        cout << Node->element << endl;
        Node = Node->next;
    }
}
template <class T>
ostream &operator<<(ostream &cout, const linkedStack<T> &RightStack)
{
    RightStack.output();
    return cout;
}
template <class T>
linkedStack<T> linkedStack<T>::merge(const linkedStack<T> &RightStack)
{
    linkedStack<T> resStack;
    resStack.stackSize = this->stackSize + RightStack.stackSize;
    resStack.stackTop = nullptr;
    chainNode<T> *Node1;
    chainNode<T> *Node2;
    if (this->stackTop != nullptr && this->stackTop != nullptr)
    {
        Node1 = this->stackTop;
        Node2 = RightStack.stackTop;
        resStack.stackTop = new chainNode<T>(Node1->element);
        Node1 = Node1->next;
    }
    else if (this->stackTop != nullptr && RightStack.stackTop == nullptr)
    {
        Node1 = this->stackTop;
        Node2 = nullptr;
        resStack.stackTop = new chainNode<T>(Node1->element);
        Node1 = Node1->next;
    }
    else if (this->stackTop == nullptr && RightStack.stackTop != nullptr)
    {
        Node1 = nullptr;
        Node2 = RightStack.stackTop;
        resStack.stackTop = new chainNode<T>(Node2->element);
        Node2 = Node2->next;
    }
    else
    {
        return resStack;
    }
    chainNode<T> *preNode = resStack.stackTop;
    while (Node1 != nullptr)
    {
        chainNode<T> *newNode = new chainNode<T>(Node1->element);
        preNode->next = newNode;
        preNode = preNode->next;
        Node1 = Node1->next;
    }
    preNode->next = Node2;
    while (Node2 != nullptr)
    {
        chainNode<T> *newNode = new chainNode<T>(Node2->element);
        preNode->next = newNode;
        preNode = preNode->next;
        Node2 = Node2->next;
    }
    preNode->next = nullptr;
    resStack.stackSize = this->stackSize + RightStack.stackSize;
    return resStack;
}
#endif