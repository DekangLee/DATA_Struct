// #include <iostream>
// #include <ctime>
// #include "matrix.hpp"
// #include <windows.h>
// using namespace std;
// const int Rows = 3;
// const int Columns = 4;
// template <class T>
// void genMatirx(matrix<T> &M)
// {
//     // cout<<"genMatrix----"<<endl;
//     srand(time(0));
//     for (int i = 1; i <= M.rows(); i++)
//     {
//         for (int j = 1; j <= M.columns(); j++)
//         {
//             int num = rand() % 11;
//             // cout<<num<<" ";
//             M(i, j) = num;
//         }
//         // cout<<endl;
//     }
// }
// void test01()
// {
//     matrix<int> M1(Rows, Rows);
//     matrix<int> M2(Rows, Rows);
//     genMatirx(M1);
//     // Sleep(10000);
//     genMatirx(M2);
//     cout << "M1 :" << endl;
//     cout << M1;
//     // cout<<M1.columns()<<endl;
//     cout << "M2 :" << endl;
//     cout << M2;
//     // cout<<M2.rows()<<endl;
//     cout << "M1 + M2 :" << endl;
//     try
//     {
//         cout << M1 + M2;
//     }
//     catch (illegalParameterValue &e)
//     {
//         e.outputMessage();
//     }
//     cout << "M1 - M2 :" << endl;
//     try
//     {
//         cout << M1 - M2;
//     }
//     catch (illegalParameterValue &e)
//     {
//         e.outputMessage();
//     }
//     cout << "M1 * M2 :" << endl;
//     try
//     {
//         cout << M1 * M2;
//     }
//     catch (illegalParameterValue &e)
//     {
//         e.outputMessage();
//     }
// }
// void test02()
// {
//     matrix<int> M1(Rows, Columns);
//     genMatirx(M1);
//     cout << M1;
//     M1.tranpose();
//     cout << "M1 tranposed:" << endl;
//     cout << M1;
// }
// void test03()
// {
//     diagnoalMatrix<int> diagM(Rows);
//     cout << diagM.degree() << endl;
//     for (int i = 1; i <= Rows; i++)
//     {
//         int num = rand() % 11;
//         diagM.set(i, i, num);
//     }
//     cout << diagM;
// }
// void test04()
// {
//     srand(time(0));
//     spareMatrix<int> M1;
//     arrayList<matrixTerm<int>> L1(Columns * Rows);
//     for (int i = 0; i < Rows; i++)
//     {
//         for (int j = 0; j < Columns; j++)
//         {
//             matrixTerm<int> mterm;
//             mterm.column = rand() % Columns + 1;
//             mterm.row = rand() % Rows + 1;
//             mterm.value = rand() % 11;
//             L1.push_back(mterm);
//         }
//     }
//     // cout << L1 << endl;
//     M1.input(Rows, Columns, L1);
//     cout << M1;
// }
// void test05()
// {
//     srand(time(0));
//     arrayList<int> L1;
//     for (int i = 0; i < 10; i++)
//     {
//         L1.push_back(rand() % 11);
//     }
//     cout << L1 << endl;
//     L1.set(1, -4);
//     L1.reset(10);
//     cout << L1.capacity() << endl;
// }
// int main()
// {
//     // test01();
//     // test02();
//     // test03();
//     test04();
//     // test05();
//     system("pause");
//     return 0;
// }