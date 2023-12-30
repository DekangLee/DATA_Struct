// #include <iostream>
// #include <time.h>
// #include "Example.h"
// #include <fstream>
// using namespace std;
// const int MAX_N = 10241;
// template <class T>
// int MaxSubSum1(const T *A, int N) // 时间复杂度为n^3
// {
//     int thisSum, MaxSum;
//     MaxSum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i; j < N; j++)
//         {
//             thisSum = 0;
//             for (int k = i; k <= j; k++)

//             {
//                 thisSum += A[k];
//             }
//             if (thisSum > MaxSum)
//             {
//                 MaxSum = thisSum;
//             }
//         }
//     }
//     return MaxSum;
// }
// template <class T>
// int MaxSubSum2(const T *A, int N) // 时间复杂度为n^2
// {
//     int thisSum, MaxSum;
//     MaxSum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         thisSum = 0;
//         for (int j = i; j < N; j++)
//         {
//             thisSum += A[j];
//             if (thisSum > MaxSum)
//             {
//                 MaxSum = thisSum;
//             }
//         }
//     }
//     return MaxSum;
// }
// template <class T>
// static int MaxSubSum3(const T *A, int Left, int Right) // 时间复杂度为nlogn  迭代版
// {
//     int MaxLeft, MaxRight;
//     int MaxLeftBorder, MaxRightBorder;
//     int LeftBorder, RightBorder;
//     int center, i;
//     if (Left == Right) // 基本情况
//     {
//         if (A[Left] > 0)

//             return A[Left];
//         else
//             return 0;
//     }
//     center = (Left + Right) / 2;

//     MaxLeft = MaxSubSum3(A, Left, center);
//     MaxRight = MaxSubSum3(A, center + 1, Right);
//     LeftBorder = 0;
//     RightBorder = 0;
//     MaxLeftBorder = 0;
//     MaxRightBorder = 0;
//     for (i = center; i >= Left; i--)
//     {
//         LeftBorder += A[i];
//         if (MaxLeftBorder < LeftBorder)
//             MaxLeftBorder = LeftBorder;
//     }
//     for (i = center + 1; i <= Right; i++)
//     {
//         RightBorder += A[i];
//         if (MaxRightBorder < RightBorder)
//             MaxRightBorder = RightBorder;
//     }
//     int Max = MaxLeft;
//     if (Max < MaxRight)
//     {
//         Max = MaxRight;
//     }
//     if (Max < (MaxLeftBorder + MaxRightBorder))
//     {
//         Max = (MaxLeftBorder + MaxRightBorder);
//     }
//     // cout << "MaxRight = " << MaxRight << endl;
//     // cout << "MaxLeft = " << MaxLeft << endl;
//     // cout << "MaxRightBorder + MaxLeftBorder = " << MaxRightBorder + MaxLeftBorder << endl;
//     // cout << "Max = " << Max << endl;
//     return Max;
// }
// template <class T>
// static int MaxSubSum3(const T *A, int N) // 分治算法迭代版
// {
//     int LeftMax = 0, RightMax = 0;
//     int LeftMaxBonder = 0, RightMaxBonder = 0;
//     T *B = new int[N];
//     int Maxwd = 1;
//     int wd = 1;
//     while (wd / 2 <= N)
//     {
//         int turn = 1;
//         int MaxTurn = (N % wd == 0 ? (N / wd) : (N / wd + 1));
//         int Left = 0, Right = min(wd - 1, N - 1);
//         while (turn <= MaxTurn)
//         {
//             // cout << "right = " << Right;
//             // cout << "  left = " << Left << endl;
//             int center = (Left + Right) / 2;
//             if (wd == 1)
//             {
//                 // center = Left;
//                 if (A[Left] > 0)
//                     LeftMax = A[Left];
//                 else
//                     LeftMax = 0;
//                 if (A[Right] > 0)
//                     RightMax = A[Right];
//                 else
//                     RightMax = 0;
//             }
//             else
//             {
//                 int index = Left / (wd / 2);
//                 if (wd / 2 > (Right - Left + 1))
//                 {
//                     LeftMax = RightMax = B[index];
//                 }
//                 else
//                 {
//                     LeftMax = B[index];
//                     RightMax = B[++index];
//                 }
//             }
//             // cout << "center = " << center << endl;
//             int LeftBorder = 0, RightBorder = 0;
//             LeftMaxBonder = 0, RightMaxBonder = 0;
//             for (int i = center; i >= 0; i--)
//             {
//                 LeftBorder += A[i];
//                 if (LeftMaxBonder < LeftBorder)
//                 {
//                     LeftMaxBonder = LeftBorder;
//                 }
//             }
//             for (int j = center + 1; j <= Right; j++)
//             {
//                 RightBorder += A[j];
//                 if (RightMaxBonder < RightBorder)
//                     RightMaxBonder = RightBorder;
//             }
//             int Max = LeftMax;
//             if (Max < RightMax)
//             {
//                 Max = RightMax;
//             }
//             if (Max < (LeftMaxBonder + RightMaxBonder))
//                 Max = LeftMaxBonder + RightMaxBonder;
//             B[turn - 1] = Max;
//             Right = min(Right + wd, N - 1);
//             Left = min(Left + wd, N - 1);
//             turn++;
//         }
//         wd *=2;
//     }
//     int Max = B[0];
//     delete[] B;
//     return Max;
// }

// template <class T>
// static int MaxSubSum4(const T *A, int N) // 联机算法，线性时间复杂度(也称为在线算法) 实际上该算法是该问题的用时最少的算法
// {
//     int ThisSum, MaxSum, i;
//     ThisSum = MaxSum = 0;
//     for (i = 0; i < N; i++)
//     {
//         ThisSum += A[i];
//         if (ThisSum > MaxSum)
//             MaxSum = ThisSum;
//         else if (ThisSum < 0)
//             ThisSum = 0;
//     }
//     return MaxSum;
// }
// void test01(int _MAX)
// {
//     clock_t start_time, end_time; // 记录时间
//     srand(int(time(0)));
//     int *A = new int[_MAX];
//     double Times;
//     // ofstream ofs("MaxSub.csv", ios::app);
//     // if (!ofs.is_open())
//     // {
//     //     cout << "文件打开失败！" << endl;
//     //     return;
//     // }
//     // ofs << _MAX << ",";
//     Genetate_1D(A, _MAX, -10, 10);

//     // start_time = clock();
//     // int MAxSum1 = MaxSubSum1(A, _MAX);
//     // end_time = clock();
//     // Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     // // printf("%f", Times);
//     // // ofs << Times << ",";
//     // cout << "MaxSubSum1_Time = " << Times << "s" << endl;

//     // start_time = clock();
//     // int MAxSum2 = MaxSubSum2(A, _MAX);
//     // end_time = clock();
//     // Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     // // ofs << Times << ",";
//     // cout << "MaxSubSum2_Time = " << Times << "s" << endl;

//     start_time = clock();
//     int MAxSum3 = MaxSubSum3(A, 0, _MAX - 1);
//     end_time = clock();
//     Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     // ofs << Times << ",";
//     cout << "MaxSubSum3_Time = " << Times << "s" << endl;
//     start_time = clock();
//     int MAxSum3_ = MaxSubSum3(A, _MAX);
//     end_time = clock();
//     Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     // ofs << Times << ",";
//     cout << "MaxSubSum3__Time = " << Times << "s" << endl;
//     // ofs << "0";
//     // ofs << "\n";
//     // PrintArry(A, _MAX);
//     start_time = clock();
//     int MAxSum4 = MaxSubSum4(A, _MAX);
//     end_time = clock();
//     Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     // ofs << Times << ",";
//     cout << "MaxSubSum3_Time = " << Times << "s" << endl;
//     // cout << "MaxSubSum1 = " << MAxSum1 << endl;
//     // cout << "MaxSubSum2 = " << MAxSum2 << endl;
//     cout << "MaxSubSum3 = " << MAxSum3 << endl;
//     cout << "MaxSubSum3_ = " << MAxSum3_ << endl;
//     cout << "MaxSubSum4 = " << MAxSum4 << endl;
//     delete[] A;
//     // ofs.close();
// }
// void test02()
// {
//     static int a = 0;
//     ofstream ofs("MaxSub.csv", ios::app);
//     if (!ofs.is_open())
//     {
//         cout << "文件打开失败！" << endl;
//         return;
//     }
//     double times = 1 / 3.0;
//     ofs << times << ",";
//     ofs.close();
//     cin.get();
// }
// void geneFile()
// {
//     ofstream ofs("MaxSub.csv", ios::trunc);
//     ofs << "Scale"
//         << ","
//         << "MAxSubSum1"
//         << ","
//         << "MAxSubSum2"
//         << ","
//         << "MAxSubSum3"
//         << ","
//         << "MAxSubSum4";
//     ofs << "\n";
//     ofs.close();
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock();
//     // for (int i = 5000; i < 50000; i = i + 500)
//     // {
//     //     test01(i);
//     // }
//     test01(MAX_N);
//     // geneFile();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     system("pause");
//     return 0;
// }