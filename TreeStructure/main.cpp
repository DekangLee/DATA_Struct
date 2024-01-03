// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-02 16:45:46
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-03 08:21:18
//  * @FilePath: \DATA_Struct\TreeStructure\main.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include "linkedBinaryTree.hpp"
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
// int main()
// {
//     // test01();
//     test02();
//     system("pause");
//     return 0;
// }