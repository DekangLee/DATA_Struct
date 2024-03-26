/*
 * @Author: dekangLee dakang579@gmail.com
 * @Date: 2024-01-25 19:59:16
 * @LastEditors: dekangLee dakang579@gmail.com
 * @LastEditTime: 2024-03-14 11:00:20
 * @FilePath: \DATA_Struct\TreeStructure\main4.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include "RBTree.hpp"
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
template <class K, class E>
void _printf(RBTreeNode<K, E> *node)
{
    cout << "key: " << node->key << "  color: " << node->color << endl;
    cout << "parent: " << node->parent->key << "  left: " << node->leftChild->key << "  right: " << node->rightChild->key << endl;
}
void test01()
{
    RBTree<int, int> tree1;
    srand(time(0));
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        int num = rand() % 10000000;
        // cout << "number = " << num << endl;
        auto flag = tree1.insert(num, 1);
        if (!flag)
        // cout << "插入成功！-----" << endl;
        {
            count++;
            // cout << "插入失败！-----" << endl;
        }
    }
    cout << "count = " << count << endl;
    // tree1.preOrder(_printf);
}
void test02()
{
    RBTree<int, int> tree1;
    tree1.insert(14, -1);
    tree1.insert(60, 0);
    tree1.insert(88, 0);
    tree1.insert(75, 0);
    tree1.insert(36, 0);
    tree1.insert(43, 0);
    tree1.insert(47, 0);
    tree1.insert(82, 0);
    tree1.insert(73, 0);
    tree1.insert(66, 0);
    tree1.insert(10, -1);
    tree1.preOrder(_printf);
    // if (tree1.find(10) != nullptr)
    // {
    //     cout << "查找成功！" << endl;
    //     cout << tree1.find(10)->value << endl;
    // }
    // else
    //     cout << "查找失败！" << endl;
}
void test03()
{
    RBTree<int, int> tree1;
    tree1.insert(14, -1);
    tree1.insert(60, 0);
    tree1.insert(88, 0);
    tree1.insert(75, 0);
    tree1.insert(36, 0);
    tree1.insert(43, 0);
    tree1.insert(47, 0);
    tree1.insert(2, 0);
    tree1.insert(73, 0);
    tree1.insert(66, 0);
    tree1.insert(10, -1);

    tree1.erase(88);
    tree1.erase(75);
    // tree1.erase(73);

    tree1.erase(60);
    tree1.erase(73);
    // tree1.erase(2);
    // tree1.erase(14);
    // tree1.erase(10);
    // tree1.erase(43);
    // tree1.erase(36);
    // tree1.erase(47);
    // tree1.insert(74, -1);
    tree1.preOrder(_printf);
    // tree1.postOrder(_printf);
}
void test04()
{
    vector<int> v1;
    RBTree<int, int> tree1;
    srand(time(0));
    for (int i = 0; i < 10000000; ++i)
    {
        int num = rand() % 1000000 + 1;
        // cout << "num = " << num << endl;
        v1.push_back(num);
        tree1.insert(num, -1);
    }
    // tree1.preOrder(_printf);
    random_shuffle(v1.begin(), v1.end());

    for (int i = 0; i < 99999; i++)
    {
        // cout << "v[1] = " << v1[i] << endl;
        tree1.erase(v1[i]);
    }
    tree1.output();
}
void test05()
{
    RBTree<int, int> tree1;
    tree1.insert(94, -1);
    tree1.insert(42, 0);
    tree1.insert(81, 0);
    tree1.insert(97, 0);
    tree1.insert(80, 0);
    tree1.insert(29, 0);
    tree1.insert(99, 0);
    tree1.insert(59, 0);
    tree1.insert(40, -1);
    tree1.insert(78, 0);
    tree1.insert(84, 0);
    tree1.insert(18, -1);
    tree1.insert(64, -1);
    tree1.insert(24, -1);
    tree1.insert(5, -1);

    // tree1.erase(88);
    // tree1.erase(75);
    // tree1.erase(73);
    // tree1.erase(66);
    // tree1.erase(60);

    // tree1.postOrder(_printf);
    tree1.erase(94);
    tree1.erase(42);
    tree1.erase(81);
    tree1.erase(97);
    tree1.erase(80);
    tree1.erase(29);
    tree1.erase(99);
    tree1.erase(59);
    tree1.erase(40);
    tree1.erase(78);
    tree1.preOrder(_printf);
}
void test06()
{
    RBTree<int, int> tree1;
    tree1.insert(22, -1);
    tree1.insert(72, 0);
    tree1.insert(26, 0);
    tree1.insert(81, 0);
    tree1.insert(22, 0);
    tree1.insert(31, 0);
    tree1.insert(86, 0);
    tree1.insert(23, 0);
    tree1.insert(67, -1);
    tree1.insert(60, 0);

    tree1.erase(22);
    // tree1.erase(72);
    // tree1.erase(26);
    // tree1.erase(81);
    // tree1.erase(81);
    tree1.erase(22);
    // tree1.erase(31);
    // tree1.preOrder(_printf);
    tree1.output();
}
void test07()
{
    RBTree<int, int> tree1;
    tree1.insert(33, -1);
    tree1.insert(1, 0);
    tree1.insert(31, 0);
    tree1.insert(85, 0);
    tree1.insert(47, 0);
    tree1.insert(93, 0);
    tree1.insert(56, 0);
    tree1.insert(43, 0);
    tree1.insert(52, -1);
    tree1.insert(39, 0);
    tree1.insert(8, -1);
    tree1.insert(57, 0);
    tree1.insert(29, 0);
    tree1.insert(97, 0);
    tree1.insert(84, 0);

    tree1.erase(33);
    tree1.erase(1);
    tree1.erase(31);
    tree1.erase(85);
    tree1.erase(47);
    tree1.erase(93);
    tree1.erase(56);
    tree1.erase(43);
    tree1.erase(52);
    tree1.preOrder(_printf);
}
void test08()
{
    RBTree<int, int> tree1;
    tree1.insert(25, -1);
    tree1.insert(50, 0);
    tree1.insert(57, 0);
    tree1.insert(34, 0);
    tree1.insert(68, 0);

    tree1.erase(50);
    tree1.erase(57);
    tree1.erase(34);
    tree1.erase(68);
    tree1.erase(25);
    tree1.preOrder(_printf);
}
void test09()
{
    RBTree<int, int> tree1;
    tree1.insert(78, 1);
    tree1.insert(55, 2);
    tree1.insert(89, 3);
    tree1.insert(64, 4);
    tree1.insert(80, 5);
    tree1.insert(58, 6);
    tree1.insert(1, 7);
    tree1.insert(20, 8);
    tree1.insert(50, 9);
    tree1.insert(4, 10);
    tree1.insert(71, 11);
    tree1.insert(17, 12);
    tree1.insert(84, 13);
    tree1.insert(42, 14);
    tree1.insert(10, 15);
    tree1.insert(23, 16);
    tree1.insert(36, 17);
    tree1.insert(45, 18);
    tree1.insert(6, 19);
    tree1.insert(16, 20);
    tree1.insert(47, 21);
    tree1.insert(95, 22);
    tree1.insert(70, 23);
    tree1.insert(25, 24);
    tree1.insert(56, 25);
    tree1.insert(58, 26);
    tree1.insert(40, 27);
    tree1.insert(41, 28);
    tree1.insert(6, 29);
    tree1.insert(57, 30);

    tree1.erase(89);
    tree1.erase(78);
    tree1.erase(6);
    tree1.erase(16);
    tree1.erase(70);
    tree1.erase(23);
    tree1.erase(56);
    tree1.erase(64);
    tree1.erase(1);
    tree1.erase(20);
    tree1.erase(42);
    tree1.erase(80);
    tree1.erase(4);
    tree1.erase(55);
    tree1.erase(57);
    tree1.erase(6);
    tree1.erase(84);
    tree1.erase(95);
    tree1.erase(71);
    tree1.erase(58);
    tree1.erase(36);
    tree1.erase(10);
    tree1.erase(17);
    tree1.erase(45);
    tree1.erase(41);
    tree1.erase(47);
    tree1.erase(40);
    tree1.erase(25);
    tree1.preOrder(_printf);
}
int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    // test06();
    // test05();
    // test07();
    // test08();
    // test09();
    return 0;
}