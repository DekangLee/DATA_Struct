// #include <iostream>
// #include <time.h>
// #include "Example.h"
// using namespace std;
// const int NUMBER = 60000;
// typedef int TYPE;
// static int a = 0;
// // static int a = 10;  // 不能重复定义
// void test01()
// {
//     cout << INT32_MAX << endl;

//     // PrintN1(NUMBER);
//     // PrintN2(NUMBER);
// }
// void test02()
// {
//     double x = 0;
//     cin >> x;
//     double arr[MAXSIZE];
//     Genetate(arr, MAXSIZE, 1, 2);
//     // PrintArry(arr, MAXSIZE);
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     double res = PolyCal_1(MAXSIZE, arr, x);
//     // double res = PolyCal_2(MAXSIZE,arr,x);
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     cout << "res = " << res << endl;
// }
// void test03()
// {
//     int N, M, L;
//     cout << "请输入计算方阵的大小：" << endl;
//     cin >> N >> M >> L;
//     cout << "--------------" << endl;
//     TYPE **a = new TYPE *[N];
//     TYPE **b = new TYPE *[M];
//     TYPE **c = new TYPE *[N];
//     Genetate_2D(a, N, M, 2, 4);
//     Genetate_2D(b, M, L, 5, 6);
//     Genetate_2D(c, N, L, 1, 2);
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     MatrixMulti(a, b, c, N, M, L);
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     // PrintArry(a, N, M);
//     // PrintArry(b, M, L);
//     // PrintArry(c, N, L);

//     FreeMem(a, N, M);
//     FreeMem(b, M, L);
//     FreeMem(c, N, L);
// }
// int test04(int N)
// {
//     static int a = 0; // 静态变量也存在作用域 在该作用域下其不会被编译器销毁
//     if (N == 0)
//     {
//         return a;
//     }
//     test04(N - 1);
//     a++;
//     return a;
// }

// int main()
// {

//     // test01();
//     // test02();
//     // test03();
//     // cout << test04(6) << endl;
//     // cout << test04(5) << endl; // 多次调用该函数，static int a的值一直在增加
//     system("pause");
// }