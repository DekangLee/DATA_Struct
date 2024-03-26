// // /*
// //  * @Author: dekangLee dakang579@gmail.com
// //  * @Date: 2024-02-28 19:48:00
// //  * @LastEditors: dekangLee dakang579@gmail.com
// //  * @LastEditTime: 2024-02-28 20:24:58
// //  * @FilePath: \DATA_Struct\Graph\test.cpp
// //  * @Description:
// //  *
// //  * Copyright (c) 2024 by  dakang579@gmail.com, All Rights Reserved.
// //  */
// // #include <stdio.h>
// // #include <math.h>
// // const int N = 1000;
// // int _array[N];
// // int solution(int n, int num)
// // {
// //     int x;
// //     int y;
// //     int flag = 0;
// //     int sqrt_n = (int)sqrt(n);
// //     for (x = 1; x <= sqrt_n; ++x)
// //     {
// //         for (y = x; y <= sqrt_n; ++y)
// //         {
// //             if (x * x + y * y == n)
// //             {
// //                 flag = 1;
// //                 printf("No %d: %d*%d+%d*%d=%d\n", num, x, x, y, y, n);
// //             }
// //         }
// //     }
// //     return flag;
// // }
// // int main()
// // {
// //     int count = 0;
// //     for (int i = 1; i <= N; ++i)
// //     {
// //         int n;
// //         char c;
// //         scanf("%d%c", &n, &c);
// //         count++;
// //         _array[i] = n;
// //         printf("c = %c\n",c);
// //         if (c == ' ')
// //             break;
// //     }
// //     printf("count = %d\n", count);
// //     for (int i = 1; i <= count; ++i)
// //     {
// //         if (solution(_array[i], i-1) == 1)
// //             printf("\n");
// //     }
// //     return 0;
// // }

// // proj1.cpp
// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//    MyClass(int len) 
//    { 
//       array = new int[len];
//       arraySize = len;
//       for(int i = 0; i < arraySize; i++)
//          array[i] = i+1;
//    }

//    ~MyClass()
//    {
// // ERROR   **********found**********
//        delete[] array;
//    }

//    void Print() const
//    {
//       for(int i = 0; i < arraySize; i++)
// // ERROR   **********found**********
//          cout << array[i] << ' ';

//        cout << endl;
//     }
// private:
//    int *array;
//    int arraySize;
// };
// int main()
// {
// // ERROR   **********found**********
//    MyClass obj(10);

//    obj.Print();
//    return 0;
// }
