// #include <iostream>
// #include <ctime>
// #include <string>
// #include "arrayStack.hpp"
// #include "linkedStack.hpp"
// using namespace std;
// void test01()
// {
//     arrayStack<int> S1(5);
//     for (int i = 0; i < 10; i++)
//     {
//         int element = rand() % 10;
//         cout << "stack top = " << S1.size() - 1 << " " << element << endl;
//         S1.push(element);
//     }
//     cout << "--------------" << endl;
//     while (!S1.empty())
//     {

//         cout << "stack top = " << S1.size() - 1 << " " << S1.top() << endl;
//         S1.pop();
//     }
// }
// void test02()
// {
//     arrayStack<int> S1;
//     arrayStack<int> S2;
//     for (int i = 0; i < 5; i++)
//     {
//         int element = rand() % 10;
//         S1.push(element);
//         S2.push(element);
//     }
//     arrayStack<int> S3 = S1.merge(S2);
//     cout << "S1:------" << endl;
//     cout << S1;
//     cout << "S2:------" << endl;
//     cout << S2;
//     cout << "S3:------" << endl;
//     cout << S3;
// }
// void test03()
// {
//     srand(time(0));
//     linkedStack<int> S1;
//     linkedStack<int> S2;
//     for (int i = 0; i < 5; i++)
//     {
//         int element = rand() % 10;
//         S1.push(element);
//         S2.push(element - 1);
//         cout << "stackTop = " << S1.size() - 1 << " element = " << S1.top() << endl;
//     }
//     linkedStack<int> S3 = S1.merge(S2);
//     cout << "--------------" << endl;
//     cout << S3;
// }
// // 数据结构栈应用
// // 1、括号匹配
// void printMatchedPairs(string expr)
// {
//     arrayStack<int> s;
//     int lenth = (int)expr.size();
//     for (int i = 0; i < lenth; i++)
//     {
//         if (expr.at(i) == '(')
//             s.push(i);
//         else if (expr.at(i) == ')')
//             try
//             {
//                 cout << s.top() << " " << i << endl; // 此处返回匹配括号的位置
//                 s.pop();
//             }
//             catch (stackEmpty &e)
//             {
//                 e.outputMessage();
//             }
//     }
//     while (!s.empty())
//     {
//         cout << "No match for left parenthesis at " << s.top() << endl;
//         s.pop();
//     }
// }
// // 汉诺塔问题
// // 1、递归求解,指数时间复杂度
// void towersOfHanoi(int n, int x, int y, int z)
// {
//     if (n > 0)
//     {
//         towersOfHanoi(n - 1, x, z, y);
//         cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
//         towersOfHanoi(n - 1, z, y, x);
//     }
// }
// // 2、利用栈求解
// arrayStack<int> tower[3];
// void moveAndShow(int, int, int, int);
// void towersOfHanoi(int n)
// {
//     for (int d = n; d > 0; d--)
//     {
//         tower[0].push(d);
//     }
//     moveAndShow(n, 1, 2, 3);
// }
// void showState(const arrayStack<int> *s)
// {
//     cout << "tower1 = " << s[0].size() << " tower2 = " << s[1].size() << " tower3 = " << s[2].size() << endl;
// }
// void moveAndShow(int n, int x, int y, int z)
// {
//     if (n > 0)
//     {
//         moveAndShow(n - 1, x, z, y);
//         int d = tower[x - 1].top();
//         tower[x - 1].pop();
//         tower[y - 1].push(d);
//         cout << "tower" << x << "-->"
//              << "tower" << y << endl;
//         showState(tower);
//         moveAndShow(n - 1, z, y, x);
//     }
// }
// void test04()
// {
//     arrayStack<int> *s = new arrayStack<int>;
//     cout << s->size() << endl;
//     delete s;
// }
// // 列车车厢重排问题
// arrayStack<int> *track;
// int numberOfCars;
// int numberOfTracks;
// int smallestCar;
// int itsTracks;
// bool putInHoldingTrack(int inputOrder);
// void outputFromHoldingTrack();
// bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
// {
//     numberOfCars = theNumberOfCars;
//     numberOfTracks = theNumberOfTracks;
//     track = new arrayStack<int>[numberOfTracks + 1];
//     int nextCarToOutput = 1;
//     smallestCar = numberOfCars + 1; // 缓冲轨道无车厢
//     for (int i = 1; i <= numberOfCars; i++)
//     {
//         if (inputOrder[i] == nextCarToOutput)
//         {
//             cout << "Move car " << inputOrder[i] << " form input track to output track" << endl;
//             nextCarToOutput++;
//             while (smallestCar == nextCarToOutput)
//             {
//                 outputFromHoldingTrack();
//                 nextCarToOutput++;
//             }
//         }
//         else if (!putInHoldingTrack(inputOrder[i]))
//             return false;
//     }
//     return true;
// }
// void test05()
// {
//     int carSquence[] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
//     cout << railroad(carSquence, 9, 3) << endl;
// }
// // 开关盒布线问题
// bool checkBox(int net[], int n)
// {
//     arrayStack<int> *s = new arrayStack<int>(n);
//     for (int i = 0; i < n; i++)
//     {
//         if (!s->empty())
//         {
//             if (net[i] == net[s->top()]) // 小技巧
//                 s->pop();
//             else
//                 s->push(i);
//         }
//         else
//             s->push(i);
//     }
//     if (s->empty())
//     {
//         cout << "Switch box is routable" << endl;
//         return true;
//     }
//     else
//     {
//         cout << "Switch box is not routable" << endl;
//         return false;
//     }
// }
// void test06()
// {
//     int net[8];
//     for (int i = 0; i < 8; i++)
//     {
//         cin >> net[i];
//     }
//     cout << checkBox(net, sizeof(net) / sizeof(int));
// }
// // 解决离线等价类问题
// void offline()
// {
//     int n, r; // 分别为元素个数和关系个数
//     cout << "Enter number of elements" << endl;
//     cin >> n;
//     if (n < 2)
//     {
//         cout << "Too few elements" << endl;
//         return;
//     }
//     cout << "Enter number of relations" << endl;
//     cin >> r;
//     if (r < 1)
//     {
//         cout << "Too few relations" << endl;
//         return;
//     }
//     arrayStack<int> *list = new arrayStack<int>[n + 1];
//     int a, b;
//     for (int i = 1; i <= r; i++)
//     {
//         cout << "Enter next relation/pair" << endl;
//         cin >> a >> b;
//         list[a].push(b);
//         list[b].push(a);
//     }
//     // 初始化等价类
//     arrayStack<int> unprocessedList;
//     bool *out = new bool[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         out[i] = false;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (!out[i])
//         {
//             cout << "Next class is : " << i << " ";
//             out[i] = true;
//         }
//         unprocessedList.push(i);
//         while (!unprocessedList.empty())
//         {
//             int j = unprocessedList.top();
//             unprocessedList.pop();
//             while (!list[j].empty())
//             {
//                 int q = list[j].top();
//                 list[j].pop();
//                 if (!out[q])
//                 {
//                     cout << q << " ";
//                     out[q] = true;
//                     unprocessedList.push(q);
//                 }
//             }
//         }
//         cout << endl;
//     }
//     cout << "End of list of equivalence classes" << endl;
// }
// int main()
// {
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     // string s="(s0as)";
//     // printMatchedPairs(s);
//     // towersOfHanoi(1, 1, 2, 3);
//     // towersOfHanoi(4);
//     // test05();
//     // test06();
//     offline();
//     system("pause");
//     return 0;
// }
// void outputFromHoldingTrack()
// {
//     track[itsTracks].pop();
//     cout << "Move car " << smallestCar << " from holding track " << itsTracks << " to output track" << endl;
//     smallestCar = numberOfCars + 2;
//     for (int i = 1; i <= numberOfTracks; i++)
//     {
//         if (!track[i].empty() && (track[i].top() < smallestCar))
//         {
//             smallestCar = track[i].top();
//             itsTracks = i;
//         }
//     }
// }
// bool putInHoldingTrack(int c)
// {
//     // cout<<c<<endl;
//     int bestTrack = 0;
//     int bestTop = numberOfCars + 1;
//     for (int i = 1; i <= numberOfTracks; i++)
//     {
//         if (!track[i].empty())
//         {
//             int topCar = track[i].top();
//             if (c < topCar && topCar < bestTop)
//             {
//                 bestTop = topCar;
//                 bestTrack = i;
//             }
//         }
//         else if (bestTrack == 0)
//             bestTrack = i;
//     }
//     if (bestTrack == 0)
//         return false;
//     track[bestTrack].push(c);
//     cout << "Move car " << c << " from input track"
//          << " to hloding track " << bestTrack << endl;
//     if (c < smallestCar)
//     {
//         smallestCar = c;
//         itsTracks = bestTrack;
//     }
//     return true;
// }