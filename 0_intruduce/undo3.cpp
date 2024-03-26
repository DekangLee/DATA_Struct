// #include <iostream>
// #include <vector>
// #include <ctime>
// #include <fstream>
// #include <stack>
// using namespace std;
// const int ROW = 9;
// const int COLUM = 9;
// typedef vector<vector<char>> ARRAY_Char;
// template <class T>
// void print(const T &v)
// {
//     for (auto i : v)
//     {
//         for (auto j : i)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }
// pair<int, int> orientate(int i, int j)
// {
//     vector<int> v = {3, 6, 9};
//     int row = -1, colum = -1;
//     for (auto a : v)
//     {
//         if ((i - a) < 0)
//         {
//             row = a;
//             break;
//         }
//     }
//     for (auto a : v)
//     {
//         if ((j - a) < 0)
//         {
//             colum = a;
//             break;
//         }
//     }
//     pair<int, int> res = make_pair(row, colum);
//     return res;
// }
// bool tryToSolve(const ARRAY_Char &v_num, int i, int j, char num)
// {
//     for (int row = 0; row < ROW; row++)
//     {
//         if (row != i && v_num[row][j] == num)
//         {
//             return false;
//         }
//     }
//     for (int colum = 0; colum < ROW; colum++)
//     {
//         if (colum != j && v_num[i][colum] == num)
//         {
//             return false;
//         }
//     }
//     pair<int, int> location = orientate(i, j);
//     for (int a = location.first - 3; a < location.first; a++)
//     {
//         for (int b = location.second - 3; b < location.second; b++)
//         {
//             if (v_num[a][b] == num)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// vector<pair<int, int>> Find(ARRAY_Char &v_num)
// {
//     pair<int, int> res;
//     vector<pair<int, int>> v_res;
//     for (int i = 0; i < ROW; i++)
//     {
//         for (int j = 0; j < COLUM; j++)
//         {
//             if (v_num[i][j] == '0')
//             {
//                 res = make_pair(i, j);
//                 v_res.push_back(res);
//             }
//         }
//     }
//     return v_res;
// }
// void undo(ARRAY_Char &Data)
// {
//     stack<char> res;
//     vector<pair<int, int>> Position = Find(Data);
//     int flag = Position.size();
//     cout << "flag = " << flag << endl;
//     char number = '1';
//     int pos = 0;
//     while (pos != flag)
//     {
//         int r = Position[pos].first;
//         int c = Position[pos].second;
//         while (number <= '9')
//         {
//             if (tryToSolve(Data, r, c, number))
//             {
//                 Data[r][c] = number;
//                 break;
//             }
//             number = number + 1;
//         }
//         if (number <= '9')
//         {
//             res.push(number);
//             number = '1';
//             pos++;
//         }
//         else
//         {
//             // cout << "number = " << number << endl;
//             if (res.empty())
//                 return;
//             int r = Position[pos].first;
//             int c = Position[pos].second;
//             Data[r][c] = '0';
//             char prenumber = res.top();
//             res.pop();
//             pos--;
//             number = prenumber + 1;
//         }
//     }
//     return;
// }
// void test()
// {
//     ifstream ifs;
//     ifs.open("undo4.txt", ios::in);
//     ARRAY_Char v_num;
//     string buff;
//     v_num.resize(ROW);
//     for (int i = 0; i < ROW; i++)
//     {
//         for (int j = 0; j < COLUM; j++)
//         {
//             ifs >> buff;
//             v_num[i].push_back(buff[0]);
//         }
//     }
//     cout << "The problem is-------------------" << endl;
//     print(v_num);
//     cout << "The result is-------------------" << endl;
//     undo(v_num);
//     print(v_num);
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock();
//     test();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     return 0;
// }