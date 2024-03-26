#ifndef __LINKEDDIGRAPHH__
#define __LINKEDDIGRAPHH__
#include <iostream>
#include <sstream>
#include "graph.hpp"
#include "arrayQueue.hpp"
#include "E:\project-C++\DATA_Struct\LinearDataStructure\arrayStack.hpp"
#include "myExpectation.h"
using namespace std;
using namespace std;
template <class T>
struct vertex
{
    int n;    // 顶点编号
    T weight; // 权值
    vertex<T> *next;
    vertex() { next = nullptr; }
    vertex(int theVertex, const T &theWeight) : n(theVertex), weight(theWeight) { next = nullptr; }
};
template <class T>
class linkedDigraph
{
private:
    int n; // 顶点数
    int e; // 边数
    vertex<T> **aList;

public:
    linkedDigraph(int numberOfVertices = 0) // 构造函数
    {
        this->aList = new vertex<T> *[numberOfVertices + 1];
        this->n = numberOfVertices;
        this->e = 0;
        for (int i = 1; i <= n; i++)
        {
            this->aList[i] = nullptr;
        }
    }
    ~linkedDigraph(); // 析构函数
    bool exsitEdge(int i, int j) const
    {
        vertex<T> *node = this->aList[i];
        while (node != nullptr)
        {
            if (node->n == j)
                return true;
            node = node->next;
        }
        return false;
    }
    void insertEdge(const edge<T> theEdge)
    {
        int v1 = theEdge.vertex1();
        int v2 = theEdge.vertex2();
        vertex<T> *node = this->aList[v1];
        vertex<T> *pNode = node;
        while (true)
        {
            if (node == nullptr) // 原图中没有这条边,需要新增边
            {
                vertex<T> *newNode = new vertex<T>(v2, theEdge.weight());
                if (pNode == node)
                    this->aList[v1] = newNode;
                else
                    pNode->next = newNode;
                this->e++;
                return;
            }
            if (node->n == v2) // 原图中存在这条边
            {
                node->weight = theEdge.weight();
                return;
            }
            pNode = node;
            node = node->next;
        }
    }
    void checkVertex(int i, int j) const
    {
        if (i < 1 || i > n || j < 1 || j > n)
        {
            ostringstream tip;
            tip << "invalid vertex parameter";
            throw illegalParameterValue(tip.str());
        }
    }
    int numberOfVertices() const { return n; }
    int numberOfEdges() const { return e; }
    bool directed() const { return true; }
    bool weighted() const { return true; }
    int degree(int) { return 0; }
    void eraseEdge(int i, int j)
    {
        checkVertex(i, j);
        if (!exsitEdge(i, j))
        {
            ostringstream tip;
            tip << "this edge is not exsited";
            throw illegalParameterValue(tip.str());
        }
        vertex<T> *node = aList[i];
        vertex<T> *pNode = nullptr;
        while (node != nullptr)
        {
            if (node->n == j)
                break;
            pNode = node;
            node = node->next;
        }
        if (pNode == nullptr)
            this->aList[i] = node->next;
        else
            pNode->next = node->next;
        delete node;
        this->e--;
    }
    int outDegree(int theVertex) const;
    int inDegree(int theVertex) const;
    void BFS(int v);
    void DFS(int v);
    void reDFS(int v)
    {
        bool *reach = new bool[this->n + 1];
        for (int i = 1; i <= n; ++i)
            reach[i] = false;
        reach[v] = true;
        _dfs(aList[v], reach);
        for (int i = 1; i <= n; i++)
            if (reach[i])
                cout << i << endl;
        delete[] reach;
    }
    void _dfs(vertex<T> *node, bool *reach)
    {
        if (node == nullptr)
            return;
        vertex<T> *nextNode = nullptr; //  nextNode为需要DFS的新节点
        while (node != nullptr)        // 寻找候选节点nextNode
        {
            if (reach[node->n])
            {
                node = node->next;
                continue;
            }
            cout << "node = " << node->n << endl;
            nextNode = aList[node->n];
            _dfs(nextNode, reach);
            reach[node->n] = true;
            node = node->next;
        }
    }
};
template <class T>
linkedDigraph<T>::~linkedDigraph()
{
    for (int i = 1; i <= this->n; ++i)
    {
        vertex<T> *node = this->aList[i];
        while (node != nullptr)
        {
            vertex<T> *nextNode = node->next;
            delete node;
            node = nextNode;
        }
    }
    delete[] aList;
}
template <class T>
int linkedDigraph<T>::outDegree(int theVertex) const
{
    checkVertex(theVertex, 1);
    int sum = 0;
    vertex<T> *node = aList[theVertex];
    while (node != nullptr)
    {
        sum++;
        node = node->next;
    }
    return sum;
}
template <class T>
int linkedDigraph<T>::inDegree(int theVertex) const
{
    checkVertex(theVertex, 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == theVertex)
            continue;
        vertex<T> *node = aList[i];
        while (node != nullptr)
        {
            if (node->n == theVertex)
                sum++;
            node = node->next;
        }
    }
    return sum;
}
template <class T>
void linkedDigraph<T>::BFS(int v)
{
    arrayQueue<int> q;
    bool *reach = new bool[n + 1];
    for (int i = 1; i <= n; ++i)
        reach[i] = false;
    q.push(v);
    reach[v] = true;
    while (!q.empty())
    {
        int currentV = q.front();
        cout << "currentV = " << currentV << endl;
        q.pop();
        vertex<T> *node = aList[currentV];
        while (node != nullptr && (!reach[node->n]))
        {
            q.push(node->n);
            reach[node->n] = true;
            node = node->next;
        }
    }
    delete[] reach;
}
template <class T>
void linkedDigraph<T>::DFS(int v)
{
    arrayStack<int> _stack;
    bool *reach = new bool[n + 1];
    for (int i = 1; i <= n; ++i)
        reach[i] = false;
    _stack.push(v);
    reach[v] = true;
    while (!_stack.empty())
    {
        int currentV = _stack.top();
        cout << "currentV = " << currentV << endl;
        _stack.pop();
        vertex<T> *node = aList[currentV];
        while (node != nullptr)
        {
            if (!reach[node->n])
            {
                cout << "v = " << node->n << endl;
                _stack.push(node->n);
                reach[node->n] = true;
            }
            node = node->next;
        }
    }
    delete[] reach;
}
#endif