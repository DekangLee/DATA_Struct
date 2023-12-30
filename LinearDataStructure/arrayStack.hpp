#ifndef _ARRAYSTACKH_
#define _ARRAYSTACKH_
#include <iostream>
#include <sstream>
#include "linearList.hpp"
#include <algorithm>
template <class T>
class arrayStack : public stack<T>
{
public:
    arrayStack(int initialCapacity = 10);
    arrayStack(const arrayStack<T> &);
    ~arrayStack()
    {
        if (this->stack != nullptr)
        {
            delete[] this->stack;
            this->stack = nullptr;
        }
    }
    bool empty() const
    {
        return this->stackTop == -1;
    }
    int size() const
    {
        return this->stackTop + 1;
    }
    T &top()
    {
        if (this->stackTop != -1)
        {
            return this->stack[this->stackTop];
        }
        else
        {
            throw stackEmpty("The stack is empty!");
        }
    }
    void pop()
    {
        if (this->stackTop == -1)
        {
            throw stackEmpty("The stack is empty!");
        }
        this->stack[this->stackTop--].~T();
    }
    // 从栈顶向下输入
    void output(ostream &cout) const;
    void push(const T &theElement);
    arrayStack<T> merge(const arrayStack<T> &) const;
    arrayStack<T> &operator=(const arrayStack<T> &RightStack)
    {
        if (this->stack != nullptr)
        {
            delete[] this->stack;
            this->stack = nullptr;
        }
        this->arrayLenth = RightStack.arrayLenth;
        this->stack = new T[this->arrayLenth];
        if (RightStack.stackTop == -1)
            return *this;
        copy(RightStack.stack, RightStack.stack + RightStack.stackTop + 1, this->stack);
        this->stackTop = RightStack.stackTop;
        return *this;
    }
    // linkedStack<T>& operator=(const linkedStack<T>&);

private:
    int stackTop;   // 当前栈顶
    int arrayLenth; // 栈容量
    T *stack;
};
template <class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream error;
        error << "Inital capacity = " << initialCapacity << " Must be > 0!";
        throw illegalParameterValue(error.str());
    }
    this->arrayLenth = initialCapacity;
    this->stack = new T[this->arrayLenth];
    this->stackTop = -1; // 注意栈顶的初始位置
}
template <class T>
arrayStack<T>::arrayStack(const arrayStack<T> &RightStack)
{
    this->arrayLenth = RightStack.arrayLenth;
    this->stack = new T[this->arrayLenth];
    if (RightStack.stackTop == -1)
        return;
    copy(RightStack.stack, RightStack.stack + RightStack.stackTop + 1, this->stack);
    this->stackTop = RightStack.stackTop;
}
template <class T>
void arrayStack<T>::push(const T &element)
{
    if (this->stackTop == this->arrayLenth - 1)
    {
        this->arrayLenth *= 2;
        T *newStack = new T[this->arrayLenth];
        copy(this->stack, this->stack + this->stackTop + 1, newStack);
        delete[] this->stack;
        this->stack = newStack;
    }
    this->stack[++this->stackTop] = element;
}
template <class T>
arrayStack<T> arrayStack<T>::merge(const arrayStack<T> &RightStack) const
{
    arrayStack<T> resStack(this->arrayLenth + RightStack.arrayLenth);
    resStack.arrayLenth = this->arrayLenth + RightStack.arrayLenth;
    resStack.stackTop = this->stackTop + RightStack.stackTop + 1;
    copy(this->stack, this->stack + this->stackTop + 1, resStack.stack);
    copy(RightStack.stack, RightStack.stack + RightStack.stackTop + 1, resStack.stack + this->stackTop + 1);
    return resStack;
}
template <class T>
void arrayStack<T>::output(ostream &cout) const
{
    for (int i = this->stackTop; i >= 0; i--)
    {
        cout << this->stack[i] << endl;
    }
}
template <class T>
ostream &operator<<(ostream &cout, const arrayStack<T> &RightStack)
{
    RightStack.output(cout);
    return cout;
}
#endif