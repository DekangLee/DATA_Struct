#ifndef _HASHTABLEH_
#define _HASHTABLEH_
#include <iostream>
#include "dictionary.hpp"
#include <exception>
using namespace std;
template <class K, class E>
class hashTable : public dictionary<K, E>
{
public:
    hashTable(int theDivisor);
    ~hashTable()
    {
        for (int i = 0; i < this->divisor; i++)
        {
            if (this->table[i] != nullptr)
            {
                delete this->table[i];
                this->table[i] = nullptr;
            }
        }
        if (this->table != nullptr)
        {
            delete[] this->table;
            this->table = nullptr;
        }
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
    E &operator[](const K &theKey)
    {
        pair<K, E> *result = this->find(theKey);
        if(result == nullptr)
        {
            this->insert(make_pair(theKey,E()));
        }
        return this->find(theKey)->second;
    }
private:
    pair<K, E> **table; // 散列表
    hash<K> hash;       // 把类型K映射到一个非负整数
    int dSize;          // 字典中的数对个数
    int divisor;        // 散列函数除数
};
template <class K, class E>
hashTable<K, E>::hashTable(int theDivisor)
{
    this->divisor = theDivisor;
    this->dSize = 0;
    // 分配和初始化散列表数组
    this->table = new pair<K, E> *[divisor];
    for (int i = 0; i < this->divisor; i++)
    {
        table[i] = nullptr;
    }
}
template <class K, class E>
int hashTable<K, E>::search(const K &theKey) const
{
    // cout << "thekey = " << theKey << endl;

    // cout << this->hash(theKey) << endl;
    // cout << (unsigned long long)this->hash(theKey) << endl;
    int i = (unsigned long long)this->hash(theKey) % this->divisor; // 这是theKey的起始桶
    // cout << i << endl;
    int j = i;
    do
    {
        if (table[j] == nullptr || table[j]->first == theKey)
            return j;
        j = (j + 1) % this->divisor; // 循环查找，一直到起始桶
    } while (j != i);
    return j;
}
template <class K, class E>
pair<K, E> *hashTable<K, E>::find(const K &theKey) const
{
    // 返回匹配的数对的指针
    // 如果数对不存在，则返回NULL
    // 搜索散列表
    int b = this->search(theKey);
    // 判断table[b] 是否为要找的数对
    if (table[b] == nullptr || table[b]->first != theKey)
        return nullptr;
    return table[b];
}
template <class K, class E>
void hashTable<K, E>::insert(const pair<K, E> &thePair)
{
    // 把数对thePair插入字典，若存在相同的数对，则覆盖
    //  若表满，则抛出异常
    //  搜索散列表，查找匹配的数对
    int b = this->search(thePair.first);
    if (table[b] == nullptr)
    {
        // 没有匹配的数对，而且表不满
        this->table[b] = new pair<K, E>(thePair);
        dSize++;
    }
    else
    {
        if (this->table[b]->first == thePair.first)
            this->table[b]->first = thePair.first;
        else
            throw invalid_argument("Error table is full!");
    }
}
template <class K, class E>
void hashTable<K, E>::erase(const K &theKey)
{
    int b = this->search(theKey);
    if (this->table[b] != nullptr)
    {
        delete this->table[b];
        this->table[b] = nullptr;
        this->dSize--;
    }
}
template <class K, class E>
void hashTable<K, E>::output() const
{
    for (int i = 0; i < this->divisor; i++)
    {
        if (this->table[i] != nullptr)
        {
            cout << *this->table[i] << endl;
        }
        else
        {
            cout << "nullptr" << endl;
        }
    }
}
template <class K, class E>
ostream &operator<<(ostream &cout, const pair<K, E> &pair)
{
    cout << "(" << pair.first << "," << pair.second << ")";
    return cout;
}
#endif