#include <iostream>
using namespace std;
int *parent;
// 初始化numberOfElement 颗树，每棵树一个元素
void initialize(int numberOfElements)
{
    parent = new int[numberOfElements + 1];
    for (int e = 1; e <= numberOfElements; ++e)
    {
        parent[e] = 0;
    }
}
// 返回元素的root
int find(int theElement)
{
    while (parent[theElement] != 0)
    {
        theElement = parent[theElement];
    }
    return theElement;
}
// 合并两颗其根节点不同的树
void unite(int rootA, int rootB)
{
    parent[rootB] = rootA;
}
int main()
{
    return 0;
}