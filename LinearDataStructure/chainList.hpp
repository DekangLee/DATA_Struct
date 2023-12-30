#ifndef _CHAINLISTH_
#define _CHAINLISTH_
#include <iostream>
#include <sstream>
#include <algorithm>
#include "myExpectation.h"
#include "linearList.hpp"
#include "arrayList.hpp"
template <class T>
class chainList : public linearList<T>
{
public:
    chainList(int initialCapacity = 10);
    chainList(const chainList<T> &clst);
    ~chainList();
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
    T max();
    T min();
    chainList<T> &meld(const chainList<T> &List);
    class iterator;
    iterator begin()const
    {
        return iterator(this->firstNode);
    }
    T &operator[](int theIndex)
    {
        this->checkIndex(theIndex);
        chainNode<T> *Node = this->firstNode;
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
    void _swap(int index1, int index2);
    chainList<T> &operator=(const chainList<T> &chainList);

private:
    void checkIndex(int theIndex) const;
    chainNode<T> *firstNode = nullptr;
    int listSize;
};
template <class T>
chainList<T>::chainList(int initialCapacity)
{
    // cout<<"chainList(int initialCapacity)"<<endl;
    if (initialCapacity < 1)
    {
        ostringstream tip;
        tip << "error! Inital capacity = " << initialCapacity << " Must be > 0!";
        throw illegalParameterValue(tip.str());
    }
    this->firstNode = nullptr;
    this->listSize = 0;
}
template <class T>
chainList<T>::chainList(const chainList<T> &clst) // 可以分析拷贝构造的时间复杂度为n，与clst.size有关
{
    this->listSize = clst.listSize;
    if (clst.listSize == 0)
    {
        // cout << "...." << endl;
        this->firstNode = nullptr;
        return;
    }
    // 链表clst 非空时,两件事 1、开辟空间赋值 2、指针后移
    chainNode<T> *sourceNode = clst.firstNode;
    this->firstNode = new chainNode<T>(sourceNode->element);
    chainNode<T> *currentNode = this->firstNode;
    chainNode<T> *nextNode = nullptr;
    sourceNode = sourceNode->next;
    while (sourceNode != nullptr)
    {
        nextNode = new chainNode<T>(sourceNode->element);
        currentNode->next = nextNode;
        currentNode = nextNode;
        sourceNode = sourceNode->next;
    }
    currentNode->next = nullptr;
}
template <class T>
chainList<T>::~chainList()
{
    chainNode<T> *Node;
    Node = this->firstNode;
    while (Node != nullptr)
    {
        chainNode<T> *temp = Node->next;
        delete Node;
        Node = temp;
    }
    this->firstNode = nullptr;
}
template <class T>
void chainList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= this->listSize)
    {
        ostringstream tip;
        tip << "Error! The index = " << theIndex << " But the size = " << this->listSize;
        throw illegalIndex(tip.str());
        return;
    }
}
// 扩充链表
template <class T>
chainList<T> &chainList<T>::meld(const chainList<T> &List)
{
    chainNode<T> *Node = this->firstNode;
    chainNode<T> *preNode = nullptr;
    while (Node != nullptr)
    {
        preNode = Node;
        Node = Node->next;
    }
    chainNode<T> *sourceNode = List.firstNode;
    while (sourceNode != nullptr)
    {
        Node = new chainNode<T>(sourceNode->element);
        preNode->next = Node;
        preNode = preNode->next;
        sourceNode = sourceNode->next;
    }
    preNode->next = nullptr;
    this->listSize += List.listSize;
    return *this;
}
// 根据索引获得链表元素
template <class T>
T &chainList<T>::get(int theIndex) const
{
    this->checkIndex(theIndex); // 检查索引是否越界
    int count = 0;
    chainNode<T> *Node = this->firstNode;
    // Node = Node->next;
    // cout<<Node->next->next->element<<endl;
    while (count < theIndex)
    {
        Node = Node->next;
        count++;
    }
    return Node->element;
}
// 查找元素第一次出现时的索引
template <class T>
int chainList<T>::indexOf(const T &theElement) const
{
    chainNode<T> *Node = this->firstNode;
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
int chainList<T>::lastIndexOf(const T &theElement) const
{
    chainNode<T> *Node = this->firstNode;
    int index = -1;
    int count = 0;
    while (Node != nullptr)
    {
        if (Node->element == theElement)
        {
            index = count;
        }
        Node = Node->next;
        count++;
    }
    return index;
}
// 删除索引对应的元素
template <class T>
void chainList<T>::erase(int theIndex)
{
    try
    {
        this->checkIndex(theIndex);
    }
    catch (illegalIndex &e)
    {
        e.outputMessage();
        return;
    }

    int index = 0;
    chainNode<T> *Node = this->firstNode;
    chainNode<T> *preNode = nullptr;
    for (; index < theIndex; index++)
    {
        preNode = Node;
        Node = Node->next;
    }
    if (preNode == nullptr)
    {
        chainNode<T> *temp = Node->next;
        delete Node;
        this->firstNode = temp;
    }
    else if (Node->next == nullptr)
    {
        delete Node;
        preNode->next = nullptr;
    }
    else
    {
        chainNode<T> *temp = Node->next;
        delete Node;
        preNode->next = temp;
    }
    this->listSize--;
}
// 使链表逆序,成员函数实现，线性时间复杂度
template <class T>
void chainList<T>::reverse()
{
    if (this->firstNode == nullptr || this->firstNode->next == nullptr)
    {
        return;
    }
    chainNode<T> *Node = this->firstNode;
    chainNode<T> *preNode = this->firstNode;
    Node = Node->next;
    preNode->next = nullptr;
    while (Node != nullptr)
    {
        chainNode<T> *tempNode = Node->next;
        Node->next = preNode;
        preNode = Node;
        Node = tempNode;
    }
    this->firstNode = preNode;
}
// 在chainList尾部附上元素element
template <class T>
void chainList<T>::push_back(const T &theElement)
{
    if (this->firstNode == nullptr)
    {
        this->firstNode = new chainNode<T>(theElement);
        this->firstNode->next = nullptr;
    }
    else
    {
        chainNode<T> *Node = this->firstNode;
        chainNode<T> *preNode = nullptr;
        while (Node != nullptr)
        {
            preNode = Node;
            Node = Node->next;
        }
        Node = new chainNode<T>(theElement);
        preNode->next = Node;
        Node->next = nullptr;
    }
    this->listSize++;
}
template <class T>
void chainList<T>::output(ostream &cout) const
{
    chainNode<T> *Node = this->firstNode;
    while (Node != nullptr)
    {
        cout << Node->element << " ";
        Node = Node->next;
    }
}
// 链表前插
template <class T>
void chainList<T>::push_front(const T &theElement)
{
    chainNode<T> *newNode = new chainNode<T>(theElement);
    if (this->firstNode == nullptr)
    {
        this->firstNode = newNode;
        this->firstNode->next = nullptr;
    }
    else
    {
        newNode->next = this->firstNode;
        this->firstNode = newNode;
    }
    this->listSize++;
}
// 返回链表的最大值
template <class T>
T chainList<T>::max()
{
    if (this->listSize == 0)
    {
        ostringstream tip;
        tip << "The size of this list is zero !";
        throw illegalParameterValue(tip.str());
    }
    T max = this->firstNode->element;
    chainNode<T> *Node = this->firstNode;
    while (Node != nullptr)
    {
        if (max < Node->element)
        {
            max = Node->element;
        }
        Node = Node->next;
    }
    return max;
}
// 返回链表的最小值
template <class T>
T chainList<T>::min()
{
    if (this->listSize == 0)
    {
        ostringstream tip;
        tip << "The size of this list is zero !";
        throw illegalParameterValue(tip.str());
    }
    T min = this->firstNode->element;
    chainNode<T> *Node = this->firstNode;
    while (Node != nullptr)
    {
        if (min > Node->element)
        {
            min = Node->element;
        }
        Node = Node->next;
    }
    return min;
}
template <class T>
ostream &operator<<(ostream &cout, const chainList<T> &chainL)
{
    chainL.output(cout);
    return cout;
}
template <class T>
chainList<T> &chainList<T>::operator=(const chainList<T> &chainList)
{
    chainNode<T> *targetNode = this->firstNode;
    while (targetNode != nullptr)
    {
        chainNode<T> *nextNode = targetNode->next;
        delete targetNode;
        targetNode = nextNode;
    }
    this->listSize = chainList.listSize;
    if (this->listSize == 0)
    {
        // cout<<"88888"<<endl;
        this->firstNode = nullptr;
    }
    else
    {
        targetNode = chainList.firstNode;
        chainNode<T> *thisNode = nullptr;
        this->firstNode = new chainNode<T>(targetNode->element);
        chainNode<T> *preNode = this->firstNode;
        targetNode = targetNode->next;
        while (targetNode != nullptr)
        {
            thisNode = new chainNode<T>(targetNode->element);
            preNode->next = thisNode;
            preNode = thisNode;
            targetNode = targetNode->next;
        }
        preNode->next = nullptr;
    }
    return *this;
}
// 链表向左移动pos个位置
template <class T>
void chainList<T>::moveLeft(int pos)
{
    int moveL = pos % this->listSize;
    if (moveL == 0)
    {
        return;
    }
    chainNode<T> *Node = this->firstNode;
    chainNode<T> *preNode = nullptr;
    chainNode<T> *newFirst = nullptr;
    chainNode<T> *newLast = nullptr;
    int index = 0;
    while (Node != nullptr)
    {
        if (index == moveL)
        {
            newFirst = Node;
            newLast = preNode;
        }
        preNode = Node;
        Node = Node->next;
        index++;
    }
    preNode->next = this->firstNode;
    this->firstNode = newFirst;
    newLast->next = nullptr;
}
// 链表向右移动pos个位置
template <class T>
void chainList<T>::moveRight(int pos)
{
    int moveR = pos % this->listSize;
    if (moveR == 0)
    {
        return;
    }
    this->moveLeft(this->listSize - moveR);
}
// 指定位置插入指定元素
template <class T>
void chainList<T>::insert(int theIndex, const T &TheElement)
{
    try
    {
        this->checkIndex(theIndex);
    }
    catch (illegalIndex &e)
    {
        e.outputMessage();
    }
    chainNode<T> *newNode = new chainNode<T>(TheElement);
    chainNode<T> *Node = this->firstNode;
    chainNode<T> *preNode = nullptr;
    int index = 0;
    while (index < theIndex)
    {
        preNode = Node;
        Node = Node->next;
        index++;
    }
    if (preNode == nullptr)
    {
        newNode->next = Node;
        this->firstNode = newNode;
    }
    else
    {
        preNode->next = newNode;
        newNode->next = Node;
    }
    this->listSize++;
}
template <class T>
void chainList<T>::set(int theIndex, T theElement)
{
    checkIndex(theIndex);
    chainNode<T> *Node = this->firstNode;
    int index = 0;
    while (index < theIndex)
    {
        Node = Node->next;
        index++;
    }
    Node->element = theElement;
}
template <class T>
void chainList<T>::removeRange(int fromIndex, int toIndex)
{
    if (fromIndex > toIndex)
    {
        ostringstream tip;
        tip << "Error! fromIndex > toIndex";
        throw illegalParameterValue(tip.str());
        return;
    }
    this->checkIndex(fromIndex);
    this->checkIndex(toIndex);
    chainNode<T> *fromNode = this->firstNode;
    chainNode<T> *prefromNode = nullptr;
    for (int index = 0; index < fromIndex; index++)
    {
        prefromNode = fromNode;
        fromNode = fromNode->next;
    }
    chainNode<T> *toNode = fromNode;
    for (int index = fromIndex; index < toIndex; index++)
    {
        toNode = toNode->next;
    }
    cout << fromNode->element << endl;
    // cout << "toNode->next = " << toNode->next << endl;
    if (prefromNode == nullptr)
    {
        this->firstNode = toNode->next;
    }
    else
    {
        prefromNode->next = toNode->next;
    }
    chainNode<T> *stopNode = toNode->next;
    while (fromNode != stopNode)
    {
        chainNode<T> *tempNode = fromNode->next;
        // cout << fromNode->element << endl;
        // cout << "fromNode = " << fromNode << endl;
        // cout << "fromNode->next = " << fromNode->next << endl;
        // cout << "toNode->next = " << toNode->next << endl;
        // cout << "-----------------" << endl;
        delete fromNode;
        fromNode = tempNode;
    }
    this->listSize = this->listSize - (toIndex - fromIndex + 1);
}
template <class T>
class chainList<T>::iterator
{
public:
    iterator(chainNode<T> *theNode = nullptr);
    T &operator*() const;
    T *operator->() const;
    iterator &operator++()
    {
        this->Node = this->Node->next;
        return *this;
    }
    iterator operator++(int)
    {
        iterator temp = *this;
        this->Node = this->Node->next;
        return temp;
    }
    bool operator!=(const iterator &right);
    bool operator==(const iterator &right);

private:
    chainNode<T> *Node = nullptr;
};
template <class T>
chainList<T>::iterator::iterator(chainNode<T> *theNode)
{
    this->Node = theNode;
}
template <class T>
T &chainList<T>::iterator::operator*() const
{
    return this->Node->element;
}
template <class T>
T *chainList<T>::iterator::operator->() const
{
    return &this->Node->element;
}
template <class T>
bool chainList<T>::iterator::operator!=(const iterator &right)
{
    if (this->Node->element != right->Node->element && this->Node->next != right->Node->next)
    {
        return true;
    }
    else
        return false;
}
template <class T>
bool chainList<T>::iterator::operator==(const iterator &right)
{
    if (this->Node->element == right->Node->element && this->Node->next == right->Node->next)
    {
        return true;
    }
    else
        return false;
}
// 交换链表中的两个元素位置
template <class T>
void chainList<T>::_swap(int index1, int index2)
{
    checkIndex(index1);
    checkIndex(index2);
    if (index1 == index2)
        return;
    int right = (index1 > index2 ? index1 : index2);
    int left = (index1 <= index2 ? index1 : index2);
    // cout << "Left = " << left << endl;
    // cout << "right = " << right << endl;
    chainNode<T> *NodeLeft = this->firstNode;
    chainNode<T> *preNodeLeft = nullptr;
    for (int index = 0; index < left; index++)
    {
        preNodeLeft = NodeLeft;
        NodeLeft = NodeLeft->next;
    }
    chainNode<T> *NodeRight = NodeLeft;
    chainNode<T> *preNodeRight = nullptr;
    for (int index = left; index < right; index++)
    {
        // cout<<"NodeLeft->next = "<<NodeLeft->next<<endl;
        preNodeRight = NodeRight;
        NodeRight = NodeRight->next;
    }
    if (preNodeLeft == nullptr)
    {
        chainNode<T> *tempRight = NodeRight->next;
        chainNode<T> *tempLeft = NodeLeft->next;
        this->firstNode = NodeRight;
        if (NodeLeft->next == NodeRight)
        {
            NodeLeft->next = tempRight;
            NodeRight->next = NodeLeft;
        }
        else
        {
            NodeRight->next = tempLeft;
            preNodeRight->next = NodeLeft;
            NodeLeft->next = tempRight;
        }
    }
    else
    {
        // chainNode<T> *tempRight = NodeRight->next;
        chainNode<T> *tempLeft = NodeLeft->next;
        preNodeLeft->next = NodeRight;
        // cout<<"NodeLeft->next = "<<NodeLeft->next<<endl;
        // cout<<"NodeRight = "<<NodeRight<<endl;
        if (NodeLeft->next == NodeRight)
        {
            NodeLeft->next = NodeRight->next;
            // cout << NodeLeft->element << endl;
            // cout << NodeRight->element << endl;
            NodeRight->next = NodeLeft;
        }
        else
        {
            // cout << NodeLeft->element << endl;
            // cout << NodeRight->element << endl;
            NodeLeft->next = NodeRight->next;
            NodeRight->next = tempLeft;
            preNodeRight->next = NodeLeft;
        }
    }
}
template <class T>
void chainList<T>::swap(int index1, int index2)
{
    checkIndex(index1);
    checkIndex(index2);
    if (index1 == index2)
        return;
    int right = (index1 > index2 ? index1 : index2);
    int left = (index1 <= index2 ? index1 : index2);
    chainNode<T> *NodeLeft = this->firstNode;
    // chainNode<T> *preNodeLeft = nullptr;
    for (int index = 0; index < left; index++)
    {
        NodeLeft = NodeLeft->next;
    }
    chainNode<T> *NodeRight = NodeLeft;
    for (int index = left; index < right; index++)
    {
        NodeRight = NodeRight->next;
    }
    T tempElement = NodeLeft->element;
    NodeLeft->element = NodeRight->element;
    NodeRight->element = tempElement;
}
template <class T>
void chainList<T>::setSize(int theSize)
{
    if (theSize >= this->listSize)
    {
        return;
    }
    chainNode<T> *Node = this->firstNode;
    for (int index = 0; index < theSize - 1; index++)
    {
        Node = Node->next;
    }
    chainNode<T> *nextNode = Node->next;
    Node->next = nullptr;
    while (nextNode != nullptr)
    {
        chainNode<T> *temp = nextNode->next;
        delete nextNode;
        nextNode = temp;
    }
    this->listSize = theSize;
}
template <class T>
void chainList<T>::clear()
{
    while (this->firstNode != nullptr)
    {
        chainNode<T> *nextNode = this->firstNode->next;
        delete this->firstNode;
        this->firstNode = nextNode;
    }
    this->listSize = 0;
}
template <class T>
void sort(chainList<T> &list) // 真的好吗？ 使用swap方法与get方法使得时间复杂度增高，效率比一般的冒泡排序还要低
{
    // chainNode<T> *Node;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list.size() - i - 1; j++)
        {
            if (list.get(j) > list.get(j + 1))
            {
                list.swap(j, j + 1);
            }
        }
    }
}
template <class T>
arrayList<T> convertToArray(const chainList<T> &chaninList)
{
    arrayList<T> arrayList(chaninList.size());
    for (int i = 0; i < chaninList.size(); i++)
    {
        arrayList.push_back(chaninList.get(i));
    }
    return arrayList;
}
#endif