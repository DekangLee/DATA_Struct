// #include <iostream>
// #include "arrayList.hpp"
// #include "arrayStack.hpp"
// #include "chainList.hpp"
// #include "doubleLinkList.hpp"
// #include <string>
// using namespace std;
// template <class T>
// class equivalence
// {
// public:
//     equivalence(){};
//     equivalence(T first, T second)
//     {
//         this->first = first;
//         this->second = second;
//     }
//     bool match(T element1, T element2)
//     {
//         if (element1 == this->first && element2 == this->second)
//             return true;
//         else
//             return false;
//     }
//     T first;
//     T second;
// };
// template <class T>
// ostream &operator<<(ostream &cout, const equivalence<T> &E)
// {
//     cout << E.first << " " << E.second;
//     return cout;
// }
// void test01()
// {
//     arrayList<equivalence<char>> V;
//     V.push_back(equivalence<char>('(', ')'));
//     V.push_back(equivalence<char>('[', ']'));
//     V.push_back(equivalence<char>('{', '}'));
//     // for(auto ele : V)
//     // {
//     //     cout<<ele<<endl;
//     // }
//     string str;
//     cout << "Enter a stirng: ";
//     cin >> str;
//     arrayStack<char> charStack;
//     for (auto c : str)
//     {
//         for (auto ele : V)
//         {
//             bool flag = false;
//             if (!charStack.empty())
//             {
//                 flag = ele.match(charStack.top(), c);
//                 if (flag)
//                 {
//                     charStack.pop();
//                 }
//             }
//             if (!flag)
//             {
//                 if (c == ele.first || c == ele.second)
//                 {
//                     charStack.push(c);
//                 }
//             }
//         }
//     }
//     if (charStack.empty())
//     {
//         cout << "Valid string!" << endl;
//     }
//     else
//     {
//         cout << "This string is invalid" << endl;
//     }
// }
// class position
// {
// public:
//     int row;
//     int col;
// };
// arrayStack<position> *path;
// int size;
// int **maze = new int *[size + 1];
// bool findPath()
// {
//     path = new arrayStack<position>;
//     for (int i = 0; i < size + 1; i++)
//     {
//         maze[i] = new int[size + 1];
//     }
//     position offset[4];
//     offset[0].row = 0;
//     offset[0].col = 1; // 右移
//     offset[1].row = 1;
//     offset[1].col = 0; // 下移
//     offset[2].row = 0;
//     offset[2].col = -1; // 左移
//     offset[3].row = -1;
//     offset[3].col = 1; // 上移
//     // 初始化外围的墙
//     for (int i = 0; i <= size + 1; i++)
//     {
//         maze[0][i] = maze[size + 1][i] = 1;
//         maze[i][0] = maze[i][size + 1] = 1;
//     }
//     position here;
//     here.row = 1;
//     here.col = 1;
//     maze[1][1] = 1;
//     int option = 0;
//     int lastOption = 3;
//     // 寻找路径
//     while (here.row != size || here.col != size)
//     {
//         int r, c;
//         while (option <= lastOption)
//         {
//             r = here.row + offset[option].row;
//             c = here.col + offset[option].col;
//             if(maze[r][c] == 0) break;
//             option++;
//         }
//         if (option <= lastOption)
//         {
//             path->push(here);
//             here.col = c;
//             here.row = r;
//             maze[c][r] = 1;
//             option = 0;
//         }
//         else
//         {
//             if (path->empty())
//                 return false;
//             position next = path->top();
//             path->pop();
//             if (next.row == here.row)
//             {
//                 option = 2 + next.col - here.col;// 细节操作，还原在netx点位的操作，并且option 为反向操作
//             }
//             else
//                 option = 3 + next.row - here.row; // 与上相同，这里需要注意的是0,1,2,3为右，下，左，上。这个顺序是有逻辑性的
//             here = next;
//         }
//     }
//     return true;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }