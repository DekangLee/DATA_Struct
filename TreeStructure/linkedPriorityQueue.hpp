#ifndef _LINKEDPRIORITYQUEUEH_
#define _LINKEDPRIORITYQUEUEH_
#include "maxPriorityQueue.hpp"
#include "sortedChain.hpp"
template <class K, class E>
class linkedPriorityQueue : maxPriorityQueue<K,E>
{
public:
    linkedPriorityQueue()
    {
        this->queueSize = 0;
        this->pQueue = new sortedChain<K, E>;
    }
    ~linkedPriorityQueue()
    {
        if (this->pQueue != nullptr)
        {
            delete this->pQueue;
            this->pQueue = nullptr;
        }
    }
    bool empty() const // 队列是否为空
    {
        return this->queueSize == 0;
    }
    int size() const // 返回队列的元素个数
    {
        return this->queueSize;
    }
    const E &top();                                 // 返回优先级最大的元素的引用
    void pop();                                     // 删除队首元素
    void push(const K &prior, const E &theElement); // 插入元素
private:
    int queueSize;
    sortedChain<K, E> *pQueue;
};
template <class K, class E>
const E &linkedPriorityQueue<K, E>::top()
{
    return this->pQueue->front();
}
template <class K, class E>
void linkedPriorityQueue<K, E>::pop()
{
    this->pQueue->pop();
    this->queueSize--;
}
template <class K, class E>
void linkedPriorityQueue<K, E>::push(const K &prior, const E &theElement)
{
    this->pQueue->insert(_Pair<K,E>(prior,theElement));
    this->queueSize++;
}
#endif