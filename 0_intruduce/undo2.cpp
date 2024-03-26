// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
// const int ROW = 9;
// const int COLUM = 9;
// int Data[ROW][COLUM];
// void print(int (*v_num)[COLUM])
// {
//     for (int i = 0; i < ROW; i++)
//     {
//         for (int j = 0; j < COLUM; j++)
//             cout << v_num[i][j] << " ";
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
// bool tryToSolve(int (*v_num)[COLUM], int i, int j, int num)
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
// vector<pair<int, int>> Find(int (*v_num)[COLUM])
// {
//     pair<int, int> res;
//     vector<pair<int, int>> v_res;
//     for (int i = 0; i < ROW; i++)
//     {
//         for (int j = 0; j < COLUM; j++)
//         {
//             if (v_num[i][j] == 0)
//             {
//                 res = make_pair(i, j);
//                 v_res.push_back(res);
//             }
//         }
//     }
//     return v_res;
// }
// void undo(int (*Data)[COLUM])
// {
//     stack<int> res;
//     vector<pair<int, int>> Position = Find(Data);
//     int flag = Position.size();
//     int number = 1;
//     int pos = 0;
//     while (pos != flag)
//     {
//         // cout << "Position:" << Position[pos].first << "," << Position[pos].second << endl;
//         int r = Position[pos].first;
//         int c = Position[pos].second;
//         while (number <= 9)
//         {
//             // cout << "tryToSolve:" << tryToSolve(Data, r, c, number) << endl;
//             // cout << "number:" << number << endl;
//             if (tryToSolve(Data, r, c, number))
//             {
//                 Data[r][c] = number;
//                 break;
//             }
//             number++;
//         }
//         if (number <= 9)
//         {
//             res.push(number);
//             number = 1;
//             pos++;
//             // cout << "res.top():" << res.top() << endl;
//         }
//         else // 无解回溯至res的顶端数字
//         {
//             if (res.empty())
//                 return;
//             int r = Position[pos].first;
//             int c = Position[pos].second;
//             Data[r][c] = 0;
//             int prenumber = res.top();
//             res.pop();
//             pos--;
//             number = prenumber + 1;
//         }
//     }
//     return;
// }
// int main()
// {
//     for (int i = 0; i < ROW; ++i)
//     {
//         int num;
//         for (int j = 0; j < COLUM; ++j)
//         {
//             cin >> num;
//             Data[i][j] = num;
//         }
//     }
//     undo(Data);
//     print(Data);
//     return 0;
// }