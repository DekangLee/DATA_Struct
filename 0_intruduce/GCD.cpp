// #include <iostream>
// using namespace std;
// unsigned int Gcd(unsigned int M, unsigned int N) // 欧几里得辗转相除 迭代版
// {
//     unsigned int Rem;
//     while (N > 0)
//     {
//         Rem = M % N;
//         M = N;
//         N = Rem;
//     }
//     return M;
// }
// unsigned int Gcd_R(unsigned int M, unsigned int N) // 递归版
// {
//     if (N % M == 0)
//     {
//         return M;
//     }
//     return Gcd_R(N, M % N);
// }
// long int Pow(long int x, unsigned int N)  // 时间复杂度为lo
// {
//     if (N == 0)
//         return 1;
//     if (N == 1)
//         return x;
//     if (N % 2 == 0)
//         return Pow(x * x, N / 2);
//     else
//         return x * Pow(x * x, N / 2);
    
// }
// void test01()
// {
//     unsigned int M;
//     unsigned int N;
//     cout << "M = ";
//     cin >> M;
//     cout << "\b";
//     cout << "N = ";
//     cin >> N;
//     cout << "最大公约数:" << Gcd_R(M, N) << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }