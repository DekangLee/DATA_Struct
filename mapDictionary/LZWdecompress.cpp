#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include "hashTable.hpp"
using namespace std;
#define INUPTFILENAME "codeFile.zzz"
#define OUTPUTFILE "decodeFile.txt"
ifstream in;                // 用于文件输入的全局变量
ofstream out;               // 用于文件输出的全局变量
const int DIVISOR = 4099;   // 散列函数的除数
const int MAX_CODES = 4096; // 2^12
const int EXCESS = 4;       // 12 - BYTE_SIZE
const int BYTE_SIZE = 8;
const int MASK = 15;   // 2 * BYTE_SZIE -1
const int ALPHA = 256; // 2^BYTE_SIZE
typedef pair<long, int> pairType;
pairType ht[MAX_CODES];    // 字典
char s[MAX_CODES];         // 用来重建文本
int size;                  // 重建文本的大小
bool bitsLeftOver = false; // false 表示没有余下的位
int leftOver;              // 待输出的代码位
void setFiles()
{
    // 建立文件输入输出流
    // char outputFile[50], inputFile[50];
    // // 检查是否有文件名
    // if (argc >= 2)
    // {
    //     strcpy(inputFile, argv[1]);
    // }
    // else
    // {
    //     // 无文件名需要根据要求提供文件名
    //     cout << "Enter name of file to compress:" << endl;
    //     cin >> inputFile;
    // }
    // // 打开二进制文件
    in.open(INUPTFILENAME, ios::in | ios::binary);
    if (in.fail())
    {
        cout << "文件打开失败！" << endl;
        exit(1);
    }
    // strcpy(outputFile, inputFile);
    // strcpy(outputFile, "zzz");
    out.open(OUTPUTFILE, ios::out);
}
// 输出与代码code对应的串
void output(int code)
{
    size = -1;
    while (code >= ALPHA)
    {
        // 字典中的后缀
        s[++size] = ht[code].second;
        code = ht[code].first;
    }
    s[++size] = code; // code < ALPHA
    // 解压的串是s[size] ... s[0]
    for (int i = size; i >= 0; --i)
    {
        out.put(s[i]);
    }
}
// 从压缩文件中提取代码 将压缩文件中的下一个代码存入code
bool getCode(int &code)
{
    // 如果不再有代码，返回false
    int c, d;
    if ((c = in.get()) == EOF)
        return false;
    // 检查前面是否有剩余的位
    // 如果有，与其连接
    if (bitsLeftOver)
        code = (leftOver << BYTE_SIZE) | c;
    else
    {
        // 没有剩余的位，需要加4位以凑足代码
        d = in.get(); // 另外8位
        code = (c << EXCESS) | (d >> EXCESS);
        leftOver = d & MASK; // 存储4位
    }
    bitsLeftOver = !bitsLeftOver;
    return true;
}
// LZW解压缩器
void decompress()
{
    int codesUsed = ALPHA; // 当前代码codesUsed
    // 输入和解压缩
    int pcode,          // 前面的代码
        ccode;          // 当前的代码
    if (getCode(pcode)) // 文件不为空
    {
        s[0] = pcode;  // 取pcode的代码
        out.put(s[0]); // 输出pcode的串
        size = 0;      // s[size] 是最后一个输出串的第一个字符
        while (getCode(ccode))
        {
            // 有一个代码
            if (ccode < codesUsed)
            {
                // 确定ccode
                output(ccode);
                if (codesUsed < MAX_CODES)
                {
                    // 建立新代码
                    ht[codesUsed].first = pcode;
                    ht[codesUsed].second = s[size];
                }
            }
            else // 特殊情况，没有定义的代码
            {
                ht[codesUsed].first = pcode;
                ht[codesUsed++].second = s[size];
                output(ccode);
            }
            pcode = ccode;
        }
    }
    in.close();
    out.close();
}
int main()
{
    setFiles();
    decompress();
    return 0;
}