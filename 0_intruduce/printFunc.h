#ifndef _PRINTFUNCH_
#define _PRINTFUNCH_
#include <iostream>
#include <cmath>
using namespace std;
template <class T>
void PrintArry(T Array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}
template <class T>
void PrintArry(T **Array, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Array[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
}
void PrintN1(int n)
{
    if (n == 0)
    {
        return;
    }
    PrintN1(n - 1);
    cout << n << endl;
}
void PrintN2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
}
double PolyCal_1(int n, double *a, double x)
{
    double res = 0.;
    for (int i = 0; i < n; i++)
    {
        res += a[i] * pow(x, i);
    }
    return res;
}
double PolyCal_2(int n, double *a, double x)
{
    double res = a[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        res = x * res + a[i - 1];
    }
    return res;
}
template <class T>
void Genetate_1D(T *a, int n, int l, int r) // 生成范围在l~r的随机数
{
    // srand(1); // 设置时间种子
    for (int i = 0; i < n; i++)
    {
        a[i] = l + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (r - l)));
    }
}
template <class T>
void Genetate_2D(T **a, int N, int M, int l, int r) // 生成范围在l~r的随机数
{
    // srand(1); // 设置时间种子
    for (int i = 0; i < N; i++)
    {
        a[i] = new T[M];
        for (int j = 0; j < M; j++)
            a[i][j] = l + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (r - l)));
    }
}
template <class T>
void MatrixMulti(T **a, T **b, T **c, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
template <class T>
void MatrixMulti(T **a, T **b, T **c, int n, int m, int l)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            c[i][j] = 0;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < l; j++)
    //     {
    //         for (int k = 0; k < m; k++)
    //         {
    //             c[i][j] += a[i][k] * b[k][j];
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < l; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
template <class T>
void FreeMem(T **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) != NULL)
        {
            delete[] *(a + i);
            *(a + i) = NULL;
        }
    }
    delete[] a;
}
#endif