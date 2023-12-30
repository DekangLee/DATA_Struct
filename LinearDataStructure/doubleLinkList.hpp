#pragma once
#ifndef _DOUBLELINKLISTH_
#define _DOUBLELINKLISTH_
#include <iostream>
#include "linearList.hpp"
#include <sstream>
#include "myExpectation.h"
namespace doublychainNode
{
    template <class T>
    class chainNode
    {
    public:
        T element;
        chainNode<T> *previous;
        chainNode<T> *next;
        chainNode()
        {
            this->previous = nullptr;
            this->next = nullptr;
        }
        chainNode(const T &element)
        {
            this->element = element;
            this->previous = nullptr;
            this->next = nullptr;
        }
        chainNode<T> &operator=(const chainNode<T> &Node)
        {
            this->element = Node.element;
            this->previous = Node.previous;
            this->next = Node.next;
        }
    };
}
template <class T>
class doubleLinkList : public linearList<T>
{
public:
    doubleLinkList();
    doubleLinkList(const doubleLinkList<T> &clst);
    ~doubleLinkList();
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
    void push_front(const T &theElement);
    void output(ostream &cout) const;
    void insert(int index, const T &TheElement);
    void swap(int index1, int index2);
    void set(int theIndex, T theElement);
    void removeRange(int fromIndex, int toIndex);
    int lastIndexOf(const T &theElement) const;
    void reverse();
    void moveRight(int pos);
    void moveLeft(int pos);
    void doubleLinkTest();
    doubleLinkList<T> &meld(const doubleLinkList &List);
    class iterator
    {
    public:
        iterator(doublychainNode::chainNode<T> *thePosition = nullptr)
        {
            this->position = thePosition;
        }
        T &operator*() const
        {
            return (*position).element;
        }
        T *operator->() const
        {
            return &(*position).element;
        }
        iterator &operator++() // 前置递增
        {
            this->position = this->position->next;
            return *this;
        }
        iterator operator++(int) // 后置递增
        {
            iterator temp = *this;
            this->position = this->position->next;
            return temp;
        }
        iterator &operator--() // 前置递减
        {
            this->position = this->position->previous;
            return *this;
        }
        iterator operator--(int) // 后置递减
        {
            iterator temp = *this;
            this->position = this->position->previous;
            return temp;
        }
        bool operator!=(const iterator &right_it) const
        {
            return this->position != right_it.position;
        }
        bool operator==(const iterator &right_it) const
        {
            return this->position == right_it.position;
        }
        iterator &operator=(const iterator &it)
        {
            this->position = it.position;
            return *this;
        }

    private:
        doublychainNode::chainNode<T> *position = nullptr;
    };
    iterator begin() const
    {
        return iterator(this->firstNode);
    }
    iterator end() const
    {
        return iterator(this->lastNode);
    }
    T &operator[](int theIndex)
    {
        this->checkIndex(theIndex);
        doublychainNode::chainNode<T> *Node = this->firstNode;
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
    doubleLinkList<T> &operator=(const doubleLinkList<T> &chainList);

private:
    void checkIndex(int theIndex) const;
    doublychainNode::chainNode<T> *firstNode;
    doublychainNode::chainNode<T> *lastNode;
    int listSize;
};
template <class T>
doubleLinkList<T>::doubleLinkList()
{
    this->firstNode = nullptr;
    this->lastNode = nullptr;
    this->listSize = 0;
}
template <class T>
doubleLinkList<T>::doubleLinkList(const doubleLinkList<T> &dlst)
{
    this->listSize = dlst.listSize;
    if (this->listSize == 0)
    {
        this->firstNode = nullptr;
        this->lastNode = nullptr;
        return;
    }
    doublychainNode::chainNode<T> *currentNode = nullptr;
    doublychainNode::chainNode<T> *sourcefirstNode = dlst.firstNode;
    doublychainNode::chainNode<T> *sourcelastNode = dlst.lastNode;
    this->firstNode = new doublychainNode::chainNode<T>(sourcefirstNode->element);
    if (sourcefirstNode == sourcelastNode)
    {
        this->firstNode->next = this->firstNode;
        this->firstNode->previous = this->firstNode;
        this->lastNode = firstNode;
        return;
    }
    doublychainNode::chainNode<T> *preNode = this->firstNode;
    sourcefirstNode = sourcefirstNode->next;
    while (sourcefirstNode != sourcelastNode)
    {
        currentNode = new doublychainNode::chainNode<T>(sourcefirstNode->element);
        currentNode->previous = preNode;
        preNode->next = currentNode;
        preNode = currentNode;
        sourcefirstNode = sourcefirstNode->next;
    }
    currentNode = new doublychainNode::chainNode<T>(sourcelastNode->element);
    preNode->next = currentNode;
    currentNode->next = this->firstNode;
    currentNode->previous = preNode;
    this->firstNode->previous = currentNode;
    this->lastNode = currentNode;
}
template <class T>
doubleLinkList<T>::~doubleLinkList()
{
    if (this->firstNode == nullptr)
        return;
    while (this->firstNode != this->lastNode)
    {
        doublychainNode::chainNode<T> *Node = firstNode->next;
        delete this->firstNode;
        this->firstNode = Node;
    }
    delete this->lastNode;
}
template <class T>
void doubleLinkList<T>::doubleLinkTest()
{
    doublychainNode::chainNode<T> *Node = this->firstNode;
    while (Node != this->lastNode)
    {
        cout << Node->element << " ";
        Node = Node->next;
    }
    if (Node != nullptr)
    {
        cout << Node->element << " ";
    }
    // doublychainNode::chainNode<T> *Node = this->lastNode;
    // if(Node->next == this->firstNode)
    // {
    //     cout<<true;
    // }
    // cout<<this->lastNode->next->element<<endl;
    // while (Node != this->firstNode)
    // {
    //     cout<<Node->element<<" ";
    //     Node = Node->previous;
    // }
    // if(Node != nullptr)
    // {
    //     cout<< Node->element<<" ";
    // }
}
template <class T>
void doubleLinkList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= this->listSize)
    {
        ostringstream tip;
        tip << "Error! The index = " << theIndex << " But the size = " << this->listSize;
        throw illegalIndex(tip.str());
        return;
    }
}
// 双向链表尾插
template <class T>
void doubleLinkList<T>::push_back(const T &theElement)
{
    doublychainNode::chainNode<T> *currentNode;
    doublychainNode::chainNode<T> *preNode;
    if (this->firstNode == nullptr && this->lastNode == nullptr)
    {
        this->firstNode = new doublychainNode::chainNode<T>(theElement);
        this->firstNode->next = this->firstNode;
        this->firstNode->previous = this->firstNode;
        this->lastNode = firstNode;
    }
    else if (this->lastNode == this->firstNode)
    {
        preNode = this->firstNode;
        currentNode = new doublychainNode::chainNode<T>(theElement);
        preNode->next = currentNode;
        preNode->previous = currentNode;
        currentNode->previous = preNode;
        currentNode->next = preNode;
        this->lastNode = currentNode;
    }
    else
    {
        currentNode = new doublychainNode::chainNode<T>(theElement);
        this->lastNode->next = currentNode;
        currentNode->previous = this->lastNode;
        currentNode->next = this->firstNode;
        this->firstNode->previous = currentNode;
        this->lastNode = currentNode;
    }
    this->listSize++;
}
// 双向链表头插
template <class T>
void doubleLinkList<T>::push_front(const T &theElement)
{
    doublychainNode::chainNode<T> *currentNode;
    doublychainNode::chainNode<T> *preNode;
    if (this->firstNode == nullptr && this->lastNode == nullptr)
    {
        this->firstNode = new doublychainNode::chainNode<T>(theElement);
        this->firstNode->next = this->firstNode;
        this->firstNode->previous = this->firstNode;
        this->lastNode = firstNode;
    }
    else if (this->lastNode == this->firstNode)
    {
        preNode = this->lastNode;
        currentNode = new doublychainNode::chainNode<T>(theElement);
        preNode->next = currentNode;
        preNode->previous = currentNode;
        currentNode->previous = preNode;
        currentNode->next = preNode;
        this->firstNode = currentNode;
    }
    else
    {
        currentNode = new doublychainNode::chainNode<T>(theElement);
        this->firstNode->previous = currentNode;
        currentNode->next = this->firstNode;
        currentNode->previous = this->lastNode;
        this->lastNode->next = currentNode;
        this->firstNode = currentNode;
    }
    this->listSize++;
}
template <class T>
T &doubleLinkList<T>::get(int theIndex) const
{
    this->checkIndex(theIndex); // 检查索引是否越界
    int count = 0;
    doublychainNode::chainNode<T> *Node = this->firstNode;
    // Node = Node->next;
    // cout<<Node->next->next->element<<endl;
    while (count < theIndex)
    {
        Node = Node->next;
        count++;
    }
    return Node->element;
}
template <class T>
int doubleLinkList<T>::indexOf(const T &theElement) const
{
    doublychainNode::chainNode<T> *Node = this->firstNode;
    int index = 0;
    while (Node != nullptr && Node != this->lastNode)
    {
        if (Node->element == theElement)
        {
            break;
        }
        Node = Node->next;
        index++;
    }
    if (this->lastNode != nullptr)
    {
    }
    if (Node == nullptr)
    {
        return -1;
    }
    else
        return index;
}
template <class T>
void doubleLinkList<T>::erase(int theIndex)
{
}
template <class T>
void doubleLinkList<T>::output(ostream &cout) const
{
    doublychainNode::chainNode<T> *curruntNode = this->firstNode;
    cout << curruntNode->element << " ";
    curruntNode = curruntNode->next;
    while (curruntNode != this->firstNode)
    {
        // cout << "Node = " << Node << " " << endl;
        cout << curruntNode->element << " ";
        curruntNode = curruntNode->next;
    }
    // if (curruntNode != nullptr)
    //     cout << curruntNode->element << " ";
}
template <class T>
void doubleLinkList<T>::insert(int index, const T &TheElement)
{
    if (index >= this->listSize)
    {
        throw illegalIndex("ERROR! index >= this->listSize");
    }
    if (index * 2 > this->listSize)
    {
        doublychainNode::chainNode<T> *currentNode = this->lastNode;
        for (int i = this->listSize - 1; i >= index; i--)
        {
            currentNode = currentNode->previous;
        }
        doublychainNode::chainNode<T> *nextNode = currentNode->next;
        doublychainNode::chainNode<T> *newNode = new doublychainNode::chainNode<T>(TheElement);
        newNode->previous = currentNode;
        newNode->next = nextNode;
        currentNode->next = newNode;
        nextNode->previous = newNode;
    }
    else
    {
        doublychainNode::chainNode<T> *currentNode = this->firstNode;
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }
        doublychainNode::chainNode<T> *preNode = currentNode->previous;
        doublychainNode::chainNode<T> *newNode = new doublychainNode::chainNode<T>(TheElement);
        newNode->previous = preNode;
        newNode->next = currentNode;
        currentNode->previous = newNode;
        preNode->next = newNode;
        if(index == 0)
        {
            this->firstNode = newNode;
        }
    }
    this->listSize++;
}
template <class T>
void doubleLinkList<T>::swap(int index1, int index2)
{
    this->checkIndex(index1);
    this->checkIndex(index2);
    if (index1 == index2)
        return;
    int pre = (index1 > index2 ? index2 : index1);
    int next = (index1 < index2 ? index2 : index1);
    doublychainNode::chainNode<T> *preNode = this->firstNode;
    doublychainNode::chainNode<T> *nextNode = this->lastNode;
    int index = 0;
    while (index < pre)
    {
        preNode = preNode->next;
        index++;
    }
    index = this->listSize - 1;
    while (index > next)
    {
        nextNode = nextNode->previous;
        index--;
    }
    T tempElement = preNode->element;
    preNode->element = nextNode->element;
    nextNode->element = tempElement;
}
template <class T>
void doubleLinkList<T>::set(int theIndex, T theElement)
{
}
template <class T>
void doubleLinkList<T>::removeRange(int fromIndex, int toIndex)
{
}
template <class T>
int doubleLinkList<T>::lastIndexOf(const T &theElement) const
{
    return -1;
}
template <class T>
void doubleLinkList<T>::reverse()
{
    doublychainNode::chainNode<T> *NewfirstNode = this->firstNode;
    while (NewfirstNode != nullptr && NewfirstNode != this->lastNode)
    {
        doublychainNode::chainNode<T> *Node = NewfirstNode->next;
        NewfirstNode->next = NewfirstNode->previous;
        NewfirstNode->previous = Node;
        NewfirstNode = NewfirstNode->previous;
    }
    if (this->lastNode != nullptr)
    {
        doublychainNode::chainNode<T> *Node = NewfirstNode->next;
        NewfirstNode->next = NewfirstNode->previous;
        NewfirstNode->previous = Node;
        Node = this->firstNode;
        this->firstNode = this->lastNode;
        this->lastNode = Node;
    }
}
// 双头链表右移
template <class T>
void doubleLinkList<T>::moveRight(int pos)
{
    int skipR = pos % this->listSize;
    if (skipR == 0)
    {
        return;
    }
    for (int index = 0; index < skipR; index++)
    {
        this->firstNode = this->firstNode->previous;
        this->lastNode = this->lastNode->next;
    }
}
// 双头循环链表左移
template <class T>
void doubleLinkList<T>::moveLeft(int pos)
{
    int skipL = pos % this->listSize;
    if (skipL == 0)
    {
        return;
    }
    for (int index = 0; index < skipL; index++)
    {
        this->firstNode = this->firstNode->next;
        this->lastNode = this->lastNode->previous;
    }
}
template <class T>
doubleLinkList<T> &doubleLinkList<T>::meld(const doubleLinkList &List)
{
}
template <class T>
void doubleLinkList<T>::setSize(int theSize)
{
}
template <class T>
void doubleLinkList<T>::clear()
{
}
template <class T>
doubleLinkList<T> &doubleLinkList<T>::operator=(const doubleLinkList<T> &List)
{
    while (this->firstNode != this->lastNode)
    {
        doublychainNode::chainNode<T> *Node = this->firstNode->next;
        delete this->firstNode;
        this->firstNode = this->firstNode->next;
    }
    this->listSize = List.listSize;
    if (this->listSize == 0)
    {
        this->firstNode = nullptr;
        this->lastNode = nullptr;
        return *this;
    }
    doublychainNode::chainNode<T> *currentNode = nullptr;
    doublychainNode::chainNode<T> *sourcefirstNode = List.firstNode;
    doublychainNode::chainNode<T> *sourcelastNode = List.lastNode;
    this->firstNode = new doublychainNode::chainNode<T>(sourcefirstNode->element);
    if (sourcefirstNode == sourcelastNode)
    {
        this->firstNode->next = this->firstNode;
        this->firstNode->previous = this->firstNode;
        this->lastNode = firstNode;
        return *this;
    }
    doublychainNode::chainNode<T> *preNode = this->firstNode;
    sourcefirstNode = sourcefirstNode->next;
    while (sourcefirstNode != sourcelastNode)
    {
        currentNode = new doublychainNode::chainNode<T>(sourcefirstNode->element);
        currentNode->previous = preNode;
        preNode->next = currentNode;
        preNode = currentNode;
        sourcefirstNode = sourcefirstNode->next;
    }
    currentNode = new doublychainNode::chainNode<T>(sourcelastNode->element);
    preNode->next = currentNode;
    currentNode->next = this->firstNode;
    currentNode->previous = preNode;
    this->firstNode->previous = currentNode;
    this->lastNode = currentNode;
    return *this;
}
template <class T>
ostream &operator<<(ostream &cout, const doubleLinkList<T> &List)
{
    List.output(cout);
    return cout;
}
#endif