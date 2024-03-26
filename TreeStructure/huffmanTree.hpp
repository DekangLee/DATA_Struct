/*
 * @Author: dekangLee dakang579@gmail.com
 * @Date: 2024-01-13 19:37:39
 * @LastEditors: dekangLee dakang579@gmail.com
 * @LastEditTime: 2024-01-18 10:10:55
 * @FilePath: \DATA_Struct\TreeStructure\huffmanTree.hpp
 * @Description:
 *
 * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
 */
#ifndef _HUFFMANTREEH_
#define _HUFFMANTREEH_
#include "minHeap.hpp"
#include "linkedBinaryTree.hpp"
template <class T>
struct huffmanNode
{
    T weight;
    linkedBinaryTree<int> *tree;
    huffmanNode()
    {
        this->tree = nullptr;
    }
    huffmanNode(const huffmanNode<T> &theNode)
    {
        this->weight = theNode.weight;
        if (theNode.tree != nullptr)
            this->tree = new linkedBinaryTree<int>(*theNode.tree);
        else
            this->tree = nullptr;
    }
    ~huffmanNode()
    {
        // cout<<"huffmanNode析构函数"<<endl;
        if (this->tree != nullptr)
            delete this->tree;
        this->tree = nullptr;
    }
    bool operator>(const huffmanNode<T> theNode)
    {
        return this->weight > theNode.weight;
    }
    bool operator>=(const huffmanNode<T> theNode)
    {
        return this->weight >= theNode.weight;
    }
    bool operator<(const huffmanNode<T> theNode)
    {
        return this->weight < theNode.weight;
    }
    bool operator<=(const huffmanNode<T> theNode)
    {
        return this->weight <= theNode.weight;
    }
    huffmanNode<T> &operator=(const huffmanNode<T> &theNode)
    {
        if (this->tree != nullptr)
            delete this->tree;
        this->weight = theNode.weight;
        if (theNode.tree == nullptr)
            this->tree = nullptr;
        else
            this->tree = new linkedBinaryTree<int>(*theNode.tree);
        return *this;
    }
};
template <class E>
void _print(binaryTreeNode<E> *t)
{
    cout << t->element << endl;
}
template <class T>
linkedBinaryTree<int> *huffmanTree(T weight[], int n)
{
    // 用权值weight生成huffmanTree，n>1；
    huffmanNode<T> *hNode = new huffmanNode<T>[n];
    linkedBinaryTree<int> emptyTree;
    for (int i = 0; i < n; i++)
    {
        hNode[i].weight = weight[i];
        hNode[i].tree = new linkedBinaryTree<int>;
        hNode[i].tree->makeTree(0, emptyTree, emptyTree);
        // cout<<"tree size = "<<hNode[i].tree->size()<<endl;
    }
    // hNode->tree->levelOrder(_print);
    cout << "---------------" << endl;
    // 使一组节点树构成小根堆
    minHeap<huffmanNode<T>> heap;
    for (int i = 0; i < n; i++)
    {
        heap.push(hNode[i]);
    }
    cout << "-------heap szie = " << heap.size() << endl;
    // 不断从小根堆中提取两个树合并，直到剩下一棵树
    huffmanNode<T> w, x, y;
    linkedBinaryTree<int> *z;
    for (int i = 0; i < n; ++i)
    {
        // 从小根堆中提取两颗树最轻的树
        cout << "i = " << i << "---------" << endl;
        cout << "heap size = " << heap.size() << endl;
        x = heap.top();
        cout << "x tree size = " << x.tree->size() << endl;
        cout << "x.weight = " << x.weight << endl;
        heap.pop();
        cout << heap.top().weight << endl;
        cout << heap.top().tree->size() << endl;
        y = heap.top();
        heap.pop();
        cout << "y tree size = " << y.tree->size() << endl;
        cout << "y.weight = " << y.weight << endl;
        // 合并成一棵树
        z = new linkedBinaryTree<int>;
        w.weight = x.weight + y.weight;
        z->makeTree(w.weight, *x.tree, *y.tree);
        w.tree = z;
        heap.push(w);
        delete x.tree;
        delete y.tree;
    }
    return heap.top().tree;
}
#endif