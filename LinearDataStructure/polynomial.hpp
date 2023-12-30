#pragma once
#include <iostream>
#include "linearList.hpp"
#include "chainList.hpp"
#include "arrayList.hpp"
#include <cmath>
#include <sstream>
#include "myExpectation.h"
using namespace std;
template <class T>
class polynomial_Array
{
public:
    polynomial_Array();
    polynomial_Array(const polynomial_Array<T> &p);
    polynomial_Array(const arrayList<T> &list);
    ~polynomial_Array();
    int degree();
    polynomial_Array<T> add(const polynomial_Array<T> &p);
    polynomial_Array<T> operator+(const polynomial_Array<T> &p)
    {
        return this->add(p);
    }
    void input(const arrayList<T> &list);
    arrayList<T> output();
    arrayList<T> operator<<(const polynomial_Array<T> &p)
    {
        return this->output();
    }
    polynomial_Array<T> subtract(const polynomial_Array<T> &p);
    polynomial_Array<T> operator-(const polynomial_Array<T> &p)
    {
        return this->subtract(p);
    }
    polynomial_Array<T> multiply(const polynomial_Array<T> &p);
    polynomial_Array<T> operator*(const polynomial_Array<T> &p)
    {
        return this->multiply(p);
    }
    polynomial_Array<T> divide(const polynomial_Array<T> &p);
    polynomial_Array<T> &operator=(const polynomial_Array<T> &p);
    T valueOf(T x);
    T operator()(T x);

private:
    int _n;
    arrayList<T> *factorList;
};
template <class T>
polynomial_Array<T>::polynomial_Array()
{
    this->_n = 0;
    this->factorList = nullptr;
}
template <class T>
polynomial_Array<T>::polynomial_Array(const arrayList<T> &list)
{
    this->_n = list.size();
    if (this->_n == 0)
        return;
    this->factorList = new arrayList<T>;
    this->factorList->operator=(list);
}
template <class T>
polynomial_Array<T>::polynomial_Array(const polynomial_Array<T> &p)
{
    this->_n = p._n;
    this->factorList = new arrayList<T>(*p.factorList);
}
template <class T>
polynomial_Array<T>::~polynomial_Array()
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
    }
}
template <class T>
void polynomial_Array<T>::input(const arrayList<T> &list)
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
    }
    this->_n = list.size();
    this->factorList = new arrayList<T>(list);
}
template <class T>
arrayList<T> polynomial_Array<T>::output()
{
    return *this->factorList;
}
template <class T>
int polynomial_Array<T>::degree()
{
    return this->_n;
}
template <class T>
polynomial_Array<T> polynomial_Array<T>::add(const polynomial_Array<T> &p)
{
    polynomial_Array<T> res;
    arrayList<T> resL;
    if (this->_n > p._n)
    {
        for (int i = 0; i < p._n; i++)
        {
            resL.push_back(this->factorList->get(i) + p.factorList->get(i));
        }
        for (int i = p._n; i < this->_n; i++)
        {
            resL.push_back(this->factorList->get(i));
        }
    }
    else
    {
        for (int i = 0; i < this->_n; i++)
        {
            resL.push_back(this->factorList->get(i) + p.factorList->get(i));
        }
        for (int i = this->_n; i < p._n; i++)
        {
            resL.push_back(p.factorList->get(i));
        }
    }
    res.input(resL);
    return res;
}
template <class T>
polynomial_Array<T> polynomial_Array<T>::subtract(const polynomial_Array<T> &p)
{
    polynomial_Array<T> res;
    arrayList<T> resL;
    if (this->_n > p._n)
    {
        for (int i = 0; i < p._n; i++)
        {
            resL.push_back(this->factorList->get(i) - p.factorList->get(i));
        }
        for (int i = p._n; i < this->_n; i++)
        {
            resL.push_back(this->factorList->get(i));
        }
    }
    else
    {
        for (int i = 0; i < this->_n; i++)
        {
            resL.push_back(this->factorList->get(i) - p.factorList->get(i));
        }
        for (int i = this->_n; i < p._n; i++)
        {
            resL.push_back(p.factorList->get(i));
        }
    }
    res.input(resL);
    return res;
}
template <class T>
polynomial_Array<T> polynomial_Array<T>::multiply(const polynomial_Array<T> &p)
{
    polynomial_Array<T> res;
    arrayList<T> resL;
    for (int i = 0; i < this->_n + p._n - 1; i++)
    {
        // cout<<i<<endl;
        resL.push_back(0);
    }
    for (int i = 0; i < this->_n; i++)
    {
        for (int j = 0; j < p._n; j++)
        {
            resL[j + i] += this->factorList->get(i) * p.factorList->get(j);
        }
    }

    return polynomial_Array(resL);
}
template <class T>
polynomial_Array<T> polynomial_Array<T>::divide(const polynomial_Array<T> &p)
{
}
template <class T>
T polynomial_Array<T>::valueOf(T x)
{
    T res = this->factorList->get(this->_n - 1);
    for (int i = this->_n - 2; i >= 0; i--)
    {
        // cout << "---------" << endl;
        res *= x;
        res += this->factorList->get(i);
        // cout << "res = " << res << endl;
    }
    return res;
}
template <class T>
T polynomial_Array<T>::operator()(T x)
{
    T res = this->factorList->get(this->_n - 1);
    for (int i = this->_n - 2; i >= 0; i--)
    {
        res *= x;
        res += this->factorList->get(i);
    }
    return res;
}
template <class T>
polynomial_Array<T> &polynomial_Array<T>::operator=(const polynomial_Array<T> &p)
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
    }
    this->factorList = new arrayList<T>(*p.factorList);
    this->_n = p._n;
    return *this;
}
template <class T>
class Type
{
public:
    int _exp;
    T _ceof;
    void set(int exp, T ceof)
    {
        this->_exp = exp;
        this->_ceof = ceof;
    }
    Type &operator=(const Type<T> &Element)
    {
        this->_ceof = Element._ceof;
        this->_exp = Element._exp;
        return *this;
    }
    Type operator+(const Type<T> &Element)
    {
        Type<T> addResult;
        if (this->_exp != Element._exp)
        {
            ostringstream tip;
            tip << "Exponent of first number is " << this->_exp << " ,but the second is " << Element._exp;
            addResult.set(0, 0);
            throw illegalInputData(tip.str());
        }
        else
        {
            addResult.set(this->_exp, this->_ceof + Element._ceof);
        }
        return addResult;
    }
    Type operator-(const Type<T> &Element)
    {
        Type<T> minusResult;
        if (this->_exp != Element._exp)
        {
            ostringstream tip;
            tip << "Exponent of first number is " << this->_exp << " ,but the second is " << Element._exp;
            minusResult.set(0, 0);
            throw illegalInputData(tip.str());
        }
        else
        {
            minusResult.set(this->_exp, this->_ceof - Element._ceof);
        }
        return minusResult;
    }
};
template <class T>
ostream &operator<<(ostream &cout, const Type<T> &element)
{
    cout << "ceof:" << element._ceof << " Exp:" << element._exp<<" ";
    return cout;
}
template <class T>
class polynomial_Chain
{
public:
    polynomial_Chain();
    polynomial_Chain(const polynomial_Chain<T> &p);
    polynomial_Chain(const chainList<Type<T>> &list);
    ~polynomial_Chain();
    int degree()
    {
        return this->_n;
    }
    polynomial_Chain<T> add(const polynomial_Chain<T> &p);
    polynomial_Chain<T> operator+(const polynomial_Chain<T> &p)
    {
        return this->add(p);
    }
    void input(const chainList<Type<T>> &list);
    chainList<Type<T>> output();
    polynomial_Chain<T> subtract(const polynomial_Chain<T> &p);
    polynomial_Chain<T> operator-(const polynomial_Chain<T> &p)
    {
        return this->subtract(p);
    }
    polynomial_Chain<T> multiply(const polynomial_Chain<T> &p);
    polynomial_Chain<T> divide(const polynomial_Chain<T> &p);
    T valueOf(T x);
    T operator()(T x);
    polynomial_Chain<T> &operator=(const polynomial_Chain<T> &p);

private:
    int _n;
    chainList<Type<T>> *factorList;
};
template <class T>
polynomial_Chain<T>::polynomial_Chain()
{
    this->_n = 0;
    this->factorList = nullptr;
}
template <class T>
polynomial_Chain<T>::polynomial_Chain(const polynomial_Chain<T> &p)
{
    this->_n = p._n;
    if (p.factorList == nullptr)
    {
        this->factorList = nullptr;
        return;
    }
    this->factorList = new chainList<Type<T>>(*p.factorList);
}
template <class T>
polynomial_Chain<T> &polynomial_Chain<T>::operator=(const polynomial_Chain<T> &RightElement)
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
    }
    this->_n = RightElement._n;
    if (RightElement.factorList != nullptr)
    {
        this->factorList = new chainList<Type<T>>(*RightElement.factorList);
    }
    return *this;
}
template <class T>
polynomial_Chain<T>::polynomial_Chain(const chainList<Type<T>> &list)
{

    if (list.size() == 0)
    {
        this->_n = 0;
        this->factorList = nullptr;
        return;
    }
    class chainList<Type<T>>::iterator it = list.begin();
    this->factorList = new chainList<Type<T>>;
    for (int i = 0; i < list.size(); i++, it++)
    {
        if ((*it)._ceof != 0)
        {
            this->factorList->push_back(*it);
        }
    }
    this->_n = (*this->factorList->begin())._exp + 1;
}
template <class T>
polynomial_Chain<T>::~polynomial_Chain()
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
    }
}
template <class T>
void polynomial_Chain<T>::input(const chainList<Type<T>> &list)
{
    if (this->factorList != nullptr)
    {
        delete this->factorList;
        this->factorList = nullptr;
        this->_n = 0;
    }
    if (list.size() == 0)
        return;
    this->factorList = new chainList<Type<T>>;
    class chainList<Type<T>>::iterator it = list.begin();
    this->factorList = new chainList<Type<T>>;
    for (int i = 0; i < list.size(); i++, it++)
    {
        if ((*it)._ceof != 0)
        {
            this->factorList->push_back(*it);
        }
    }
    this->_n = (*this->factorList->begin())._exp + 1;
}
template <class T>
chainList<Type<T>> polynomial_Chain<T>::output()
{
    return chainList<Type<T>>(*this->factorList);
}
template <class T>
polynomial_Chain<T> polynomial_Chain<T>::add(const polynomial_Chain<T> &p)
{
    chainList<Type<T>> reschain;
    class chainList<Type<T>>::iterator it1 = this->factorList->begin();
    class chainList<Type<T>>::iterator it2 = p.factorList->begin();
    int size1 = this->factorList->size();
    int size2 = p.factorList->size();
    while (size1 != 0 && size2 != 0)
    {
        if ((*it1)._exp > (*it2)._exp)
        {
            reschain.push_back(*it1);
            size1--;
            it1++;
        }
        else if ((*it1)._exp < (*it2)._exp)
        {
            reschain.push_back(*it2);
            size2--;
            it2++;
        }
        else
        {
            reschain.push_back(*it1 + *it2);
            size1--;
            it1++;
            size2--;
            it2++;
        }
    }
    while (size1 > 0)
    {
        reschain.push_back(*it1);
        size1--;
        it1++;
    }
    while (size2 > 0)
    {
        reschain.push_back(*it2);
        size2--;
        it2++;
    }
    return polynomial_Chain<T>(reschain);
}
template <class T>
polynomial_Chain<T> polynomial_Chain<T>::subtract(const polynomial_Chain<T> &p)
{
    chainList<Type<T>> reschain;
    class chainList<Type<T>>::iterator it1 = this->factorList->begin();
    class chainList<Type<T>>::iterator it2 = p.factorList->begin();
    int size1 = this->factorList->size();
    int size2 = p.factorList->size();
    while (size1 != 0 && size2 != 0)
    {
        if ((*it1)._exp > (*it2)._exp)
        {
            Type<T> element;
            element.set((*it1)._exp, -(*it1)._ceof);
            reschain.push_back(element);
            size1--;
            it1++;
        }
        else if ((*it1)._exp < (*it2)._exp)
        {
            Type<T> element;
            element.set((*it2)._exp, -(*it2)._ceof);
            reschain.push_back(element);
            size2--;
            it2++;
        }
        else
        {
            reschain.push_back(*it1 - *it2);
            size1--;
            it1++;
            size2--;
            it2++;
        }
    }
    while (size1 > 0)
    {
        reschain.push_back(*it1);
        size1--;
        it1++;
    }
    while (size2 > 0)
    {
        reschain.push_back(*it2);
        size2--;
        it2++;
    }
    return polynomial_Chain<T>(reschain);
}
template <class T>
polynomial_Chain<T> polynomial_Chain<T>::multiply(const polynomial_Chain<T> &p)
{
}
template <class T>
polynomial_Chain<T> polynomial_Chain<T>::divide(const polynomial_Chain<T> &p)
{
}
template <class T>
T polynomial_Chain<T>::valueOf(T x)
{
    class ::chainList<Type<T>>::itreator it = this->factorList->begin();
    T res = 0;
    for (int i = 0; i < this->factorList->size(); i++, it++)
    {
        int exp = (*it)._exp;
        T ceof = (*it)._ceof;
        res += ceof * pow(x, exp);
    }
    return res;
}
template <class T>
T polynomial_Chain<T>::operator()(T x)
{
    class ::chainList<Type<T>>::iterator it = this->factorList->begin();
    T res = 0;
    for (int i = 0; i < this->factorList->size(); i++, it++)
    {
        int exp = (*it)._exp;
        T ceof = (*it)._ceof;
        res += ceof * pow(x, exp);
    }
    return res;
}