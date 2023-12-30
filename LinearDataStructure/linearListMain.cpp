// #include <iostream>
// #include "chainList.hpp"
// #include "arrayList.hpp"
// #include "linearList.hpp"
// #include "circularList.hpp"
// #include "doubleLinkList.hpp"
// #include <algorithm>
// #include "polynomial.hpp"
// #include <ctime>
// using namespace std;
// const int N = 5;
// void test01()
// {
//     srand(time(0));
//     arrayList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = (rand() % 30) + 20;
//         cout << "num = " << num << endl;
//         L1.push_back(num);
//     }
//     cout << "Size of L1 :" << L1.size() << endl;
//     cout << "ArrayList : " << L1 << endl;
//     try
//     {
//         L1[20] = 10;
//         cout << "L1[0] = " << L1[0] << endl;
//     }
//     catch (illegalIndex &e)
//     {
//         e.outputMessage();
//     }
// }
// void test02()
// {
//     srand(time(0));
//     arrayList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = (rand() % 30) + 20;
//         // cout << "num = " << num << endl;
//         L1.push_back(num);
//     }
//     // auto _fprint = [](int num)
//     // {
//     //     cout<<num <<" ";
//     // };
//     // for_each(L1.begin(),L1.end(),_fprint);
//     // for(auto elem : L1)
//     // {
//     //     cout<<elem <<" ";
//     // }
//     arrayList<int>::iterator it = L1.begin();
//     for (; it != L1.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
//     auto _fsort = [](int n1, int n2)
//     {
//         return n1 < n2;
//     };
//     L1.sort(L1.begin(), L1.end(), _fsort);
//     cout << "sorted L1 :" << L1 << endl;
//     try
//     {
//         L1.insert(30, 200);
//     }
//     catch (illegalIndex &e)
//     {
//         e.outputMessage();
//     }
//     cout << L1 << endl;
// }
// /*------------------链表测试-------------*/
// void test03()
// {
//     chainList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 50 + 10;
//         L1.push_back(num);
//     }
//     cout << L1 << " size = " << L1.size() << endl;
//     cout << "index of 51 :" << L1.indexOf(51) << " size = " << L1.size() << endl;
//     L1.insert(3, 0);
//     cout << "inserted L1 : " << L1 << " size = " << L1.size() << endl;
//     L1.erase(30);
//     cout << "erased L1 : " << L1 << " size = " << L1.size() << endl;
//     L1.swap(0, L1.size() - 1);
//     cout << "L1 : " << L1 << endl;
//     cout << "L1[0] = " << L1.get(0) << endl;
//     sort(L1);
//     L1.set(0, -1);
//     chainList<int>::iterator it = L1.begin();
//     for (int i = 0; i < L1.size(); i++)
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl;
//     L1[2] = 1;
//     cout << "L1 : " << L1 << endl;
//     L1.setSize(16);
//     cout << "L1 : " << L1 << endl;
//     L1.clear();
//     cout << "L1 : " << L1 << endl;
// }
// void test04()
// {
//     chainList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 50 + 10;
//         L1.push_back(num);
//     }
//     cout << "L1 : " << L1 << endl;
//     L1.removeRange(0, L1.size() - 1);
//     cout << "L1 : " << L1 << endl;
//     cout << "Size of L1 : " << L1.size() << endl;
// }
// void test05()
// {
//     chainList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 10;
//         L1.push_back(num);
//     }
//     cout << "L1 : " << L1 << endl;
//     L1.insert(3, 1);
//     cout << "Last index of 1 in L1 :" << L1.lastIndexOf(1) << endl;
// }
// void test06()
// {
//     srand(int(time(0)));
//     chainList<int> L1;
//     arrayList<int> L2;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 100;
//         L1.push_back(num);
//     }
//     chainList<int> L3;
//     L2 = convertToArray(L1);
//     L3 = L1;
//     L3.reverse();
//     L3.meld(L1);
//     sort(L3);
//     cout << "L1 : " << L1 << endl;
//     cout << "L2 : " << L2 << endl;
//     cout << "L3 : " << L3 << endl;
// }
// void test07()
// {
//     srand(int(time(0)));
//     chainList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         L1.push_back(i);
//     }
//     cout << "L1 : " << L1 << endl;
//     L1.moveRight(20);
//     cout << "L1 : " << L1 << endl;
//     L1.reverse();
//     cout << "L1 : " << L1 << endl;
// }
// void test08()
// {
//     circularList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 10;
//         L1.push_back(i);
//     }
//     circularList<int> L2 = L1;
//     cout << "L1 : " << L1 << endl;
//     cout << "L2 : " << L2 << endl;
//     circularList<int> L3;
//     L3 = L1;
//     L3[1] = -1;
//     // cout << L1.size() << endl;
//     cout << "L3 : " << L3 << endl;
// }
// void test09()
// {
//     srand(int(time(0)));
//     doubleLinkList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 50 + 50;
//         L1.push_front(num);
//     }
//     doubleLinkList<int> L2 = L1;
//     doubleLinkList<int> L3;
//     L3 = L2;
//     L3.swap(5, 6);
//     cout << "L1 :" << L1 << endl;
//     cout << "L2 :" << L2 << endl;
//     cout << "L3 :" << L3 << endl;
//     cout << L3.get(8) << endl;
//     cout << L3[8] << endl;
// }
// void test10()
// {
//     srand(int(time(0)));
//     doubleLinkList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 50 + 50;
//         L1.push_front(num);
//     }
//     cout << "L1 :" << L1 << endl;
//     L1.reverse();
//     cout << "L1 :" << L1 << endl;
//     doubleLinkList<int> L2;
//     L2.push_back(1);
//     L2.reverse();
//     cout << "L2 :" << L2 << endl;
//     // L2.moveLeft(1);
// }
// void test11()
// {
//     chainList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 50 + 50;
//         L1.push_back(num);
//     }
//     cout << "L1 : " << L1 << endl;
//     cout << "min : " << L1.min() << endl;
//     cout << "max : " << L1.max() << endl;
// }
// void test12()
// {
//     doubleLinkList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         int element = rand() % 101;
//         cout << element << " ";
//         L1.push_back(element);
//     }
//     cout << endl;
//     cout << "L1 :" << L1 << endl;
//     L1.moveLeft(1);
//     L1.moveRight(1);
//     cout << "L1 :" << L1 << endl;
// }
// void test13()
// {
//     srand(time(0));
//     const int N = 3;
//     polynomial_Array<int> P1;
//     polynomial_Array<int> P2;
//     arrayList<int> L1;
//     arrayList<int> L2;
//     for (int i = 0; i < N; i++)
//     {
//         int num = rand() % 6;
//         L1.push_back(num);
//     }
//     for (int i = 0; i < N - 1; i++)
//     {
//         int num = rand() % 6;
//         L2.push_back(num);
//     }
//     cout << "L1 = " << L1 << endl;
//     cout << "L2 = " << L2 << endl;
//     P1.input(L1);
//     P2.input(L2);
//     polynomial_Array<int> P3;
//     P3 = P2 = P1;
//     arrayList<int> L3 = P3.output();
//     cout << P2.degree() << endl;
//     cout << P2.output() << endl;
//     cout << P3.output() << endl;
//     cout << P1(1) << endl;
// }
// void test14()
// {
//     srand(time(0));
//     polynomial_Array<int> P1;
//     polynomial_Array<int> P2;
//     arrayList<int> L1;
//     arrayList<int> L2;
//     for (int i = 0; i < N; i++)
//     {
//         int num = rand() % 5 + 1;
//         L1.push_back(num);
//     }
//     for (int i = 0; i < N - 1; i++)
//     {
//         int num = rand() % 5 + 1;
//         L2.push_back(num);
//     }
//     P1.input(L1);
//     P2.input(L2);
//     polynomial_Array<int> P3 = P2.add(P1);
//     cout << P1.output() << endl;
//     cout << P2.output() << endl;
//     cout << P3.output() << endl;
//     cout << P3.subtract(P2).output() << endl;
//     cout << P1.multiply(P2).output() << endl;
// }
// void test15()
// {
//     srand(time(0));
//     polynomial_Chain<int> P1;
//     chainList<Type<int>> L1;
//     for (int i = N - 1; i >= 0; i--)
//     {
//         int num = rand() % 6;
//         Type<int> element;
//         element.set(i, num);
//         L1.push_back(element);
//     }
//     P1.input(L1);
//     cout << "L1 :" << L1 << endl;
//     cout << P1.output() << endl;
//     cout << P1(1) << endl;
// }
// void test16()
// {
//     chainList<Type<int>> L1;
//     for (int i = N - 1; i >= 0; i--)
//     {
//         int num = rand() % 6;
//         Type<int> element;
//         element.set(i, num);
//         L1.push_back(element);
//     }
//     chainList<Type<int>>::iterator it = L1.begin();
//     for (int i = 0; i < L1.size(); i++)
//     {
//         cout << *it << endl;
//         it++;
//     }
// }
// void test17()
// {
//     doubleLinkList<Type<int>> L1;
//     for (int i = N - 1; i >= 0; i--)
//     {
//         int num = rand() % 6;
//         Type<int> element;
//         element.set(i, num);
//         cout << "element: " << element << endl;
//         L1.push_back(element);
//     }
//     doubleLinkList<Type<int>>::iterator it = L1.end();
//     for (int i = 0; i < L1.size(); i++, it--)
//     {
//         cout << *it << endl;
//     }
//     // cout<<*L1.end()<<endl;
// }
// void test18()
// {
//     srand(time(0));
//     polynomial_Chain<int> P1;
//     polynomial_Chain<int> P2;
//     chainList<Type<int>> L1;
//     chainList<Type<int>> L2;
//     for (int i = N - 1; i >= 0; i--)
//     {
//         int num = rand() % 6;
//         Type<int> element;
//         element.set(i, num);
//         L1.push_back(element);
//     }
//     for (int i = N - 2; i >= 0; i--)
//     {
//         int num = rand() % 6;
//         Type<int> element;
//         element.set(i, num);
//         L2.push_back(element);
//     }
//     P1.input(L1);
//     P2.input(L2);
//     cout << P1.output() << endl;
//     cout << P2.output() << endl;
//     polynomial_Chain<int> P3;
//     polynomial_Chain<int> P4 = P2 - P1;
//     P3 = P1.add(P2);
//     cout << P3.output() << endl;
//     cout << P4.output() << endl;
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
//     // test08();
//     // test09();
//     // test10();
//     // test11();
//     // test12();
//     // test13();
//     // test14();
//     // test15();
//     // test16();
//     // test17();
//     test18();
//     system("pause");
//     return 0;
// }