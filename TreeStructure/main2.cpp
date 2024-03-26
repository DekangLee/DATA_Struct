// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-05 16:05:46
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-06 19:56:36
//  * @FilePath: \DATA_Struct\TreeStructure\main2.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include "maxHblt.hpp"
// #include "maxHeap.hpp"
// #include "linkedBinaryTree.hpp"
// #include <ctime>
// #include <random>
// using namespace std;
// template <class T>
// void _printf(binaryTreeNode<T> *theNode)
// {
//     cout << "s:" << theNode->element.first << " value = " << theNode->element.second << endl;
// }
// void test01()
// {
//     maxHblt<int> hblt1;
//     srand(time(0));
//     for (int i = 0; i < 10; ++i)
//     {
//         int num = rand() % 100;
//         hblt1.push(num);
//     }
//     hblt1.preOrder(_printf);
//     // while(!hblt1.empty())
//     // {
//     //     cout<<hblt1.top()<<endl;
//     //     hblt1.pop();
//     // }
// }
// template <class T>
// void geneArr(T *arr, int n, int l, int r)
// {
//     srand(time(0));
//     random_device rd;
//     for (int i = 0; i < n; ++i)
//     {
//         T num = rand() % (r - l + 1) + l;
//         arr[i] = num;
//     }
// }
// template <class T>
// void _printf(T *arr, int n)
// {
//     for (int i = 0; i < n; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// void test02()
// {
//     int a[10];
//     geneArr(a, 10, 1, 20);
//     _printf(a,10);
//     heapSort(a,10);
//     _printf(a,10);
// }

// int main()
// {
//     // test01();
//     // test02();
//     // cout<<min(1,2)<<endl;
//     cout<<5+11+7+16+27<<endl;
//     cout<<6*2+6+9+9+12+18<<endl;
//     return 0;
// }