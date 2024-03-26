// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-02 16:45:46
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-18 11:10:00
//  * @FilePath: \DATA_Struct\TreeStructure\main1.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include "linkedBinaryTree.hpp"
// #include "linkedPriorityQueue.hpp"
// #include "maxHeap.hpp"
// #include "minHeap.hpp"
// #include "huffmanTree.hpp"
// #include <ctime>
// using namespace std;
// template <class E>
// void print(binaryTreeNode<E> *t)
// {
//     cout << t->element << endl;
// }
// void test01()
// {
//     srand(time(0));
//     linkedBinaryTree<int> tree1;
//     for (int i = 1; i <= 10; ++i)
//     {
//         // cout << "i = " << i << endl;
//         int num = rand() % 10;
//         tree1.insert(num, i);
//     }
//     cout << "szie of tree : " << tree1.size() << endl;
//     // tree1.preOrder(print);
//     // tree1.postOrder(print);
//     // tree1.inOrder(print);
//     // tree1.levelOrder(print);
//     tree1.insert(-1, 11);
//     linkedBinaryTree<int> tree2 = tree1;
//     tree1 = tree2;
//     tree1.levelOrder(print);
//     cout << "--------------" << endl;
//     tree2.levelOrder(print);
//     cout << "the tree height : " << tree1.height() << endl;
//     cout << tree1.compare(tree2) << endl;
// }
// void test02()
// {
//     linkedBinaryTree<int> tree1;
//     for (int i = 1; i <= 10; ++i)
//     {
//         // cout << "i = " << i << endl;
//         // int num = rand()%10;
//         int num = i;
//         tree1.insert(num, i);
//     }
//     linkedBinaryTree<int>::preIterator it = tree1.begin();
//     while (!it.isEnd())
//     {
//         cout << *it << endl;
//         ++it;
//     }
// }
// void test03()
// {
//     linkedPriorityQueue<int, int> q1;
//     sortedChain<int, int> chain1;
//     // chain1.insert(_Pair<int,int>(1,3));
//     // chain1.insert(_Pair<int,int>(3,2));
//     // chain1.insert(_Pair<int,int>(2,4));
//     // chain1.insert(_Pair<int,int>(5,3));
//     // chain1.insert(_Pair<int,int>(0,-1));
//     // chain1.output();
//     chain1.rOutput();
//     q1.push(1, 3);
//     q1.push(2, 4);
//     q1.push(-1, 5);
//     q1.push(3, 10);
//     q1.push(10, 10);
//     while (!q1.empty())
//     {
//         cout << q1.top() << endl;
//         q1.pop();
//     }
// }
// void test04()
// {
//     maxHeap<int> heap1;
//     srand(time(0));
//     for (int i = 0; i < 10; ++i)
//     {
//         int num = rand() % 100;
//         heap1.push(num);
//     }
//     maxHeap<int> heap2 = heap1;
//     for (int i = 0; i < 10; ++i)
//     {
//         cout << heap2.top() << endl;
//         heap2.pop();
//     }
//     cout << "heap1 size = " << heap1.size() << endl;
//     cout << "heap2 size = " << heap2.size() << endl;
// }
// void test05()
// {
//     minHeap<int> heap1;
//     srand(time(0));
//     for (int i = 0; i < 10; ++i)
//     {
//         int num = rand() % 100;
//         heap1.push(num);
//     }
//     for (int i = 0; i < 10; ++i)
//     {
//         cout << heap1.top() << endl;
//         heap1.pop();
//     }
// }
// void test06()
// {
//     minHeap<linkedBinaryTree<int>> heap1;
//     linkedBinaryTree<int> emptyTree;
//     linkedBinaryTree<int> *tree1 = new linkedBinaryTree<int>;
//     linkedBinaryTree<int> *tree2 = new linkedBinaryTree<int>;
//     for (int i = 1; i < 10; i++)
//     {
//         // cout << i << endl;
//         tree1->insert(i, i);
//         tree2->insert(i, i);
//         // heap1.push(*tree1);
//     }
//     cout << "tree size = " << tree1->size() << endl;
//     // tree1.levelOrder(print);
//     // cout << "-------------" << endl;
//     // tree2.levelOrder(print);
//     emptyTree.makeTree(-1, *tree1, *tree1);
//     delete tree1;
//     delete tree2;
//     cout << "---------" << endl;
//     emptyTree.levelOrder(print);
// }
// void test07()
// {
//     linkedBinaryTree<int> *huffmanTree1;
//     int weight[] = {10, 20, 3, 13, 5};
//     // minHeap<huffmanNode<int>> heap1;
//     // huffmanNode<int> *hNode = new huffmanNode<int>[5];
//     // linkedBinaryTree<int> emptyTree;
//     // for (int i = 0; i < 5; i++)
//     // {
//     //     hNode[i].weight = weight[i];
//     //     hNode[i].tree = new linkedBinaryTree<int>;
//     //     hNode[i].tree->makeTree(0, emptyTree, emptyTree);
//     //     // cout<<"tree size = "<<hNode[i].tree->size()<<endl;
//     // }
//     // hNode->tree->height();
//     // for (int i = 0; i < 5; ++i)
//     // {
//     //     heap1.push(hNode[i]);
//     // }
//     // for (int i = 0; i < 5; ++i)
//     // {
//     //     cout << "size = " << heap1.top().tree->size() << endl;
//     //     heap1.pop();
//     // }
//     huffmanTree1 = huffmanTree(weight, 5);
//     huffmanTree1->levelOrder(print);
// }
// void test08()
// {
//     minHeap<int> heap1;
//     for (int i = 0; i < 10; i++)
//     {
//         heap1.push(rand() % 20);
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         cout << heap1.top() << endl;
//         heap1.pop();
//     }
// }
// int main()
// {
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     test07();
//     // test08();
//     return 0;
// }