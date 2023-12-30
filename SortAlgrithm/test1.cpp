#include <iostream>
#include <time.h>
#include <cstdlib>
#include "MySort.h"
// #include"MySort.cpp"
const int MAXSIZE = 100000;
using namespace std;
template <class T>
void Genetate(T *a, int n, int l, int r) // 生成范围在l~r的随机数
{
    srand(time(0)); // 设置时间种子
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (r - l + 1) + l; // 生成区间r~l的随机数
    }
}

void test01()
{
    int IntArry[MAXSIZE];
    Genetate(IntArry, MAXSIZE, 0, 100);
    // PrintArry(IntArry, sizeof(IntArry) / sizeof(int));
    // myQSort(CharArry, 0, 6);
    // QuickSort(IntArry, 0, MAXSIZE-1);
    // InsertSort(IntArry, MAXSIZE);
    MergeSort(IntArry,MAXSIZE);
    // MergeSortRecursive(IntArry,MAXSIZE,0,MAXSIZE-1);
    // Reverse(IntArry,MAXSIZE);
    // PrintArry(IntArry, MAXSIZE);
}
void test02()
{
    int *p = new int[4];
    delete [] p;
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock(); // 获取开始执行时间
    test01();
    // test02();
    end_time = clock();
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "程序运行时间：" << Times << "s" << endl;
    system("pause");
}