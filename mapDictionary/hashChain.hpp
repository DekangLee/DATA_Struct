#ifndef _HASHCHAINH_
#define _HASHCHAINH_
#include <iostream>
#include "dictionary.hpp"
using namespace std;
template <class K, class E>
struct hashNode
{
    pair<K, E> element;
    hashNode<K, E> *next;
    hashNode<K, E> *previous;
    hashNode(){};
    hashNode(const pair<K, E> &thePair)
    {
        this->element.first = thePair.first;
        this->element.second = thePair.second;
    }
    hashNode(const hashNode<K, E> &rHashNode)
    {
        this->element.first = rHashNode.element.first;
        this->element.second = rHashNode.element.second;
        this->next = rHashNode.next;
        this->previous = rHashNode.previous;
    }
};
template <class K, class E>
class hashChain : public dictionary<K, E>
{
public:
    hashChain()
    {
        this->dSize = 0;
        this->headNode = new hashNode<K, E> *[this->divisor + 1];
        this->tailNode = new hashNode<K, E> *[this->divisor + 1];
        // cout << this->headNode[1]->next << endl;
        for (int i = 0; i < this->divisor; i++)
        {
            this->headNode[i] = new hashNode<K, E>;
            this->tailNode[i] = new hashNode<K, E>;
            this->headNode[i]->next = this->tailNode[i];
            this->tailNode[i]->previous = this->headNode[i];
        }
    }
    ~hashChain()
    {
        for (int i = 0; i < this->divisor; i++)
        {
            hashNode<K, E> *Node = this->headNode[i]->next;
            while (Node != this->tailNode[i])
            {
                hashNode<K, E> *nextNode = Node->next;
                delete Node;
                Node = nextNode;
            }
            delete this->headNode[i];
            delete this->tailNode[i];
        }
        delete[] this->headNode;
        delete[] this->tailNode;
    }
    void insert(const pair<K, E> &thePair);
    int search(const K &) const;
    pair<K, E> *find(const K &theKey) const;
    bool empty() const
    {
        return this->dSize == 0;
    }
    int size() const
    {
        return this->dSize;
    }
    void erase(const K &);
    void output() const;
    E &operator[](const K &theKey);

private:
    int dSize;
    hashNode<K, E> **tailNode;
    hashNode<K, E> **headNode;
    hash<K> hash;
    const int divisor = 997;
};
template <class K, class E>
void hashChain<K, E>::insert(const pair<K, E> &thePair)
{
    int i = this->search(thePair.first);
    hashNode<K, E> *Node = this->headNode[i]->next;
    while (Node != this->tailNode[i])
    {
        if (Node->element.first == thePair.first)
        {
            Node->element.second = thePair.second;
            return;
        }
    }
    hashNode<K, E> *newNode = new hashNode<K, E>(thePair);
    hashNode<K, E> *preNode = this->tailNode[i]->previous;
    preNode->next = newNode;
    newNode->previous = preNode;
    newNode->next = this->tailNode[i];
    this->tailNode[i]->previous = newNode;
    this->dSize++;
}
template <class K, class E>
int hashChain<K, E>::search(const K &theKey) const
{
    int i = (unsigned long long)this->hash(theKey) % this->divisor;
    return i;
}
template <class K, class E>
void hashChain<K, E>::erase(const K &theKey)
{
    int i = this->search(theKey);
    hashNode<K, E> *Node = this->headNode[i]->next;
    while (Node != this->tailNode[i])
    {
        if (Node->element.first == theKey)
        {
            break;
        }
    }
    if (Node != this->tailNode[i])
    {
        hashNode<K, E> *preNode = Node->previous;
        hashNode<K, E> *nextNode = Node->next;
        delete Node;
        preNode->next = nextNode;
        nextNode->previous = preNode;
        this->dSize--;
    }
}
template <class K, class E>
void hashChain<K, E>::output() const
{
    for (int i = 0; i < this->divisor; i++)
    {
        if (this->headNode[i]->next == this->tailNode[i])
            continue;
        hashNode<K, E> *Node = this->headNode[i]->next;
        while (Node != this->tailNode[i])
        {
            cout << "(" << Node->element.first << "," << Node->element.second << ")" << endl;
            Node = Node->next;
        }
    }
}
template <class K, class E>
pair<K, E> *hashChain<K, E>::find(const K &theKey) const
{
    int i = this->search(theKey);
    hashNode<K, E> *Node = this->headNode[i]->next;
    while (Node != this->tailNode[i])
    {
        if (Node->element.first == theKey)
            break;
        Node = Node->next;
    }
    if (Node == this->tailNode[i])
        return nullptr;
    return &Node->element;
}
template <class K, class E>
E &hashChain<K, E>::operator[](const K &theKey)
{
    int i = this->search(theKey);
    hashNode<K, E> *Node = this->headNode[i]->next;
    while (Node != this->tailNode[i])
    {
        if (Node->element.first == theKey)
            break;
    }
    if (Node == this->tailNode[i])
    {
        hashNode<K, E> *newNode = new hashNode<K, E>(make_pair(theKey, E()));
        hashNode<K, E> *preNode = Node->previous;
        preNode->next = newNode;
        newNode->previous = preNode;
        newNode->next = Node;
        Node->previous = newNode;
        return newNode->element.second;
    }
    return Node->element.second;
}
#endif