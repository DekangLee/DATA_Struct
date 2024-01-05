/*
 * @Author: dekangLee dakang579@gmail.com
 * @Date: 2024-01-05 16:05:46
 * @LastEditors: dekangLee dakang579@gmail.com
 * @LastEditTime: 2024-01-05 16:20:39
 * @FilePath: \DATA_Struct\TreeStructure\main2.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include "maxHblt.hpp"
using namespace std;
template <class T>
void _printf(binaryTreeNode<T> *theNode)
{
    cout << "s:" << theNode->element.first << " value = " << theNode->element.second <<endl;;
}
void test01()
{
    maxHblt<int> hblt1;
    hblt1.push(1);
    hblt1.push(2);
    hblt1.preOrder(_printf);
}
int main()
{
    test01();
    return 0;
}