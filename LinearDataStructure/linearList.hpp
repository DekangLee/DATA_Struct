#ifndef _LINEARLISTH_
#define _LINEARLISTH_
#include <iostream>
#include <sstream>
#include <algorithm>
#include "myExpectation.h"
using namespace std;
template <class T>
class chainNode
{
public:
    T element;
    chainNode<T> *next;
    chainNode(){};
    chainNode(const T &element)
    {
        this->element = element;
    }
    chainNode(const T &element, chainNode<T> *next)
    {
        this->element = element;
        this->next = next;
    }
};
template <class T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T &get(int index) const = 0;
    virtual void erase(int index) = 0;
    virtual void insert(int index, const T &TheElement) = 0;
    virtual void push_back(const T &theElement) = 0;
    virtual void output(ostream &out) const = 0;
    virtual void setSize(int theSize) = 0;
};
template <class T>
class stack
{
public:
    virtual ~stack(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T &top() = 0;
    virtual void pop() = 0;
    virtual void push(const T &theElement) = 0;
};
#endif