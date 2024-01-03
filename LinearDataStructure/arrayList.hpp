#ifndef _ARRAYLISTH_
#define _ARRAYLISTH_
#include <iostream>
#include <sstream>
#include <algorithm>
#include "myExpectation.h"
#include "linearList.hpp"

template <class T>
class arrayList : public linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList()
    {
        delete[] this->element;
    }
    bool empty() const
    {
        return this->listSize == 0;
    }
    int size() const
    {
        return this->listSize;
    }
    T &get(int theIndex) const;                     // 常数时间复杂度
    int indexOf(const T &theElement) const;         // 线性时间复杂度
    void erase(int theIndex);                       // 线性时间复杂度
    void insert(int theIndex, const T &theElement); // 线性时间复杂度
    void output(ostream &out) const;
    void push_back(const T &theElement);
    void setSize(int theSize);
    void resetSize(int theSize)
    {
        if (this->element != nullptr)
        {
            delete[] this->element;
            this->element = nullptr;
        }
        this->listSize = theSize;
        this->arrayLength = theSize;
        this->element = new T[this->arrayLength];
    }
    void set(int index, const T &element)
    {
        if (index < 0 || index >= this->listSize)
        {
            throw illegalParameterValue("Error ! Out of bounds.");
        }
        this->element[index] = element;
    }
    void reset(int size)
    {
        if (this->element != nullptr)
        {
            delete[] this->element;
        }
        this->element = new T[size];
        this->listSize = 0;
        this->arrayLength = size;
    }
    arrayList<T> &operator=(const arrayList<T> &arrayList);
    T max();
    // void sort(iterator<T> _start, iterator<T> _last, bool (*f));
    int capacity() const
    {
        return this->arrayLength;
    }
    T &operator[](int theIndex)
    {
        this->checkIndex(theIndex);
        return this->element[theIndex];
    }
    class iterator
    {
    public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        iterator(T *thePosition = nullptr)
        {
            this->position = thePosition;
        }
        iterator(const iterator &RightIterator)
        {
            this->position = RightIterator.position;
        }
        T &operator*() const
        {
            return *position;
        }
        T *operator->() const
        {
            return &(*position);
        }
        iterator &operator++();  // 前置递增
        iterator operator++(int) // 后置递增
        {
            iterator temp = *this;
            this->position++;
            return temp;
        }
        iterator &operator--() // 前置递减
        {
            --this->position;
            return *this;
        }
        iterator operator--(int) // 后置递减
        {
            iterator temp = *this;
            this->position--;
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
        iterator operator-(int num)
        {
            this->position - num;
            return *this;
        }

    private:
        T *position = nullptr;
    };
    void sort(iterator _first, iterator _second, bool (*f)(T, T));
    iterator begin() const
    {
        return iterator(this->element);
    }
    iterator end() const
    {
        return iterator(this->element + this->listSize);
    }

private:
    void checkIndex(int TheIndex) const;
    T *element;
    int arrayLength;
    int listSize;
};
template <class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    this->arrayLength = initialCapacity;
    this->element = new T[this->arrayLength];
    this->listSize = 0;
}
template <class T>
arrayList<T>::arrayList(const arrayList<T> &arr1)
{
    this->arrayLength = arr1.arrayLength;
    this->element = new T[this->arrayLength];
    for (int i = 0; i < arr1.size(); i++)
    {
        this->element[i] = arr1.get(i);
    }
    this->listSize = arr1.size();
}
template <class T>
void arrayList<T>::checkIndex(int theIndex) const // 检查索引是否越界
{
    if (theIndex < 0 || theIndex >= this->listSize)
    {
        ostringstream s;
        s << "error! index = " << theIndex << " but size = " << this->listSize;
        throw illegalIndex(s.str());
    }
}
template <class T>
T &arrayList<T>::get(int theIndex) const
{
    try
    {
        this->checkIndex(theIndex);
    }
    catch (illegalIndex &ileidx)
    {
        ileidx.outputMessage();
    }
    return element[theIndex];
}
template <class T>
T arrayList<T>::max()
{
    if (this->listSize == 0)
    {
        ostringstream tip;
        tip << "The size of this list is zero!";
        throw illegalParameterValue(tip.str());
    }
    T max = this->element[0];
    for (int i = 0; i < this->listSize; i++)
    {
        if (this->element[i] > max)
        {
            max = this->element[i];
        }
    }
    return max;
}
template <class T>
int arrayList<T>::indexOf(const T &theElement) const
{
    int theIndex = (int)(find(this->element, this->element + this->listSize, theElement) - element);
    if (theIndex == this->listSize)
        return -1;
    else
        return theIndex;
}
template <class T>
void arrayList<T>::erase(int theIndex)
{
    this->checkIndex(theIndex);
    T *temp = this->element;
    this->element = new T[this->arrayLength];
    for (int i = 0; i < theIndex; i++)
    {
        this->element[i] = temp[i];
    }
    for (int i = theIndex + 1; i < this->listSize; i++)
    {
        this->element[i - 1] = temp[i];
    }
    this->listSize--;
    delete[] temp;
}
template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex >= this->listSize)
    {
        ostringstream tip;
        tip << "error! index = " << theIndex << " but size = " << this->listSize;
        throw illegalIndex(tip.str());
        // return ;
    }
    if (this->listSize == this->arrayLength)
    {
        this->arrayLength *= 2;
    }
    T *temp = this->element;
    this->element = new T[this->arrayLength];
    listSize++;
    for (int i = 0; i < theIndex; i++)
    {
        this->element[i] = temp[i];
    }
    this->element[theIndex] = theElement;
    for (int i = theIndex + 1; i < this->listSize; i++)
    {
        this->element[i] = temp[i - 1];
    }
    delete[] temp;
}
template <class T>
void arrayList<T>::output(ostream &cout) const
{
    for (int i = 0; i < this->listSize; i++)
    {
        cout << this->element[i] << " ";
    }
    // cout << endl;
}
template <class T>
void arrayList<T>::push_back(const T &theElement)
{
    if (this->listSize == this->arrayLength)
    {
        this->arrayLength *= 2;
        T *temp = this->element;
        this->element = new T[this->arrayLength];
        for (int i = 0; i < this->listSize; i++)
        {
            this->element[i] = temp[i];
        }
        this->element[this->listSize++] = theElement;
    }
    else
    {
        this->element[this->listSize++] = theElement;
    }
}
template <class T>
void arrayList<T>::setSize(int theSize)
{
    if (this->listSize > theSize)
    {
        this->listSize = theSize;
        if (this->listSize < this->arrayLength / 4)
        {
            T *temp = this->element;
            this->arrayLength = std::max(10, this->arrayLength / 2);
            this->element = new T[this->arrayLength];
            for (int i = 0; i < this->listSize; i++)
            {
                this->element[i] = temp[i];
            }
        }
    }
}
template <class T>
ostream &operator<<(ostream &cout, const arrayList<T> &List)
{
    List.output(cout);
    return cout;
}
template <typename T>
class arrayList<T>::iterator &arrayList<T>::iterator::operator++() // 前置递增
{
    ++this->position;
    return *this;
};
template <class T>
arrayList<T> &arrayList<T>::operator=(const arrayList<T> &arrayList)
{
    this->arrayLength = arrayList.arrayLength;
    delete[] this->element;
    this->element = new T[this->arrayLength];
    this->listSize = arrayList.listSize;
    for (int i = 0; i < this->listSize; i++)
    {
        this->element[i] = arrayList.element[i];
    }
    return *this;
}
template <class T>
void arrayList<T>::sort(iterator _first, iterator _second, bool (*f)(T, T))
{
    for (; _first != _second; _first++)
    {
        iterator temp;
        temp = _first;
        for (iterator it = _first; it != _second; it++)
        {
            if (!f(*temp, *it))
            {
                temp = it;
            }
            // cout << "temp = " << *temp << endl;
        }
        // cout << "----------------------------" << endl;
        T tempElement;
        tempElement = *temp;
        *temp = *_first;
        *_first = tempElement;
        // cout << "_first = " << *_first << endl;
    }
}

#endif