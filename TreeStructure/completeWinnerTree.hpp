#ifndef _COMPLETEWINNERTREEH_
#define _COMPLETEWINNERTREEH_
#include "winnerTree.hpp"
#include "myExpectation.h"
#include <exception>
#include <iostream>
#include <cmath>
using namespace std;
template <class T>
class completeWinnerTree : public winnerTree<T>
{
public:
    completeWinnerTree(T *thePlayer, int theNumberOfPlayers)
    {
        this->tree = nullptr;
        this->player = nullptr;
        this->numberPlayer = 0;
        this->initialize(thePlayer, theNumberOfPlayers);
    };
    ~completeWinnerTree();
    void initialize(T *thePlayer, int theNumberOfPlayers);
    // 返回赢者树的索引
    int winner() const;
    // 在参赛者thePlayer的分数变化后重赛
    void rePlayer(int thePlayer);
    // 根据叶子结点的索引player[i]计算父节点tree[i]的索引
    int index(int childIndex)
    {
        // cout << "LowExt = " << this->lowExt << endl;
        // cout << "offset = " << this->offset << endl;
        if (childIndex <= this->lowExt)
            return (childIndex + this->offset) / 2;
        else
            return (childIndex - this->lowExt + this->numberPlayer - 1) / 2;
    }
    // 根据父节点tree[i]的索引计算右叶子节点player[i]的索引
    int rIndex(int parentIndex)
    {
        if (2 * parentIndex + 1 <= this->numberPlayer - 1)
            return 2 * parentIndex + 1;
        int n = floor(log2(this->numberPlayer)) + 1;
        int dis = pow(2, n) - 1;
        if (n - 1 == floor(log2(parentIndex)))
            return 2 * parentIndex + 1 - dis;
        else
            return 2 * parentIndex + 1 - dis + this->numberPlayer;
    }
    int lIndex(int parentIndex)
    {
        if (2 * parentIndex <= this->numberPlayer - 1)
            return 2 * parentIndex;
        int n = floor(log2(this->numberPlayer)) + 1;
        int dis = pow(2, n) - 1;
        if (n - 1 == floor(log2(parentIndex)))
            return 2 * parentIndex - dis;
        else
            return 2 * parentIndex - dis + this->numberPlayer;
    }
    void output() const;
    T &winnerElem() const
    {
        return this->tree[1];
    }
    void rePlayer(int thePlayer, const T &newScore);

private:
    T *tree;
    T *player;
    int numberPlayer;
    int lowExt;
    int offset;
};
template <class T>
void completeWinnerTree<T>::initialize(T *thePlayer, int theNumberOfPlayers)
{
    if (theNumberOfPlayers <= 1)
        throw illegalParameterValue("thePlayer must be >= 2");
    this->numberPlayer = theNumberOfPlayers;
    int num = floor(log2(this->numberPlayer - 1));
    // cout << "num = " << num << endl;
    int s = pow(2, num);
    // cout << "s = " << s << endl;
    this->lowExt = 2 * (this->numberPlayer - s);
    this->offset = 2 * s - 1;
    this->player = new T[theNumberOfPlayers + 1];
    this->tree = new T[theNumberOfPlayers];

    for (int i = 1; i <= theNumberOfPlayers; ++i)
    {
        this->player[i] = thePlayer[i];
    }
    int parent = this->numberPlayer - 1; // 竞赛的位置
    int l = 0;
    int r = 0;
    while (parent >= 1)
    {
        l = this->lIndex(parent);
        r = this->rIndex(parent);
        // cout << "l = " << l << "  "
            //  << "r = " << r << endl;
        if (2 * parent + 1 <= this->numberPlayer - 1)
            this->tree[parent] = (this->tree[l] > this->tree[r] ? this->tree[l] : this->tree[r]);
        if (2 * parent + 1 > this->numberPlayer - 1 && 2 * parent <= this->numberPlayer - 1)
            this->tree[parent] = (this->tree[l] > this->player[r] ? this->tree[l] : this->player[r]);
        if (2 * parent > this->numberPlayer - 1)
            this->tree[parent] = (this->player[l] > this->player[r] ? this->player[l] : this->player[r]);
        parent--;
    }
}
template <class T>
completeWinnerTree<T>::~completeWinnerTree()
{
    if (this->tree != nullptr)
    {
        delete[] this->tree;
        this->tree = nullptr;
    }
    if (this->player != nullptr)
    {
        delete[] this->player;
        this->player = nullptr;
    }
}
template <class T>
int completeWinnerTree<T>::winner() const
{
    for (int i = 1; i <= this->numberPlayer; ++i)
    {
        if (this->tree[1] == this->player[i])
            return i;
    }
    return -1;
}
template <class T>
void completeWinnerTree<T>::rePlayer(int thePlayer)
{
    this->rePlayer(thePlayer,INT_MIN);
}
template <class T>
void completeWinnerTree<T>::rePlayer(int thePlayer, const T &newScore)
{
    this->player[thePlayer] = newScore;
    int parent = this->index(thePlayer);
    int r = 0;
    int l = 0;
    while (parent >= 1)
    {
        // cout << "parent = " << parent << endl;
        l = this->lIndex(parent);
        r = this->rIndex(parent);
        if (2 * parent <= this->numberPlayer - 2)
            this->tree[parent] = (this->tree[l] > this->tree[r] ? this->tree[l] : this->tree[r]);
        if (2 * parent > this->numberPlayer - 2 && 2 * parent <= this->numberPlayer - 1)
            this->tree[parent] = (this->tree[l] > this->player[r] ? this->tree[l] : this->player[r]);
        if (2 * parent > this->numberPlayer - 1)
            this->tree[parent] = (this->player[l] > this->player[r] ? this->player[l] : this->player[r]);
        parent = parent / 2;
    }
}
template <class T>
void completeWinnerTree<T>::output() const
{
    cout << "the information of the tree:" << endl;
    for (int i = 1; i <= this->numberPlayer - 1; ++i)
    {
        cout << "tree[" << i << "] = " << tree[i] << " " << endl;
    }
}
#endif