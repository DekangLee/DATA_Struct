// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <fstream>
// #include "hashTable.hpp"
// #define FILENAME "codeFile.txt"
// using namespace std;
// ifstream in;                // 用于文件输入的全局变量
// ofstream out;               // 用于文件输出的全局变量
// const int DIVISOR = 4099;   // 散列函数的除数
// const int MAX_CODES = 4096; // 2^12
// const int MASK1 = 255;      // ALPHA - 1
// const int EXCESS = 4;       // 12 - BYTE_SIZE
// const int BYTE_SIZE = 8;
// const int MASK2 = 15;  // 2 * BYTE_SZIE -1
// const int ALPHA = 256; // 2^BYTE_SIZE
// typedef pair<long, int> pairType;
// bool bitsLeftOver = false; // false 表示没有余下的位
// int leftOver;              // 待输出的代码位

// void setFiles()
// {
//     // 建立文件输入输出流
//     char outputFile[50], inputFile[50];
//     // // 检查是否有文件名
//     // if (argc >= 2)
//     // {
//     //     strcpy(inputFile, argv[1]);
//     // }
//     // else
//     // {
//     //     // 无文件名需要根据要求提供文件名
//     //     cout << "Enter name of file to compress:" << endl;
//     //     cin >> inputFile;
//     // }
//     // 打开二进制文件
//     strcpy(inputFile, FILENAME);
//     in.open(inputFile, ios::in | ios::binary);
//     if (in.fail())
//     {
//         cout << "文件打开失败！" << endl;
//         exit(1);
//     }
//     cout << inputFile << endl;
//     char ch = '.';
//     strncpy(outputFile, inputFile,(strchr(inputFile, ch) - inputFile));
//     cout << outputFile << endl;
//     cout << strchr(inputFile, ch) - inputFile << endl;
//     strcat(outputFile, ".zzz");
//     out.open(outputFile, ios::out | ios::binary);
// }
// void output(long pcode)
// {
//     // 输出8位，把剩余位保存
//     int c, d;
//     if (bitsLeftOver)
//     {
//         // 前面的剩余位
//         d = int(pcode & MASK1);
//         c = int((leftOver << EXCESS) | (pcode >> BYTE_SIZE));
//         out.put(c);
//         out.put(d);
//         bitsLeftOver = true;
//     }
//     else
//     {
//         // 前面没有剩余的位
//         leftOver = pcode & MASK1;
//         c = int(pcode >> EXCESS);
//         out.put(c);
//         bitsLeftOver = true;
//     }
// }
// // LZW压缩器
// void compress()
// {
//     // 定义和初始化代码字典
//     hashTable<long, int> h(DIVISOR);
//     for (int i = 0; i < ALPHA; ++i)
//     {
//         h.insert(pairType(i, i));
//     }
//     int codesUsed = ALPHA;
//     // 输入和压缩
//     int c = in.get();
//     if (c != EOF) // 文件不为空
//     {
//         long pcode = c; // 前缀代码
//         while ((c = in.get()) != EOF)
//         {
//             // 处理字符c
//             long theKey = (pcode << BYTE_SIZE) + c;
//             pairType *thePair = h.find(theKey);
//             if (thePair == nullptr)
//             {
//                 // 关键字并不在表里
//                 output(pcode);
//                 if (codesUsed < MAX_CODES) // 建立新代码
//                     h.insert(pairType((pcode << BYTE_SIZE) | c, codesUsed++));
//                 pcode = c;
//             }
//             else
//                 pcode = thePair->second; // 关键字theKey在表中
//         }
//         // 输出最后的代码
//         output(pcode);
//         if (bitsLeftOver)
//             out.put(leftOver << EXCESS);
//     }
//     out.close();
//     in.close();
// }
// int main()
// {
//     setFiles();
//     compress();
//     // in.open("codeFile.txt", ios::in);
//     // out.open("decodeFile.txt", ios::out);
//     // if (in.fail())
//     // {
//     //     cout << "文件打开失败" << endl;
//     //     return 1;
//     // }
//     // char ch;
//     // while ((ch = in.get()) != EOF)
//     // {
//     //     out << ch;
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // in.close();
//     // out.close();
//     return 0;
// }