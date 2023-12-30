// #include <iostream>
// #include <string>
// #include<sstream>
// using namespace std;
// class illegalParameterValue
// {
// public:
//     illegalParameterValue(string theMessage = "Illegal parameter value")
//     {
//         message = theMessage;
//     }
//     void outputMessage() const { cout << message << endl; }

// private:
//     string message;
// };
// // #include<vector>
// // #include<algorithm>
// // struct decompose
// // {
// //     int data;

// //     decompose *p;

// // };
// // int main()
// // {
// //     int a;
// //     vector<long> v1;
// //     decompose p0;
// //     cin >> a;
// //     while (a != 3 && a != 4 && a != 2)
// //     {
// //         if (a % 2 != 0)
// //         {
// //             int b = a / 2;
// //             a = b + 1;
// //             v1.emplace_back(b);
// //         }
// //         else
// //         {
// //             int b = a / 2;
// //             a = b;
// //             v1.emplace_back(b);
// //         }
// //     }
// //     v1.emplace_back(a);
// //     sort(v1.begin(), v1.end());  //原位操作
// //     long mu = 1;
// //     for(int i:v1)
// //     {
// //          cout << i << " ";
// //          mu *= i;
// //     }

// //     cout<<endl;
// //     cout<<mu<<endl;

// //     system("pause");
// //     return 0;
// // }
// void test01()
// {
//     int a = 10;
//     if (a > 9)
//     {
//         ostringstream  tip;
//         tip<<"error a > 9!";
//         throw illegalParameterValue(tip.str());
//     }
// }
// void test02()
// {
//     cout << "正在运行" << endl;
// }
// int main()
// {
//     try
//     {
//         test01();
//     }
//     catch (const illegalParameterValue &e)
//     {
//         e.outputMessage();
//     }
//     test02();
//     system("pause");
//     return 0;
// }