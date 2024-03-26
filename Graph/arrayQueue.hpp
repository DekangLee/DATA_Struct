#ifndef _ARRAYQUEUE_
#define _ARRAYQUEUE_
#include <iostream>
#include <algorithm>
#include "myExpectation.h"
template <class T>
class arrayQueue
{
public:
    arrayQueue(int capacity = 10)
    {
        this->arraylenth = capacity;
        this->queue = new T[this->arraylenth];
        this->queueFront = this->queueBack = 0;
        this->queueSize = 0;
    }
    arrayQueue(const arrayQueue<T> &rightQ)
    {
        this->arraylenth = rightQ.arraylenth;
        this->queueFront = rightQ.queueFront;
        this->queueBack = rightQ.queueBack;
        this->queue = new T[this->arraylenth];
        copy(rightQ.queue, rightQ.queue + rightQ.arraylenth + 1, this->queue);
    }
    ~arrayQueue()
    {
        if (this->queue != nullptr)
        {
            delete[] this->queue;
            this->queue = nullptr;
        }
    }
    bool empty() const
    {
        return this->queueBack == this->queueFront;
    }
    virtual int size() const;
    virtual T &front();
    virtual T &back();
    virtual void pop();
    virtual void push(const T &theElement);
    void output()
    {
        for (int i = 0; i < this->arraylenth; i++)
        {
            cout << this->queue[i] << " ";
        }
        cout << endl;
    }
    arrayQueue<T> &operator=(const arrayQueue<T> &rightQ)
    {
        if (this->queue != nullptr)
        {
            delete[] this->queue;
        }
        this->arraylenth = rightQ.arraylenth;
        this->queueFront = rightQ.queueFront;
        this->queueBack = rightQ.queueBack;
        this->queue = new T[this->arraylenth];
        copy(rightQ.queue, rightQ.queue + rightQ.arraylenth + 1, this->queue);
        return *this;
    }

private:
    T *queue;
    int queueFront;
    int queueBack;
    int arraylenth;
    int queueSize;
};
template <class T>
int arrayQueue<T>::size() const
{
    return this->queueSize;
}
template <class T>
void arrayQueue<T>::push(const T &theElement)
{

    // cout << "this->queueFront:" << this->queueFront << endl;
    if ((this->queueBack + 1) % this->arraylenth == this->queueFront)
    {
        T *newQueue = new T[2 * this->arraylenth];
        if (this->queueFront < this->queueBack) // 未形成环形
        {
            copy(queue + this->queueFront + 1, queue + this->queueBack + 1, newQueue + this->queueFront + 1);
        }
        else
        {
            copy(queue, queue + this->queueBack + 1, newQueue);
            copy(queue + this->queueFront + 1, queue + this->arraylenth + 1, newQueue + arraylenth + this->queueFront + 1);
            this->queueFront += this->arraylenth;
        }
        this->arraylenth *= 2;
        delete[] this->queue;
        this->queue = newQueue;
    }
    this->queueBack = (this->queueBack + 1) % this->arraylenth;
    this->queue[this->queueBack] = theElement;
    this->queueSize++;
    // cout << "this->queueBack:" << this->queueBack << endl;
}
template <class T>
T &arrayQueue<T>::front()
{
    if (this->queueFront == this->queueBack)
        throw queueEmpty("This queue is empty");
    int theFront = (this->queueFront + 1) % this->arraylenth;
    return this->queue[theFront];
}
template <class T>
void arrayQueue<T>::pop()
{
    if (this->queueFront == this->queueBack)
    {
        throw illegalIndex("This queue is empty");
    }
    this->queueFront = (this->queueFront + 1) % this->arraylenth;
    this->queue[this->queueFront].~T();
    this->queueSize--;
}
template <class T>
T &arrayQueue<T>::back()
{
    if (this->queueFront == this->queueBack)
        throw queueEmpty("This queue is empty");
    return this->queue[this->queueBack];
}
#endif