#ifndef __GRAPHH__
#define __GRAPHH__
#include <ostream>
using namespace std;
template <class T>
class edge
{
public:
    int vertex1() const { return v1; }
    int vertex2() const { return v2; }
    T weight() const { return mweight; }
    edge() {}
    edge(int theV1, int theV2, const T &theWeight) : v1(theV1), v2(theV2), mweight(theWeight) {}
    edge(const edge<T>& theEdge)
    {
        this->v1 = theEdge.v1;
        this->v2 = theEdge.v2;
        this->mweight = theEdge.mweight;
    }

private:
    int v1; // 第一个顶点
    int v2; // 第二个顶点
    T mweight;
};
template <class T>
class graph
{
public:
    virtual ~graph() {}
    // ADT方法
    virtual int numberOfVertices() const = 0;
    virtual int numberOfEdges() const = 0;
    virtual bool exsitEdge(int, int) const = 0;
    virtual void insertEdge(const edge<T>&) = 0;
    virtual void eraseEdge(int, int) = 0;
    virtual int inDegree(int) const = 0;
    virtual int outDegree(int) const = 0;
    // 其他方法
    virtual bool directed() const = 0; // 当且仅当是有向图是，返回值是true
    virtual bool weighted() const = 0; // 当且仅当是加权图时，返回值的true
    // virtual vertexIterator<T> *iterator(int) = 0; // 访问指定顶点的相邻顶点
};
#endif