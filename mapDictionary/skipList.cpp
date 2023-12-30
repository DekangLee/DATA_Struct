#ifndef _SKIPLISTH_
#define _SKIPLISTH_
#include <iostream>
#include <cmath>
#include <exception>
#include <sstream>
using namespace std;
template <class key, class value>
struct skipNode
{
    skipNode(const pair<key, value> &thePair, int size)
    {
        this->element.first = thePair.first;
        this->element.second = thePair.second;
        this->next = new skipNode<key, value> *[size];
        this->previous = new skipNode<key, value> *[size];
    }
    pair<key, value> element;
    skipNode<key, value> **next;
    skipNode<key, value> **previous;
};
template <class key, class value>
class skipList
{
public:
    skipList(key largeKey, int maxPairs, float prob);
    int level() const
    {
        int lev = 0;
        while (rand() <= this->cutoff)
            lev++;
        return (lev <= this->maxLevel) ? lev : maxLevel;
    }
    skipNode<key, value> *search(const key &theKey) const;
    void insert(const pair<key, value> &thePair);

private:
    float cutoff;                     // 用来确定层数
    int levels;                       // 当前最大的非空链表
    int dSzie;                        // 字典的数对个数
int maxLevel;                     // 允许的最大链表层数
    key tailkey;                      // 最大关键字
    skipNode<key, value> *headerNode; // 跳表头结点
    skipNode<key, value> *tailNode;   // 跳表尾节点
    skipNode<key, value> **last;      // last[i] 表示i层的最后节点
};
template <class key, class value>
skipList<key, value>::skipList(key largeKey, int maxPairs, float prob)
{
    this->cutoff = prob * RAND_MAX;
    this->maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
    this->levels = 0;
    this->dSzie = 0;
    this->tailkey = largeKey;
    // 生成头结点、尾节点和数组last；
    pair<key, value> tailPair;
    tailPair.first = tailkey;
    this->headerNode = new skipNode<key, value>(tailPair, maxLevel + 1);
    this->tailNode = new skipNode<key, value>(tailPair, 0);
    this->last = new skipNode<key, value> *[maxLevel + 1];
    for (int i = 0; i <= maxLevel; i++)
    {
        this->headerNode->next[i] = this->tailNode;
        this->tailNode->previous = this->headerNode->next[i];
    }
}
template <class key, class value>
skipNode<key, value> *skipList<key, value>::search(const key &theKey) const
{
    // 搜索关键字theKey,把每一级链表中要查看的最后一个节点存储早输注last中
    // 返回包含关键字theKey的节点
    // 位置beforeNode 是关键字为theKey的节点之前最右边的位置
    skipNode<key, value> *beforeNdoe = this->headerNode;
    for (int i = this->levels; i >= 0; i--)
    {
        while (beforeNdoe->next[i]->element.first < theKey)
        {
            beforeNdoe = beforeNdoe->next[i];
        }
        this->last[i] = beforeNdoe;
    }
    return beforeNdoe->next[0];
}
template <class key, class value>
void skipList<key, value>::insert(const pair<key, value> &thePair)
{
    // 把数对thePair插入字典，覆盖其关键字相同的已经存在的数对
    if (thePair.first >= this->tailkey) // 关键字太大
    {
        ostringstream tip;
        tip << "Key = " << thePair.first << " must be < " << this->tailkey;
        throw invalid_argument(tip.str());
    }
    // 查看关键字为tehKey的数对是否已经存在
    skipNode<key, value> *theNode = this->search(thePair.first);
    if (theNode->element.first == thePair.first)
    {
        // 如果存在，则更新该数对的value
        theNode->element.second = thePair.second;
        return;
    }
    int theLevel = this->level(); // 新节点的级
    // 使级theLevel <= this->levels +1;
    if (theLevel > this->levels)
    {
        theLevel = ++this->levels;
        this->last[theLevel] = this->headerNode;
    }
    // 在节点theNode 之后插入新节点
    skipNode<key, value> *newNode = new skipNode<key, value>(thePair, theLevel + 1);
    for (int i = 0; i <= theLevel; i++)
    {
        newNode->next[i] = last[i]->next[i];
    }
    this->dSzie++;
    return;
}

#endif