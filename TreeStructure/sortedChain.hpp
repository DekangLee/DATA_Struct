#ifndef _SORTEDARRAYLISTH_
#define _SORTEDARRAYLISTH_
#include <iostream>
using namespace std;
template <class K, class E>
struct _Pair
{
    K first;
    E second;
    _Pair(){};
    _Pair(const K &first, const E &second)
    {
        this->first = first;
        this->second = second;
    }
    _Pair<K, E> &operator=(const _Pair<K, E> &rightP)
    {
        this->first = rightP.first;
        this->second = rightP.second;
    }
};
template <class K, class E>
_Pair<K, E> _make_pair(const K &first, const E &second)
{
    return _Pair<K, E>(first, second);
}
template <class K, class E>
struct chainNode
{
    _Pair<K, E> element;
    chainNode<K, E> *next;
    chainNode<K, E> *previous;
    chainNode(){};
    chainNode(const _Pair<K, E> &theElenemt)
    {
        this->element.first = theElenemt.first;
        this->element.second = theElenemt.second;
    }
};
template <class K, class E>
class chainIterator;
template <class K, class E>
class sortedChain
{
public:
    sortedChain()
    {

        this->firstNode = new chainNode<K, E>;
        this->lastNode = new chainNode<K, E>;
        this->firstNode->next = this->lastNode;
        this->lastNode->previous = this->firstNode;
        this->chainSize = 0;
    }
    ~sortedChain()
    {

        while (this->firstNode->next != this->lastNode)
        {
            chainNode<K, E> *Node = this->firstNode->next;
            if (this->firstNode != nullptr)
            {
                delete this->firstNode;
                this->firstNode = Node;
            }
        }
        delete this->lastNode;
    }
    _Pair<K, E> *find(const K &theKey);
    void erase(const K &);
    void insert(const _Pair<K, E> &thePair);
    typedef chainIterator<K, E> iterator;
    iterator begin()
    {
        return iterator(this->firstNode->next);
    }
    iterator end()
    {
        return iterator(this->lastNode);
    }
    int size() const
    {
        return this->chainSize;
    }
    void output() const
    {
        chainNode<K, E> *Node = this->firstNode->next;
        while (Node != lastNode)
        {
            cout << "first = " << Node->element.first << " second = " << Node->element.second << endl;
            Node = Node->next;
        }
    }
    void rOutput() const
    {
        chainNode<K, E> *Node = this->lastNode->previous;
        while (Node != this->firstNode)
        {
            cout << "first = " << Node->element.first << " second = " << Node->element.second << endl;
            Node = Node->previous;
        }
    }
    E &front() const
    {
        return lastNode->previous->element.second;
    }
    E &back() const
    {
        return firstNode->next->element.second;
    }
    void pop()
    {
        chainNode<K, E> *preNode = this->lastNode->previous;
        preNode = preNode->previous;
        delete this->lastNode->previous;
        preNode->next = this->lastNode;
        this->lastNode->previous = preNode;
        this->chainSize--;
    }

private:
    chainNode<K, E> *firstNode;
    chainNode<K, E> *lastNode;
    int chainSize;
};
template <class K, class E>
_Pair<K, E> *sortedChain<K, E>::find(const K &theKey)
{
    chainNode<K, E> *currentNode = this->firstNode;
    while (currentNode != this->lastNode && currentNode->element.first != theKey)
    {
        currentNode = currentNode->next;
    }
    if (currentNode != this->lastNode && currentNode->element.first == theKey)
    {
        return &currentNode->element;
    }
    return nullptr;
}
template <class K, class E>
void sortedChain<K, E>::insert(const _Pair<K, E> &thePair)
{
    if (this->firstNode->next == this->lastNode)
    {
        chainNode<K, E> *newNode = new chainNode<K, E>(thePair);
        this->firstNode->next = newNode;
        newNode->next = this->lastNode;
        this->lastNode->previous = newNode;
        newNode->previous = this->firstNode;
        this->chainSize++;
        return;
    }
    chainNode<K, E> *p = this->firstNode;
    while (p != this->lastNode && p->element.first < thePair.first)
    {
        p = p->next;
    }
    if (p != this->lastNode && p->element.first == thePair.first)
    {
        p->element.second = thePair.second;
        return;
    }
    chainNode<K, E> *newNode = new chainNode<K, E>(thePair);
    chainNode<K, E> *pre = p->previous;
    pre->next = newNode;
    newNode->previous = pre;
    newNode->next = p;
    p->previous = newNode;
    this->chainSize++;
}
template <class K, class E>
void sortedChain<K, E>::erase(const K &theKey)
{
    chainNode<K, E> *p = firstNode->next;
    while (p != this->lastNode)
    {
        if (p->element.first == theKey)
        {
            break;
        }
        p = p->next;
    }
    if (p != this->lastNode)
    {
        chainNode<K, E> *preNode = p->previous;
        chainNode<K, E> *nextNode = p->next;
        delete p;
        preNode->next = nextNode;
        nextNode->previous = preNode;
        this->chainSize--;
    }
}
template <class K, class E>
class chainIterator
{
public:
    chainIterator(chainNode<K, E> *theNode = nullptr)
    {
        this->Node = theNode;
    };
    chainIterator(const chainIterator<K, E> &it)
    {
        this->Node = it.Node;
    }
    _Pair<K, E> &operator*();
    chainIterator<K, E> &operator++();
    chainIterator<K, E> operator++(int);
    chainIterator<K, E> &operator--();
    chainIterator<K, E> operator--(int);
    bool operator==(const chainIterator<K, E> &right)
    {
        return this->Node == right.Node;
    }
    bool operator!=(const chainIterator<K, E> &right)
    {
        return this->Node != right.Node;
    }

private:
    chainNode<K, E> *Node;
};
template <class K, class E>
_Pair<K, E> &chainIterator<K, E>::operator*()
{
    return this->Node->element;
}
template <class K, class E>
chainIterator<K, E> &chainIterator<K, E>::operator++()
{
    this->Node = this->Node->next;
    return *this;
}
template <class K, class E>
chainIterator<K, E> chainIterator<K, E>::operator++(int)
{
    chainIterator<K, E> temp(this->Node);
    this->Node = this->Node->next;
    return temp;
}
template <class K, class E>
chainIterator<K, E> &chainIterator<K, E>::operator--()
{
    this->Node = this->Node->previous;
    return *this;
}
template <class K, class E>
chainIterator<K, E> chainIterator<K, E>::operator--(int)
{
    chainIterator<K, E> temp(this->Node);
    this->Node = this->Node->previous;
    return temp;
}
#endif