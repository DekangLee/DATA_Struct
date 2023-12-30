#ifndef _CIRCULARLISTH_
#define _CIRCULARLISTH_
#include <iostream>
#include <sstream>
#include <algorithm>
#include "myExpectation.h"
#include "linearList.hpp"
#include "chainList.hpp"
template <class T>
class circularList : public linearList<T>
{
public:
    circularList();
    circularList(const circularList<T> &clst);
    ~circularList();
    // 抽象数类型的方法
    bool empty() const
    {
        return this->listSize == 0;
    }
    int size() const
    {
        return this->listSize;
    }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void push_back(const T &theElement);
    void output(ostream &cout) const;
    void insert(int index, const T &TheElement);
    void swap(int index1, int index2);
    void set(int theIndex, T theElement);
    void removeRange(int fromIndex, int toIndex);
    int lastIndexOf(const T &theElement) const;
    void reverse();
    void moveRight(int pos);
    void moveLeft(int pos);
    circularList<T> &meld(const circularList &List);
    class iterator;
    iterator begin()
    {
        return iterator(this->firstNode);
    }
    T &operator[](int theIndex)
    {
        this->checkIndex(theIndex);
        chainNode<T> *Node = this->headerNode->next;
        int index = 0;
        while (index < theIndex)
        {
            Node = Node->next;
            index++;
        }
        return Node->element;
    }
    void setSize(int theSize);
    void clear();
    circularList<T> &operator=(const circularList<T> &chainList);

private:
    void checkIndex(int theIndex) const;
    chainNode<T> *headerNode = nullptr;
    int listSize;
};
template <class T>
circularList<T>::circularList()
{
    this->headerNode = new chainNode<T>();
    this->headerNode->next = nullptr;
    this->listSize = 0;
}
template <class T>
circularList<T>::circularList(const circularList<T> &clst)
{
    this->listSize = clst.listSize;
    this->headerNode = new chainNode<T>();
    chainNode<T> *currentNode;
    chainNode<T> *preNode = this->headerNode;
    chainNode<T> *sourceNode = clst.headerNode->next;
    chainNode<T> *sourceFirstNode = clst.headerNode->next;
    while (sourceFirstNode != nullptr)
    {
        currentNode = new chainNode<T>(sourceNode->element);
        preNode->next = currentNode;
        preNode = currentNode;
        sourceNode = sourceNode->next;
        if(sourceNode == sourceFirstNode) break;
    }
    preNode->next = this->headerNode->next;
}
template <class T>
circularList<T>::~circularList()
{
    chainNode<T> *firstNode = this->headerNode->next;
    while (firstNode != nullptr)
    {
        chainNode<T> *Node = this->headerNode->next->next;
        delete headerNode->next;
        this->headerNode->next = Node;
        if (this->headerNode->next == firstNode)
            break;
    }
    delete this->headerNode;
}
template <class T>
void circularList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= this->listSize)
    {
        ostringstream tip;
        tip << "Error! The index = " << theIndex << " But the size = " << this->listSize;
        throw illegalIndex(tip.str());
        return;
    }
}
template <class T>
void circularList<T>::push_back(const T &theElement)
{
    chainNode<T> *firstNode = this->headerNode->next;
    chainNode<T> *currentNode = this->headerNode->next;
    chainNode<T> *preNode = this->headerNode;
    while (firstNode != nullptr)
    {
        preNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode == firstNode)
            break;
    }
    chainNode<T> *newNode = new chainNode<T>(theElement);
    // cout << "headerNode = " << this->headerNode << endl;
    // cout << "headerNode->next = " << this->headerNode->next << endl;
    // cout << "preNode = " << preNode << endl;
    preNode->next = newNode;
    // cout << "preNode->next = " << preNode->next << endl;
    newNode->next = this->headerNode->next;
    this->listSize++;
}
template <class T>
T &circularList<T>::get(int theIndex) const
{
    this->checkIndex(theIndex); // 检查索引是否越界
    int count = 0;
    chainNode<T> *Node = this->headerNode;
    // Node = Node->next;
    // cout<<Node->next->next->element<<endl;
    while (count <= theIndex)
    {
        Node = Node->next;
        count++;
    }
    return Node->element;
}
template <class T>
int circularList<T>::indexOf(const T &theElement) const
{
    chainNode<T> *Node = this->headerNode->next;
    int index = 0;
    while (Node != nullptr)
    {
        if (Node->element == theElement)
        {
            break;
        }
        Node = Node->next;
        index++;
    }
    if (Node == nullptr)
    {
        return -1;
    }
    else
        return index;
}
template <class T>
void circularList<T>::erase(int theIndex)
{

}
template <class T>
void circularList<T>::output(ostream &cout) const
{
    chainNode<T> *Node = this->headerNode->next;
    chainNode<T> *firstNode = this->headerNode->next;
    while (firstNode != nullptr)
    {
        // cout << "Node = " << Node << " " << endl;
        cout << Node->element << " ";
        Node = Node->next;
        if (Node == firstNode)
            break;
    }
}
template <class T>
void circularList<T>::insert(int index, const T &TheElement)
{
}
template <class T>
void circularList<T>::swap(int index1, int index2)
{
}
template <class T>
void circularList<T>::set(int theIndex, T theElement)
{
}
template <class T>
void circularList<T>::removeRange(int fromIndex, int toIndex)
{
}
template <class T>
int circularList<T>::lastIndexOf(const T &theElement) const
{
    return -1;
}
template <class T>
void circularList<T>::reverse()
{
}
template <class T>
void circularList<T>::moveRight(int pos)
{
}
template <class T>
void circularList<T>::moveLeft(int pos)
{
}
template <class T>
circularList<T> &circularList<T>::meld(const circularList &List)
{
}
template <class T>
void circularList<T>::setSize(int theSize)
{
}
template <class T>
void circularList<T>::clear()
{
}
template <class T>
circularList<T> &circularList<T>::operator=(const circularList<T> &chainList)
{
    chainNode<T> *firstNode = this->headerNode->next;
    while (firstNode != nullptr)
    {
        chainNode<T> *Node = this->headerNode->next->next;
        delete headerNode->next;
        this->headerNode->next = Node;
        if(this->headerNode->next == firstNode) break;
    }
    delete this->headerNode;
    this->listSize = chainList.listSize;
    this->headerNode = new chainNode<T>();
    chainNode<T> *currentNode;
    chainNode<T> *preNode = this->headerNode;
    chainNode<T> *sourceNode = chainList.headerNode->next;
    chainNode<T> *sourceFirstNode = chainList.headerNode->next;
    while (sourceFirstNode != nullptr)
    {
        currentNode = new chainNode<T>(sourceNode->element);
        preNode->next = currentNode;
        preNode = currentNode;
        sourceNode = sourceNode->next;
        if(sourceNode == sourceFirstNode) break;
    }
    preNode->next = this->headerNode->next;
    return *this;
}
template <class T>
ostream &operator<<(ostream &cout, const circularList<T> &List)
{
    List.output(cout);
    return cout;
}
#endif