#ifndef _LINKEDQUEUEH_
#define _LINKEDQUEUEH_
#include <iostream>
#include "queue.hpp"
#include "myExpectation.h"
template <class T>
class chainNode
{
public:
    chainNode()
    {
    }
    chainNode(const T &element)
    {
        this->element = element;
    }
    T element;
    chainNode<T> *next;
};
template <class T>
class linkedQueue : public queue<T>
{
public:
    linkedQueue(int capacity = 10)
    {
        this->queueFront = new chainNode<T>;
        this->queueBack = nullptr;
        this->queueFront->next = this->queueBack;
        this->queueSize = 0;
    }
    linkedQueue(const linkedQueue<T> &rightQ)
    {
        this->queueSize = rightQ.queueSize;
        this->queueFront = new chainNode<T>;
        chainNode<T> *sourceNode = rightQ.queueFront;
        chainNode<T> *targetNode = this->queueFront;
        sourceNode = sourceNode->next;
        while (sourceNode != nullptr)
        {
            chainNode<T> *newNode = new chainNode<T>(sourceNode->next);
            targetNode->next = newNode;
            targetNode = targetNode->next;
            sourceNode = sourceNode->next;
        }
        targetNode->next = nullptr;
        this->queueBack = targetNode;
    }
    ~linkedQueue()
    {
        chainNode<T> *Node = this->queueFront;
        while (Node != nullptr)
        {
            chainNode<T> *nextNode = Node->next;
            delete Node;
            Node = nextNode;
        }
    }
    bool empty() const
    {
        return this->queueSize == 0;
    }
    virtual int size() const
    {
        return this->queueSize;
    }
    virtual T &front();
    virtual T &back();
    virtual void pop();
    virtual void push(const T &theElement);
    void output() const
    {
        chainNode<T> *Node = this->queueFront->next;
        while (Node != nullptr)
        {
            cout << Node->element << " ";
            Node = Node->next;
        }
    }
    linkedQueue<T> &operator=(const linkedQueue<T> &rightQ)
    {
        this->~linkedQueue();
        this->queueSize = rightQ.queueSize;
        this->queueFront = new chainNode<T>;
        chainNode<T> *sourceNode = rightQ.queueFront;
        chainNode<T> *targetNode = this->queueFront;
        sourceNode = sourceNode->next;
        while (sourceNode != nullptr)
        {
            chainNode<T> *newNode = new chainNode<T>(sourceNode->next);
            targetNode->next = newNode;
            targetNode = targetNode->next;
            sourceNode = sourceNode->next;
        }
        targetNode->next = nullptr;
        this->queueBack = targetNode;
        return *this;
    }

private:
    chainNode<T> *queueFront;
    chainNode<T> *queueBack;
    int queueSize;
};
template <class T>
void linkedQueue<T>::push(const T &theElement)
{
    chainNode<T> *newNode = new chainNode<T>(theElement);
    if (this->queueBack == nullptr)
        this->queueFront->next = newNode;
    else
        this->queueBack->next = newNode;
    this->queueBack = newNode;
    this->queueBack->next = nullptr;
    this->queueSize++;
}
template <class T>
void linkedQueue<T>::pop()
{
    if (this->queueFront->next == nullptr)
        throw queueEmpty("This queue is empty!");
    chainNode<T> *newNext = this->queueFront->next->next;
    delete this->queueFront->next;
    this->queueFront->next = newNext;
    this->queueSize--;
}
template <class T>
T &linkedQueue<T>::back()
{
    if (this->queueFront->next == nullptr)
        throw queueEmpty("This queue is empty!");
    return this->queueBack->element;
}
template <class T>
T &linkedQueue<T>::front()
{
    if (this->queueFront->next == nullptr)
        throw queueEmpty("This queue is empty!");
    return this->queueFront->next->element;
}
template <class T>
ostream &operator<<(ostream &cout, const linkedQueue<T> &Q)
{
    Q.output();
    return cout;
}
#endif