/*
 * @Author: dekangLee dakang579@gmail.com
 * @Date: 2023-12-30 13:32:50
 * @LastEditors: dekangLee dakang579@gmail.com
 * @LastEditTime: 2024-03-02 18:24:58
 * @FilePath: \DATA_Struct\test.cpp
 * @Description:
 *
 * Copyright (c) 2023 by  dakang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int ans = 0;
    int pos = 0;
    int p = -1;
    cout << "str size = " << str.size() << endl;
    while (pos < str.size())
    {
        cout << "pos = " << pos << endl;
        cout << "p = " << p << endl;
        if (str[pos] != '?' && str[pos] == str[pos + 1])
        {
            p = pos + 1;
            pos += 2;
            ans++;
        }
        else if (str[pos] != '?' && str[pos] != str[pos + 1])
            pos++;
        else if (str[pos] == '?')
        {
            if (p < pos - 1)
            {
                str[pos] = str[pos - 1];
                p = pos;
                pos++;
                ans++;
            }
            else if (p == pos - 1)
            {
                if (pos != str.size() && str[pos + 1] != '?')
                    str[pos] = str[pos + 1];
                if (pos != str.size() && str[pos + 1] == '?')
                    str[pos] = str[pos + 1] = '0';
                if (pos == str.size() - 1)
                {
                    str[pos] = '0';
                    break;
                }
                p = pos + 1;
                pos += 2;
                ans++;
            }
        }
        cout << "ans = " << ans << endl;
    }
    cout << str << endl;
    cout << ans << endl;
    return 0;
}