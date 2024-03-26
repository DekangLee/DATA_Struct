#ifndef __ADJACENCYWDIGRAPHH__
#define __ADJACENCYWDIGRAPHH__
#include <iostream>
#include <sstream>
#include "graph.hpp"
#include "arrayQueue.hpp"
#include "E:\project-C++\DATA_Struct\LinearDataStructure\arrayStack.hpp"
#include "myExpectation.h"
using namespace std;

template <class T>
class adjacencyWDigraph : public graph<T>
{
protected:
    int n;    // 顶点个数
    int e;    // 边的个数
    T **a;    // 邻接矩阵
    T noEdge; // 表示不存在的边
public:
    adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0)
    {
        // 构造函数
        // 确认顶点的合法性
        this->n = numberOfVertices;
        this->e = 0;
        this->noEdge = theNoEdge;
        this->a = new T *[this->n + 1];
        for (int i = 1; i <= n; i++)
        {
            // 初始化邻接矩阵
            this->a[i] = new T[n + 1];
            for (int j = 1; j <= n; j++)
                this->a[i][j] = noEdge;
        }
    }
    ~adjacencyWDigraph()
    {
        for (int i = 1; i < n; i++)
            delete[] this->a[i];
        delete[] a;
    }
    int numberOfVertices() const { return n; }
    int numberOfEdges() const { return e; }
    bool directed() const { return true; }
    bool weighted() const { return true; }
    int degree(int) { return 0; }
    bool exsitEdge(int i, int j) const
    {
        // 返回值是真，当且仅当(i,j)是图的一条边
        if (i < 1 || j < 1 || i > n || j > n || a[i][j] == noEdge)
            return false;
        else
            return true;
    }
    void insertEdge(const edge<T> &theEdge)
    {
        // 插入边；如果该边已存在，则用theEdge->weight()修改边的权值
        int v1 = theEdge.vertex1();
        // cout << "v1 = " << v1 << endl;
        int v2 = theEdge.vertex2();
        // cout << "v2 = " << v2 << endl;
        if (this->a[v1][v2] == noEdge) // 新的边
            this->e++;
        this->a[v1][v2] = theEdge.weight();
    }
    void eraseEdge(int i, int j)
    {
        // 删除边
        if (i >= 1 && j >= 1 && i <= n && j <= n && a[i][j] != noEdge)
        {
            this->a[i][j] = noEdge;
            this->e--;
        }
    }
    void checkVertex(int theVertex) const
    {
        // 确认是有效顶点
        if (theVertex < 1 || theVertex > n)
        {
            throw illegalParameterValue("no vertex");
        }
    }
    // 返回顶点的出度
    int outDegree(int theVertex) const
    {
        checkVertex(theVertex);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (this->a[theVertex][i] != noEdge)
                sum++;
        }
        return sum;
    }
    int inDegree(int theVertex) const
    {
        checkVertex(theVertex);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (this->a[i][theVertex] != noEdge)
                sum++;
        }
        return sum;
    }
    class myIterator
    {
    private:
        T *row;   // 邻接矩阵的行
        T noEdge; // theRow[i]==noEdge, 当且仅当没有关联于顶点i的边
        int n;    // 顶点数
        int currentVertex;

    public:
        myIterator(T *theRow, T theNoEdge, int numberOfVertices)
        {
            this->row = theRow;
            this->noEdge = theNoEdge;
            this->n = numberOfVertices;
            this->currentVertex = 1;
        }
        ~myIterator(){};
        int next(T &theWeight)
        {
            // 返回下一个顶点。若不存在，则返回0
            // 赋权值theWeight = 边的权值
            // 寻找下一个邻接的顶点
            for (int j = this->currentVertex; j < n; j++)
            {
                if (this->row[j] != noEdge)
                {
                    this->currentVertex = j + 1;
                    theWeight = this->row[j];
                    return j;
                }
            }
            // 不存在下一个邻接的节点
            this->currentVertex = this->n + 1;
            return 0;
        }
    };
    myIterator *iterator(int theVertex)
    {
        // 返回顶点的迭代器
        checkVertex(theVertex);
        return new myIterator(this->a[theVertex], noEdge, n);
    }
    void BFS(int v, int label)
    {
        // 广度优先搜索,reach[]用来标记从顶点v可到达的所有顶点
        arrayQueue<pair<int, int>> q(10);
        int *reach = new int[n + 1];
        for (int i = 1; i <= this->n; i++)
            reach[i] = 0;
        reach[v] = label;
        q.push(make_pair(v, v));
        int currentVertex = v;
        while (!q.empty())
        {
            // 从队列中删去一个标记过的顶点
            currentVertex = q.front().first;
            if (q.front().second != q.front().first)
                cout << q.front().second << "->" << q.front().first << endl;
            q.pop();
            // 标记所有没有到达的邻接于顶点w的顶点
            for (int i = 1; i <= this->n; i++)
            {
                // cout << "reach = " << reach[i] << endl;
                if (reach[i] == 0 && this->a[currentVertex][i] != noEdge)
                {
                    // cout << "vertex = " << i << endl;
                    q.push(make_pair(i, currentVertex));
                    reach[i] = label; // 对顶点做已经遍历过的标记
                }
            }
        }
        delete reach;
    }
    void DFS(int v, int label)
    {
        arrayStack<int> _stack;
        int *reach = new int[n + 1];
        for (int i = 1; i <= this->n; i++)
            reach[i] = 0;
        _stack.push(v);
        reach[v] = label;
        int theVertex = v;
        while (!_stack.empty())
        {
            theVertex = _stack.top();
            cout << theVertex << endl;
            _stack.pop();
            for (int i = 1; i <= n; i++)
            {
                if (reach[i] == 0 && this->a[theVertex][i] != noEdge)
                {
                    // cout << theVertex << "->" << i << endl;
                    _stack.push(i);
                    reach[i] = label;
                }
            }
        }
        delete reach;
    }
    void DFS(int v)
    {
        bool *reach = new bool[n + 1];
        for (int i = 1; i <= n; ++i)
            reach[i] = false;
        // reach[v] = true;
        _dfs(v, reach);
    }
    void _dfs(int v, bool *reach)
    {
        if (reach[v])
            return;
        reach[v] = true;
        cout << "v = " << v << endl;
        for (int i = 1; i <= n; ++i)
        {
            if (a[v][i] != noEdge && (!reach[i]))
                _dfs(i, reach);
        }
    }
    void findPath(int theSource, int theDestination)
    {
        // 寻找一条顶点theSource到顶点theDestination的路径
        // 如果路径不存在返回nullptr
        int *path = new int[n + 1]; // 这里的path相当于栈的使用，用来回溯
        bool **reach = new bool *[n + 1];
        for (int i = 1; i <= n; i++)
        {
            path[i] = 0;
            reach[i] = new bool[n + 1];
        }
        resetReach(reach);
        path[1] = theSource; // 将第一个点放入path中
        // 根据DFS获得路径
        int count = 1;            // 回溯计数
        int currentV = theSource; // 标记当前顶点
        while (count != 0)
        {
            currentV = path[count];
            // cout << "currentV = " << currentV << endl;
            bool flag = true;
            for (int i = 1; i <= n; i++)
            {
                if (a[currentV][i] != noEdge && !reach[currentV][i])
                {
                    resetReach(reach,i,path,count);
                    reach[currentV][i] = true;
                    path[++count] = i;
                    flag = false;
                    if (i == theDestination) // 已经到达destination
                    {
                        // cout << "count = " << count << endl;
                        utilitFunc(path, count);
                        flag = true;
                    }
                    break;
                }
            }
            if (flag)
            {
                int cpoint = path[count]; // 将path中的第一个顶点的reach记录重置
                resetReach(reach[cpoint]);
                path[count--] = 0;
                // cout << "cpoint = " << cpoint << endl;
                // cout << "count = " << count << endl;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            delete[] reach[i];
        }
        delete[] reach;
        delete[] path;
    }

private:
    void resetReach(bool *reach)
    {
        for (int i = 1; i <= n; ++i)
            reach[i] = false;
    }
    void resetReach(bool **reach)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                reach[i][j] = false;
    }
    void resetReach(bool **reach, int currentV, int *path, int count)
    {
        for (int i = 1; i <= count; i++)
        {
            int pPoint = path[i];
            reach[currentV][pPoint] = true;
        }
    }
    void utilitFunc(int *path, int count)
    {
        for (int i = 1; i <= count; ++i)
            cout << path[i] << " ";
        cout << endl;
    }
};
#endif