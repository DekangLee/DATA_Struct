#ifndef _MYSORT_
#define _MYSORT_
#include <iostream>
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
void SelectSort(T Arry[], int lenth)
{
    // 最大值的下标
    for (int i = 0; i < lenth; i++)
    {
        int max = i;
        for (int j = i + 1; j < lenth; j++)
        {
            if (Arry[j] < Arry[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            swap(Arry[max], Arry[i]);
        }
    }
}
template <class T>
void QuickSort(T Array[], int start, int end) // 快速排序 升序
{
    if (start >= end)
        return;
    int i = start;
    int j = end;
    T key = Array[i];
    while (i < j)
    {
        while (i < j && Array[j] > key)
        {
            j--;
        }
        swap(Array[i], Array[j]);

        while (i < j && Array[i] < key)
        {
            i++;
        }
        swap(Array[i], Array[j]);
    }
    Array[i] = key;
    QuickSort(Array, start, i - 1);
    QuickSort(Array, j + 1, end);
}
template <class T>
void InsertSort(T a[], int lenth) // 插入排序 降序
{
    for (int i = 1; i < lenth; i++)
    {
        if (a[i - 1] < a[i])
        {
            T temp = a[i];
            int j;
            for (j = i - 1; j >= 0 && a[j] < temp; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}
template <typename T>
void MergeSort(T arr[], int len)
{
    T *a = arr;
    T *b = new T[len];
    int count = 1;
    while (len > count)
    {
        count *= 2;
    }
    for (int wd = 2; wd <= count; wd *= 2)
    {
        // cout << "-------------------------" << endl;
        // cout << "WD = " << wd << endl;
        for (int start = 0; start < len; start = start + wd)
        {
            int mid = wd;
            if (mid + start > len)
            {
                mid = 1;
                while (len - start > mid)
                {
                    mid *= 2;
                }
            }

            // cout << "mid = " << mid << endl;
            int start1 = min(start, len - 1), end1 = min(start + mid / 2 - 1, len - 1);
            int start2 = min(start + mid / 2, len - 1), end2 = min(start + mid - 1, len - 1);
            // cout << "len = " << len << " start1 = " << start1 << " end1 = " << end1 << " start2 = " << start2 << " end2 = " << end2 << endl;
            int k = start1;
            // cout << "K = " << k << endl;
            if (start1 == start2)
            {
                b[k] = a[start1];
                break;
            }
            while (start1 <= end1 && start2 <= end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];

            while (start1 <= end1)
            {
                // cout << "1-K = " << k << endl;
                b[k++] = a[start1++];
            }
            while (start2 <= end2)
            {
                // cout << "2-K = " << k << endl;
                b[k++] = a[start2++];
            }
            // PrintArry(b, len);
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}
// void MergeSort(T arr[], int len)
// {
//     T *a = arr;
//     T *b = new T[len];
//     for (int seg = 1; seg < len; seg += seg)
//     {
//         for (int start = 0; start < len; start += seg + seg)
//         {
//             int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
//             int k = low;
//             int start1 = low, end1 = mid;
//             int start2 = mid, end2 = high;
//             while (start1 < end1 && start2 < end2)
//                 b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
//             while (start1 < end1)
//                 b[k++] = a[start1++];
//             while (start2 < end2)
//                 b[k++] = a[start2++];
//         }
//         T *temp = a;
//         a = b;
//         b = temp;
//     }
//     if (a != arr)
//     {
//         for (int i = 0; i < len; i++)
//             b[i] = a[i];
//         b = a;
//     }
//     delete[] b;
// }
template <typename T>
void MergeSortRecursive(T *arr, int len, int start, int end)
{

    // cout << "len = " << len << " start = " << start << " end = " << end << endl;
    if (len == 1)
        return;
    int count = 1;
    while (len > count)
    {
        count *= 2;
    }
    // cout << "count = " << count << endl;
    int *b = new T[len];
    int start1 = start, end1 = min(start + count / 2 - 1, start + len - 1);
    int start2 = min(start + count / 2, start + len - 1), end2 = min(start + count - 1, start + len - 1);
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    // cout << "len = " << len << " start1 = " << start1 << " end1 = " << end1 << " start2 = " << start2 << " end2 = " << end2 << endl;
    MergeSortRecursive(arr, len1, start1, end1);
    MergeSortRecursive(arr, len2, start2, end2);
    int k = 0; // 注意这里新开辟的数组索引是从0开始
    while (start1 <= end1 && start2 <= end2)
    {
        b[k] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
        // cout << "0_b[k] = " << b[k] << endl;
        k++;
    }
    while (start1 <= end1)
    {

        b[k] = arr[start1++];
        // cout << "1_b[k] = " << b[k] << endl;
        k++;
    }
    while (start2 <= end2)
    {

        b[k] = arr[start2++];
        // cout << "2_b[k] = " << b[k] << endl;
        k++;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i + start] = b[i];
    }
    // cout<<"b:";
    // PrintArry(b,len);
    // cout << "arr:";
    // PrintArry(arr, 4);
    delete[] b;
}
template <typename T>
void Reverse(T *Array, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        T temp = Array[i];
        Array[i] = Array[len - i - 1];
        Array[len - i - 1] = temp;
    }
}
#endif