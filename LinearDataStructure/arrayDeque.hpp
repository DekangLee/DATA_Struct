#ifndef _ARRAYDEQUEH_
#define _ARRAYDEQUEH_
#include <iostream>
using namespace std;
#include "deque.hpp"
#include "myExpectation.h"
template <class T>
class arrayDeque : public deque<T>
{
public:
    arrayDeque(int capacity = 5, int groupMax = 5)
    {
        this->arraylenth = capacity;
        this->groupMax = groupMax;
        this->element = new T *[this->groupMax];
        for (int i = 0; i < groupMax; i++)
        {
            if (i == groupMax / 2)
                this->element[i] = new T[this->arraylenth];
            else
                this->element[i] = nullptr;
        }
        dequeFront = 0; // 记录队首的偏移量,总是指向第一个元素的前一个位置
        dequeBack = -1; // 记录队尾的偏移量,总是指向最后一个元素的后一个位置
    }
    ~arrayDeque();
    bool empty() const;
    int size() const;
    T &front();
    T &back();
    void pop_front();
    void pop_back();
    void push_back(const T &theElement);
    void push_front(const T &theElement);
    void output() const
    {
        for (int i = this->dequeFront - 1; i > this->dequeBack; i--)
        {
            int pos1;
            int pos2;
            this->map(i, pos1, pos2);
            cout << this->element[pos1][pos2] << " ";
        }
    }
    T &operator[](int i)
    {
        if (i < 0 || i >= (this->dequeFront - this->dequeBack - 1))
            throw queueEmpty("Illeagel pamameter!");
        int pos1;
        int pos2;
        this->map(this->dequeFront - i - 1, pos1, pos2);
        return this->element[pos1][pos2];
    }
    class iterator;
    iterator begin()
    {
        int pos1;
        int pos2;
        this->map(this->dequeFront-1,pos1,pos2);
        return iterator(this->element+pos1, this->element[pos1] + pos2);
    }
    iterator end()
    {
        int pos1;
        int pos2;
        this->map(this->dequeBack,pos1,pos2);
        return iterator(this->element+pos1, this->element[pos1] + pos2);
    }
private:
    void map(const int &pos, int &pos1, int &pos2) const;
    T **element;
    int dequeFront;
    int dequeBack;
    int arraylenth;
    int groupMax;
};
template <class T>
arrayDeque<T>::~arrayDeque()
{
    for (int i = 0; i < this->groupMax; i++)
    {
        // cout << this->element[i] << ": ";
        if (this->element[i] != nullptr)
        {
            // for (int j = 0; j < this->arraylenth; j++)
            // {
            //     cout << this->element[i][j] << " ";
            // }
            delete[] this->element[i];
            this->element[i] = nullptr;
        }
        // cout << endl;
    }
    if (this->element != nullptr)
        delete[] this->element;
}
template <class T>
bool arrayDeque<T>::empty() const
{
    return this->dequeFront - 1 == this->dequeBack;
}
template <class T>
int arrayDeque<T>::size() const
{
    return this->dequeFront - this->dequeBack - 1;
}
template <class T>
void arrayDeque<T>::map(const int &pos, int &pos1, int &pos2) const // 位置映射函数，后面要一直用到
{
    int base = groupMax / 2;
    int bias = (pos) / this->arraylenth;
    pos1 = base - bias;
    pos2 = (-pos) % this->arraylenth;
    if (pos > 0)
    {
        bias = (pos - 1) / this->arraylenth;
        pos1 = base - bias - 1;
        pos2 = (pos - 1) % this->arraylenth;
        pos2 = this->arraylenth - 1 - pos2;
    }
}
template <class T>
void arrayDeque<T>::push_back(const T &theElement)
{
    int base = groupMax / 2;
    int bias = (this->dequeBack) / this->arraylenth;
    if (base - bias >= this->groupMax)
    {

        T **newGroup = new T *[2 * this->groupMax];
        int count = 0;
        for (int i = 0; i < 2 * this->groupMax; i++)
        {
            if ((i >= (this->groupMax - this->groupMax / 2)) && (i <= (this->groupMax + (this->groupMax / 2))))
            {
                newGroup[i] = this->element[count];
                count++;
            }
            else
                newGroup[i] = nullptr;
        }
        // cout << "count = " << count << endl;
        delete[] this->element;
        this->element = newGroup;
        this->groupMax *= 2;
    }
    int pos1;
    int pos2;
    this->map(this->dequeBack, pos1, pos2);
    if (this->element[pos1] == nullptr)
    {
        this->element[pos1] = new T[this->arraylenth];
    }
    this->element[pos1][pos2] = theElement;
    this->dequeBack--;
}
template <class T>
void arrayDeque<T>::push_front(const T &theElement)
{
    // cout << "groupMax = " << this->groupMax << endl;
    int base = groupMax / 2;
    int bias = (this->dequeFront - 1) / this->arraylenth;
    if (base - bias - 1 < 0)
    {
        T **newGroup = new T *[2 * this->groupMax];
        int count = 0;
        for (int i = 0; i < 2 * this->groupMax; i++)
        {
            if (i >= (this->groupMax - (this->groupMax / 2)) && i <= (this->groupMax + (this->groupMax / 2)))
            {
                newGroup[i] = this->element[count];
                count++;
            }
            else
            {
                newGroup[i] = nullptr;
            }
        }
        delete[] this->element;
        this->element = newGroup;
        this->groupMax *= 2;
    }
    int pos1;
    int pos2;
    // cout << "this->dequeFront = " << this->dequeFront << endl;
    this->map(this->dequeFront, pos1, pos2);
    // cout << "pos1 : " << pos1 << "  pos2 : " << pos2 << endl;
    if (this->element[pos1] == nullptr)
    {
        this->element[pos1] = new T[this->arraylenth];
    }
    this->element[pos1][pos2] = theElement;
    this->dequeFront++;
}
template <class T>
void arrayDeque<T>::pop_back()
{
    if (this->dequeBack + 1 == this->dequeFront)
        throw queueEmpty("Deque is empty.");
    int pos1;
    int pos2;
    this->map(this->dequeBack + 1, pos1, pos2);
    this->element[pos1][pos2].~T();
    this->dequeBack++;
}
template <class T>
void arrayDeque<T>::pop_front()
{
    if (this->dequeFront - 1 == this->dequeBack)
        throw queueEmpty("Deque is empty.");
    int pos1;
    int pos2;
    this->map(this->dequeFront - 1, pos1, pos2);
    this->element[pos1][pos2].~T();
    this->dequeFront--;
}
template <class T>
T &arrayDeque<T>::front()
{
    if (this->dequeFront - 1 == this->dequeBack)
        throw queueEmpty("Deque is empty.");
    int pos1;
    int pos2;
    this->map(this->dequeFront - 1, pos1, pos2);
    return this->element[pos1][pos2];
}
template <class T>
T &arrayDeque<T>::back()
{
    if (this->dequeFront - 1 == this->dequeBack)
        throw queueEmpty("Deque is empty.");
    int pos1;
    int pos2;
    this->map(this->dequeBack + 1, pos1, pos2);
    return this->element[pos1][pos2];
}
template <class T>
ostream &operator<<(ostream &cout, const arrayDeque<T> &deque)
{
    deque.output();
    return cout;
}
template <class T>
class arrayDeque<T>::iterator
{
public:
    iterator();
    iterator(const iterator &it)
    {
        this->pos1 = it.pos1;
        this->pos2 = it.pos2;
    }
    iterator(T **pos1, T *pos2);
    T &operator*()
    {
        return *(pos2);
    }
    T &operator->();
    iterator &operator++()
    {
        
    }
   iterator operator++(int)
   {

   }
private:
    T **pos1;
    T *pos2;
};
template <class T>
arrayDeque<T>::iterator::iterator()
{
    this->position = nullptr;
}
template <class T>
arrayDeque<T>::iterator::iterator(T **pos1, T *pos2)
{
    this->pos1 = pos1;
    this->pos2 = pos2;
}

#endif