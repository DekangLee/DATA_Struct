// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-19 14:52:03
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-26 16:32:39
//  * @FilePath: \DATA_Struct\TreeStructure\main3.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include "completeWinnerTree.hpp"
// #include "binarySearchTree.hpp"
// #include "AVLTree.hpp"
// #include <ctime>
// #include <vector>
// #include <algorithm>
// typedef pair<const int, int> Pair;
// const int N = 10;
// using namespace std;
// template <class T>
// void _print(T *arr, int n)
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// template <class K, class E>
// void _print(AVLTreeNode<K, E> *t)
// {
//     cout << "key = " << t->key << "  height = " << t->height << endl;
//     if (t->leftChild != nullptr)
//         cout << "leftChild = " << t->leftChild->key;
//     else
//         cout << "leftChild == null";
//     if (t->rightChild != nullptr)
//         cout << "  rightChild = " << t->rightChild->key << endl;
//     else
//         cout << "  rightChild == null" << endl;
// }
// void test01()
// {
//     int arr[N];
//     srand(time(0));
//     for (int i = 1; i <= N - 1; ++i)
//     {
//         arr[i] = rand() % 100;
//     }
//     _print(arr, N - 1);
//     completeWinnerTree<int> tree(arr, N - 1);
//     tree.output();
//     tree.rePlayer(3, 100);
//     tree.output();
// }
// // 利用竞赛树排序，与堆排序相似
// void test02()
// {
//     int arr[N];
//     srand(time(0));
//     for (int i = 1; i <= N - 1; ++i)
//     {
//         arr[i] = rand() % 100;
//     }
//     _print(arr, N - 1);
//     completeWinnerTree<int> tree(arr, N - 1);
//     for (int i = 1; i <= N - 1; ++i)
//     {
//         arr[i] = tree.winnerElem();
//         int index = tree.winner();
//         tree.rePlayer(index);
//     }
//     _print(arr, N - 1);
// }
// void test03()
// {
//     Pair p1(1, 2);
//     // p1.first = 1;
//     cout << p1.first << endl;
//     p1.second = 2;
// }
// template <class K, class E>
// void _print(binaryTreeNode<pair<K, E>> *t)
// {
//     cout << t->element.first << endl;
// }
// void test04()
// {
//     binarySearchTree<int, int> tree1;
//     tree1.insert(make_pair(4, 0));
//     tree1.insert(make_pair(12, 0));
//     tree1.insert(make_pair(8, 0));
//     tree1.insert(make_pair(16, 0));
//     tree1.insert(make_pair(6, 0));
//     tree1.insert(make_pair(18, 0));
//     tree1.insert(make_pair(24, 0));
//     tree1.insert(make_pair(2, 0));
//     tree1.insert(make_pair(14, 0));
//     tree1.insert(make_pair(3, 0));
//     cout << "tree size = " << tree1.size() << endl;
//     // tree1.erase(8);
//     tree1.erase(3);
//     tree1.preOrder(_print);
//     cout << "tree size = " << tree1.size() << endl;
//     cout << "tree hight = " << tree1.height() << endl;
// }
// void test05()
// {
//     // 引用可以引用指针变量 T * &p，合法
//     // 但是指针不可以指向引用 例如 int & *p，非法
//     int a = 10;
//     int *p = &a;
//     int *&rp = p;
//     int b = 20;
//     rp = &b;
//     cout << *p << endl;
//     cout << *rp << endl;
// }
// void test06()
// {
//     int r = 0;
//     int l = 1;
//     // int res = r > l ? (++r) : (++l);
//     int res = r > l ? r++ : l++;
//     cout << "r = " << r << endl;
//     cout << "l = " << l << endl;
//     cout << "res = " << res << endl;
// }
// void test07()
// {
//     AVLTree<int, int> tree1;
//     tree1.insert(make_pair(4, 3));
//     tree1.insert(make_pair(3, -3));
//     tree1.insert(make_pair(6, 2));
//     tree1.insert(make_pair(9, 7));
//     tree1.insert(make_pair(1, 0));
//     tree1.insert(make_pair(10, 0));
//     tree1.insert(make_pair(5, 0));
//     tree1.insert(make_pair(7, 0));
//     tree1.erase(1);
//     // tree1.erase(10);
//     // tree1.erase(1);
//     // tree1.erase(3);
//     cout << "tree size = " << tree1.size() << endl;
//     // tree1.postOrder(_print);
//     // cout << "pre order : " << endl;
//     // tree1.preOrder(_print);
//     cout << "level order : " << endl;
//     tree1.levelOrder(_print);
//     AVLTreeNode<int, int> *node = tree1.find(3);
//     cout << "key : " << node->key << " value : " << node->element << endl;
// }
// void test08()
// {
//     AVLTree<int, int> tree1;
//     vector<int> numV;
//     int count = 0;
//     srand(time(0));
//     for (int i = 0; i < 100000; i++)
//     {
//         int num = rand() % 10000000;
//         numV.push_back(num);
//         auto flag = tree1.insert(make_pair(num, 1));
//         // if (!flag)
//         //     count++;
//     }
//     // cout << count << endl;
//     random_shuffle(numV.begin(),numV.end());
//     for(int i = 0;i<1000;i++)
//     {
//         tree1.erase(numV[i]);
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
//     // test07();
//     test08();
//     return 0;
// }