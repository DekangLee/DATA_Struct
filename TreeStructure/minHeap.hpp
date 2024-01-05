#ifndef _MINHEAPH_
#define _MINHEAPH_
template <class T>
class minHeap
{
public:
    minHeap(int capacity = 100)
    {
        this->arrLength = capacity + 1;
        this->heap = new T[capacity + 1];
        this->heapSize = 0;
    }
    ~minHeap()
    {
        if(this->heap != nullptr)
        {
            delete[] this->heap;
            this->heap = nullptr;
        }
    }
    T top() const
    {
        return this->heap[1];
    }
    void push(const T &theElement);
    void pop();
    int size() const
    {
        return this->heapSize;
    }

private:
    T *heap;
    int arrLength;
    int heapSize;
};
// 向堆中插入元素
template <class T>
void minHeap<T>::push(const T &theElement)
{
    // 必要时增加数组长度
    if (this->heapSize == this->arrLength - 1)
    {
        // 数组长度加倍
        T *newArray = new T[this->arrLength * 2];
        for (int i = 1; i <= this->heapSize; i++)
        {
            newArray[i] = this->heap[i];
        }
        delete[] this->heap;
        this->heap = newArray;
        this->arrLength *= 2;
    }
    // 为元素寻找插入位置
    int currentNode = ++heapSize;
    while (currentNode != 1 && this->heap[currentNode / 2] > theElement)
    {
        this->heap[currentNode] = this->heap[currentNode / 2];
        currentNode /= 2;
    }
    this->heap[currentNode] = theElement;
}
// 删除小根堆的根节点
template <class T>
void minHeap<T>::pop()
{
    this->heap[1].~T();
    // 删除最后一个元素然后重新建堆
    T lastElement = heap[this->heapSize--];
    // 从根开始，为最后一个元素寻找位置
    int currentNode = 1;
    int child = 2;
    while (child <= this->heapSize)
    {
        // heap[child] 应该是currentNode 的更大的孩子
        if (child < this->heapSize && this->heap[child] > this->heap[child + 1])
            child++;
        if (lastElement <= this->heap[child])
            break;
        this->heap[currentNode] = this->heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastElement;
}
#endif