// #include <iostream>
// #include "arrayQueue.hpp"
// #include "arrayDeque.hpp"
// #include "linkedQueue.hpp"
// #include <vector>
// using namespace std;
// void test01()
// {
//     arrayQueue<int> q1(5);
//     for (int i = 0; i < 4; i++)
//     {
//         q1.push(i);
//     }
//     cout << "q1.front : " << q1.front() << endl;
//     cout << "q1.back : " << q1.back() << endl;
//     cout << "q1.size : " << q1.size() << endl;
//     q1.pop();
//     cout << "q1.front : " << q1.front() << endl;
//     cout << "q1.back : " << q1.back() << endl;
//     cout << "q1.size : " << q1.size() << endl;
//     q1.output();
//     q1.push(5);
//     cout << "q1.front : " << q1.front() << endl;
//     cout << "q1.back : " << q1.back() << endl;
//     cout << "q1.size : " << q1.size() << endl;
//     q1.output();
//     q1.push(6);
//     q1.front() = -1;
//     cout << "q1.front : " << q1.front() << endl;
//     cout << "q1.back : " << q1.back() << endl;
//     cout << "q1.size : " << q1.size() << endl;
//     q1.output();
// }
// void test02()
// {
//     arrayQueue<int> q1;
//     q1.push(1);
//     q1.push(3);
//     q1.output();

//     arrayQueue<int> q2 = q1;
//     arrayQueue<int> q3;
//     q2.pop();
//     q2.push(4);
//     q2.output();
//     q3 = q2;
//     q3.output();
//     q1 = q3;
//     q1.output();
// }
// void test03()
// {
//     arrayDeque<int> Dq1;
//     for (int i = 0; i < 20; i++)
//     {
//         Dq1.push_front(i);
//     }
//     Dq1.push_front(-1);
//     Dq1.push_front(-2);
//     cout << "size = " << Dq1.size() << endl;
//     cout << "Is empty : " << Dq1.empty() << endl;
//     cout << "front = " << Dq1.front() << endl;
//     cout << "back = " << Dq1.back() << endl;
//     // Dq1[0] = 1234;
//     cout << "Dq1[0] = " << Dq1[19] << endl;
//     cout << Dq1 << endl;
// }
// void test04()
// {
//     vector<int> v1;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 10 + 10;
//         v1.push_back(num);
//     }
//     vector<int>::iterator it = v1.begin();
//     for (; it != (--v1.end()); it++)
//     {
//         printf("%d ", *it);
//     }
//     printf("\n");
//     v1.reserve(100000); // reserve后原数组的地址改变了
//     printf("%d ", *it);
// }
// void test05()
// {
//     linkedQueue<int> Lq1;
//     for (int i = 0; i < 10; i++)
//     {
//         Lq1.push(i);
//     }
//     Lq1.pop();
//     Lq1.push(-1);
//     for (int i = 0; i < 10; i++)
//     {
//         Lq1.pop();
//     }
//     cout << "Q : " << Lq1 << endl;
//     cout << "size = " << Lq1.size() << endl;
//     cout << "back = " << Lq1.back() << endl;
//     cout << "front = " << Lq1.front() << endl;
// }
// int main()
// {
//     // test01();
//     // test02();
//     // cout<<-10%3<<endl;
//     // test03();
//     // test04();
//     test05();
//     system("pause");
//     return 0;
// }