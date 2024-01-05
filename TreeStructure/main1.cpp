// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-02 16:45:46
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-05 16:04:39
//  * @FilePath: \DATA_Struct\TreeStructure\main.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include "linkedBinaryTree.hpp"
// #include "linkedPriorityQueue.hpp"
// #include "maxHeap.hpp"
// #include "minHeap.hpp"
// #include <ctime>
// using namespace std;
// template <class E>
// void print(binaryTreeNode<E> *t)
// {
//     cout << t->element << endl;
// }
// void test01()
// {
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
//     cout<<"heap1 size = "<<heap1.size()<<endl;
//     cout<<"heap2 size = "<<heap2.size()<<endl;
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

// int main()
// {
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // system("pause");
//     return 0;
// }