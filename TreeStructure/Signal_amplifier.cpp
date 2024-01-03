// /*
//  * @Author: dekangLee dakang579@gmail.com
//  * @Date: 2024-01-03 09:42:00
//  * @LastEditors: dekangLee dakang579@gmail.com
//  * @LastEditTime: 2024-01-03 10:27:49
//  * @FilePath: \DATA_Struct\TreeStructure\Signal_amplifier.cpp
//  * @Description: 
//  * 
//  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved. 
//  */
// #include <iostream>
// #include "linkedBinaryTree.hpp"
// using namespace std;
// const int tolerance = 3;
// template <class E>
// void print(binaryTreeNode<E> *t)
// {
//     cout << t->element << endl;
// }
// struct booster
// {
//     int degradeToleaf,     // 到达叶子时的衰减量
//         degradeFromParent; // 从父节点出发时的衰减量
//     bool boosterHere;      // 当且仅当放置了放大器时，值为真
//     booster(int theDegradeFromParent = 0, int theDegradeToleaf = 0, bool theBoosterHere = false)
//     {
//         this->degradeFromParent = theDegradeFromParent;
//         this->degradeToleaf = theDegradeToleaf;
//         this->boosterHere = theBoosterHere;
//     }
// };
// ostream &operator<<(ostream &cout, const booster &x)
// {
//     cout << x.boosterHere << " " << x.degradeToleaf << " " << x.degradeFromParent << " ";
//     return cout;
// }
// void caculate(binaryTreeNode<booster> *x)
// {
//     int leftNum = 0;
//     int rightNum = 0;
//     if(x->leftChild != nullptr)
//         leftNum = x->leftChild->element.degradeToleaf +  x->leftChild->element.degradeFromParent;
//     if(x->rightChild != nullptr)
//         rightNum = x->rightChild->element.degradeToleaf + x->rightChild->element.degradeFromParent;
//     x->element.degradeToleaf = max(leftNum,rightNum);
// }
// void placeBoosters(binaryTreeNode<booster> *x)
// {
//     // 计算*x的衰减量，若小于容忍值，则在x的子节点放置一个放大器
//     x->element.degradeToleaf = 0; // 初始化x处的衰减值
//     // 计算x的左子树的衰减量。若大于容忍值，则在x的左孩子处放置一个放大器
//     binaryTreeNode<booster> *y = x->leftChild;
//     if (y != nullptr)
//     {
//         // x有一颗左子非空树
//         int degradation = y->element.degradeToleaf + y->element.degradeFromParent;
//         if (degradation > tolerance)
//         {
//             // 在y处放置一个放大器
//             y->element.boosterHere = true;
//             x->element.degradeToleaf = y->element.degradeFromParent;
//         }
//         else
//         {
//             // 不需要在y处放置放大器
//             x->element.degradeToleaf = degradation;
//         }
//     }
//     // 计算x的右子树的衰减量，若大于容忍值，则在x孩子出放置一个放大器
//     y = x->leftChild;
//     if (y != nullptr)
//     {
//         // x 有一颗非空右子树
//         int degradation = y->element.degradeToleaf + y->element.degradeFromParent;
//         if (degradation > tolerance)
//         {
//             // 在y处放置一个放大器
//             y->element.boosterHere = true;
//             degradation = y->element.degradeFromParent;
//             x->element.degradeToleaf = degradation;
//         }
//     }
// }
// void test01()
// {
//     linkedBinaryTree<booster> tree;
//     tree.insert(booster(),1);
//     tree.insert(booster(1),2);
//     tree.insert(booster(3),3);
//     tree.insert(booster(2),4);
//     tree.insert(booster(2),5);
//     tree.insert(booster(1),6);
//     tree.insert(booster(2),7);
//     tree.insert(booster(3),8);
//     tree.insert(booster(1),9);
//     tree.insert(booster(2),13);
//     tree.insert(booster(2),15);
//     // tree.postOrder(caculate);
//     tree.postOrder(placeBoosters);

//     tree.preOrder(print);
// }
// int main()
// {
//     test01();
//     return 0;
// }