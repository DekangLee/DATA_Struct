#ifndef _MAXPRIORITYQUEUEH_
#define _MAXPRIORITYQUEUEH_
template <class K, class E>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue(){};
    virtual bool empty() const = 0;                             // 队列是否为空
    virtual int size() const = 0;                               // 返回队列的元素个数
    virtual const E &top() = 0;                                 // 返回优先级最大的元素的引用
    virtual void pop() = 0;                                     // 删除队首元素
    virtual void push(const K &prior, const E &theElement) = 0; // 插入元素
};
#endif