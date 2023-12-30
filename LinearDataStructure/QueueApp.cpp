// #include <iostream>
// #include "arrayQueue.hpp"
// #include "linkedQueue.hpp"
// #include <fstream>
// using namespace std;
// // 列车车箱重排问题
// arrayQueue<int> *track;
// int numberOfCars;
// int numberOfTracks;
// int smallestCar;
// int itsTrack;
// void outputFromHoldingTrack()
// {
//     track[itsTrack].pop();
//     cout << "Move car " << smallestCar << " from holding track " << itsTrack << " to output track" << endl;
//     smallestCar = numberOfCars + 12;
//     for (int i = 1; i < numberOfTracks; i++)
//     {
//         if (!track[i].empty() && track[i].front() < smallestCar)
//         {
//             smallestCar = track[i].front();
//             itsTrack = i;
//         }
//     }
// }
// bool putInHoldingTrack(int c)
// {
//     int bestTrack = 0; // 离当前编号越近越优先选择
//     int bestLast = 0;
//     for (int i = 1; i <= numberOfTracks; i++)
//     {
//         if (!track[i].empty())
//         {
//             if (c > track[i].back() && track[i].back() > bestLast)
//             {
//                 bestLast = track[i].back();
//                 bestTrack = i;
//             }
//         }
//         else if (bestTrack == 0)
//             bestTrack = i;
//     }
//     if (bestTrack == 0)
//         return false;
//     track[bestTrack].push(c);
//     cout << "Move car " << c << " from input track to holding track " << bestTrack << endl;
//     if (c < smallestCar)
//     {
//         smallestCar = c;
//         itsTrack = bestTrack;
//     }
//     return true;
// }
// bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
// {
//     numberOfCars = theNumberOfCars;
//     numberOfTracks = theNumberOfTracks;
//     track = new arrayQueue<int>[numberOfTracks + 1];
//     int nextCarToOutput = 1;
//     smallestCar = numberOfCars + 1; // 缓冲轨道无车厢
//     for (int i = 1; i <= numberOfCars; i++)
//     {
//         if (inputOrder[i] == nextCarToOutput)
//         {
//             cout << "Move car " << inputOrder[i] << " form input track to output track" << endl;
//             nextCarToOutput++;
//             while (smallestCar == nextCarToOutput)
//             {
//                 outputFromHoldingTrack();
//                 nextCarToOutput++;
//             }
//         }
//         else if (!putInHoldingTrack(inputOrder[i]))
//             return false;
//     }
//     return true;
// }
// void test01()
// {
//     int carSquence[] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
//     cout << railroad(carSquence, 9, 3) << endl;
// }
// // 电路布线问题, 该算法对终点的搜索明显为广度优先，搜索速度较慢，但是搜索到的路径是最优的（最短）
// struct position
// {
//     int row;
//     int col;
// };
// position start;
// position finish;
// const int size = 7;
// int pathLenth;
// arrayQueue<int> q;
// position *path = new position[pathLenth];
// int Grid[size + 2][size + 2];
// template <class T>
// void print(T (*arr)[size + 2], int start1, int end1, int start2, int end2);
// bool findPath()
// {
//     if ((start.row == finish.row) && (start.col == finish.col))
//     {
//         pathLenth = 0;
//         return true;
//     }
//     position offset[4];
//     offset[0].row = 0; // 右
//     offset[0].col = 1;
//     offset[1].row = 1; // 下
//     offset[1].col = 0;
//     offset[2].row = 0; // 左
//     offset[2].col = -1;
//     offset[3].row = -1; // 上
//     offset[3].col = 0;
//     for (int i = 0; i <= size + 1; i++)
//     {
//         Grid[0][i] = Grid[size + 1][i] = 1;
//         Grid[i][0] = Grid[i][size + 1] = 1;
//     }
//     position here = start;
//     Grid[start.row][start.col] = 2;
//     int numOfNbrs = 4;
//     arrayQueue<position> q;
//     position nbr;
//     do
//     {
//         for (int i = 0; i < numOfNbrs; i++)
//         {
//             nbr.row = here.row + offset[i].row;
//             nbr.col = here.col + offset[i].col;
//             if (Grid[nbr.row][nbr.col] == 0)
//             {
//                 cout << "here:"
//                      << "(" << here.row << "," << here.col << ") " << endl;
//                 cout << "nbr:"
//                      << "(" << nbr.row << "," << nbr.col << ") " << endl;
//                 Grid[nbr.row][nbr.col] = Grid[here.row][here.col] + 1;
//                 if ((nbr.row == finish.row) && (nbr.col == finish.col))
//                     break;
//                 q.push(nbr);
//             }
//         }

//         if ((nbr.row == finish.row) && (nbr.col == finish.col))
//         {
//             cout << "end" << endl;
//             break;
//         }

//         if (q.empty())
//             return false;
//         here = q.front();
//         q.pop();
//     } while (true);
//     // 构造路径
//     pathLenth = Grid[finish.row][finish.col] - 2;

//     // 回溯至起点 finish->start
//     cout << "current status:" << endl;
//     cout << "pathLenth = " << pathLenth << endl;
//     here = finish;
//     for (int j = pathLenth - 1; j >= 0; j--)
//     {
//         path[j] = here;
//         for (int i = 0; i < numOfNbrs; i++)
//         {
//             nbr.row = here.row + offset[i].row;
//             nbr.col = here.col + offset[i].col;
//             cout << "here:"
//                  << "(" << here.row << "," << here.col << ") " << endl;
//             cout << "nbr:"
//                  << "(" << nbr.row << "," << nbr.col << ") " << endl;
//             cout << "Grid: " << Grid[nbr.row][nbr.col] << endl;
//             if (Grid[nbr.row][nbr.col] == j + 2)
//                 break;
//         }
//         here = nbr;
//     }
//     return true;
// }
// void generate()
// {
//     start.col = 2;
//     start.row = 3;
//     finish.col = 6;
//     finish.row = 4;
//     ifstream ifs("data1.txt", ios::in);
//     if (!ifs.is_open())
//     {
//         cout << "Failed to open this file!" << endl;
//         return;
//     }
//     char ch;
//     for (int i = 1; i < size + 1; i++)
//     {
//         for (int j = 1; j < size + 1; j++)
//         {
//             ifs >> ch;
//             int number = ch - 48;
//             Grid[i][j] = number;
//         }
//     }
//     ifs.close();
// }
// template <class T>
// void print(T (*arr)[size + 2], int start1, int end1, int start2, int end2)
// {
//     for (int i = start1; i <= end1; i++)
//     {
//         for (int j = start2; j <= end2; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// void test02()
// {
//     generate();
//     print(Grid, 1, size, 1, size);
//     cout << "---------" << endl;
//     if (!findPath())
//     {
//         cout << "No valid path!" << endl;
//         // return;
//     }
//     // print(Grid, 0, size + 1, 0, size + 1);
//     for (int i = 0; i < pathLenth; i++)
//     {
//         cout << "(" << path[i].row << "," << path[i].col << ") "
//              << "-> ";
//     }
//     cout << endl;
//     cout << "---------" << endl;
//     print(Grid, 0, size + 1, 0, size + 1);
// }
// // 图元识别
// const int Row = 7;
// const int Colum = 7;
// int Graph[Row + 2][Colum + 2];
// void genGraph()
// {
//     ifstream ifs("data2.txt", ios::in);
//     if (!ifs.is_open())
//     {
//         cout << "Failed to open this file!" << endl;
//         return;
//     }
//     char ch;
//     for (int i = 1; i <= Row; i++)
//     {
//         for (int j = 1; j <= Colum; j++)
//         {
//             ifs >> ch;
//             // cout << "buff " << ch << endl;
//             int number = ch - int('0');
//             // cout << "number = " << number << endl;
//             // cout << "i = " << i << " j = " << j << endl;
//             Graph[i][j] = number;
//         }
//     }
//     ifs.close();
// }
// void labelComponents()
// {
//     position offset[4];
//     offset[0].row = 0; // 右
//     offset[0].col = 1;
//     offset[1].row = 1; // 下
//     offset[1].col = 0;
//     offset[2].row = 0; // 左
//     offset[2].col = -1;
//     offset[3].row = -1; // 上
//     offset[3].col = 0;
//     for (int i = 0; i < Row + 2; i++)
//     {
//         for (int j = 0; j < Colum + 2; j++)
//         {
//             if ((i == 0) || (i == Colum + 1) || (j == 0) || (j == Row + 1))
//             {
//                 Graph[i][j] = 0;
//             }
//         }
//     }
//     int ofClass = 2;
//     position here;
//     arrayQueue<position> q;
//     for (int i = 1; i <= Row; i++)
//     {
//         for (int j = 1; j <= Colum; j++)
//         {
//             if (Graph[i][j] == 1)
//             {
//                 Graph[i][j] = ofClass;
//                 here.row = i;
//                 here.col = j;
//                 // cout << "here:"
//                     //  << "(" << here.row << "," << here.col << ") " << endl;
//                 position nbr;
//                 do
//                 {
//                     for (int bias = 0; bias < 4; bias++)
//                     {
//                         nbr.col = here.col + offset[bias].col;
//                         nbr.row = here.row + offset[bias].row;
//                         if (Graph[nbr.row][nbr.col] == 1)
//                         {
//                             // cout << "here:"
//                             //      << "(" << here.row << "," << here.col << ") " << endl;
//                             // cout << "nbr:"
//                             //      << "(" << nbr.row << "," << nbr.col << ") " << endl;
//                             // cout << "Grid: " << Grid[nbr.row][nbr.col] << endl;
//                             Graph[nbr.row][nbr.col] = ofClass;
//                             q.push(nbr);
//                         }
//                     }
//                     if (q.empty())
//                         break;
//                     here = q.front();
//                     q.pop();
//                 } while (true);
//                 ofClass++;
//             }
//         }
//     }
// }
// void test03()
// {
//     genGraph();
//     print(Graph, 1, Row, 1, Colum);
//     labelComponents();
//     printf("--------------------\n");
//     print(Graph, 0, Row + 1, 0, Colum + 1);
// }
// int main()
// {
//     // test01();
//     // test02();
//     try
//     {
//         test03();
//     }
//     catch (...)
//     {
//     }

//     // for(int i =0;i<=128;i++)
//     //     cout<<static_cast<char>(i)<<endl;

//     system("pause");
//     return 0;
// }