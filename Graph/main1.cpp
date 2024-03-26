/*
 * @Author: dekangLee dakang579@gmail.com
 * @Date: 2024-02-26 21:20:29
 * @LastEditors: dekangLee dakang579@gmail.com
 * @LastEditTime: 2024-03-14 11:05:17
 * @FilePath: \DATA_Struct\Graph\main1.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include "graph.hpp"
#include "linkedDigraph.hpp"
#include "adjacencyWDigraph.hpp"
using namespace std;
typedef adjacencyWDigraph<int> Graph;
typedef linkedDigraph<int> lGraph;
typedef edge<int> E;
void test01()
{
    Graph G1(5, -1);
    E edge12(1, 2, 1);
    E edge23(2, 3, 1);
    E edge14(1, 4, 1);
    E edge1(1, 2, 1);
    G1.insertEdge(E(1, 2, 1));
    G1.insertEdge(E(1, 4, 1));
    G1.insertEdge(E(2, 5, 1));
    G1.insertEdge(E(2, 3, 1));
    G1.insertEdge(E(3, 4, 1));
    G1.insertEdge(E(5, 1, 1));
    G1.insertEdge(E(5, 4, 1));
    // G1.eraseEdge(1,2);
    cout << "vertex = " << G1.numberOfVertices() << endl;
    cout << "Edge = " << G1.numberOfEdges() << endl;
    // cout << G1.outDegree(1) << endl;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= 5; i++)
    {
        sum1 += G1.outDegree(i);
        sum2 += G1.inDegree(i);
    }
    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
}
void test02()
{
    Graph G1(5);
    G1.insertEdge(E(1, 2, 1));
    G1.insertEdge(E(1, 4, 1));
    G1.insertEdge(E(2, 5, 1));
    G1.insertEdge(E(2, 3, 1));
    G1.insertEdge(E(3, 4, 1));
    G1.insertEdge(E(5, 1, 1));
    G1.insertEdge(E(5, 4, 1));
    // Graph::myIterator *it = G1.iterator(1);
    // G1.BFS(1, -1);
    G1.DFS(1, -1);
    cout << "-------------" << endl;
    G1.DFS(1);
}
void test03()
{
    lGraph G1(10);
    G1.insertEdge(E(1, 2, 1));
    G1.insertEdge(E(1, 4, 1));
    G1.insertEdge(E(2, 5, 1));
    G1.insertEdge(E(2, 3, 1));
    G1.insertEdge(E(3, 4, 1));
    G1.insertEdge(E(5, 1, 1));
    G1.insertEdge(E(5, 4, 1));
    cout << "number of edges = " << G1.numberOfEdges() << endl;
    // G1.eraseEdge(1, 2);
    // cout << "number of edges = " << G1.numberOfEdges() << endl;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= 5; i++)
    {
        sum1 += G1.outDegree(i);
        sum2 += G1.inDegree(i);
    }
    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
}
void test04()
{
    lGraph G1(5);
    G1.insertEdge(E(1, 2, 1));
    G1.insertEdge(E(1, 4, 1));
    G1.insertEdge(E(2, 5, 1));
    G1.insertEdge(E(2, 3, 1));
    G1.insertEdge(E(3, 4, 1));
    G1.insertEdge(E(5, 1, 1));
    G1.insertEdge(E(5, 4, 1));
    // Graph::myIterator *it = G1.iterator(1);
    // G1.BFS(1);
    // G1.DFS(1);
    G1.reDFS(1);
}
void test05()
{
    Graph G1(10);
    G1.insertEdge(E(1, 2, 1));
    G1.insertEdge(E(1, 3, 1));
    G1.insertEdge(E(1, 4, 1));
    G1.insertEdge(E(1, 10, 1));
    G1.insertEdge(E(2, 5, 1));
    G1.insertEdge(E(3, 5, 1));
    G1.insertEdge(E(4, 3, 1));
    G1.insertEdge(E(4, 6, 1));
    G1.insertEdge(E(4, 7, 1));
    G1.insertEdge(E(5, 8, 1));
    G1.insertEdge(E(5, 10, 1));
    G1.insertEdge(E(6, 3, 1));
    G1.insertEdge(E(6, 7, 1));
    G1.insertEdge(E(6, 8, 1));
    G1.insertEdge(E(7, 8, 1));
    G1.insertEdge(E(7, 9, 1));
    G1.insertEdge(E(9, 6, 1));
    G1.insertEdge(E(10, 8, 1));
    G1.insertEdge(E(10, 9, 1));
    // cout << G1.outDegree(1) << endl;
    // cout << G1.inDegree(1) << endl;
    // int sum1 = 0;
    // int sum2 = 0;
    // for (int i = 1; i <= G1.numberOfVertices(); i++)
    // {
    //     sum1 += G1.outDegree(i);
    //     sum2 += G1.inDegree(i);
    // }
    // cout << "sum1 = " << sum1 << endl;
    // cout << "sum2 = " << sum2 << endl;
    // cout << "number of edge = " << G1.numberOfEdges() << endl;
    // G1.DFS(1,-1);
    G1.findPath(1, 10);
}
int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    // cout << asc << endl;
    return 0;
}