
// #include <bits/stdc++.h>
// #define up(l, r, i) for (int i = l; i <= r; i++)
// #define dn(l, r, i) for (int i = l; i >= r; i--)
// using namespace std;

// typedef long long LL;
// const int INF = 2147483647;
// int qread()
// {
//     int w = 1, c, ret;
//     while ((c = getchar()) > '9' || c < '0')
//         w = (c == '-' ? -1 : 1);
//     ret = c - '0';
//     while ((c = getchar()) >= '0' && c <= '9')
//         ret = ret * 10 + c - '0';
//     return ret * w;
// }
// const int MAXN = 1e4 + 3, MAXL = 1e5 + 3;
// int n, C[MAXN], flg[MAXN];
// double W[MAXN], dp[MAXN];
// vector<int> ans;
// struct Node
// {
//     int dt[MAXL], len;
//     Node() : len(0) { memset(dt, 0, sizeof(dt)); }
//     Node operator*(int t)
//     {
//         Node res;
//         up(1, len, i) res.dt[i] = dt[i] * t;
//         up(1, len + 10, i)
//         {
//             res.dt[i + 1] += res.dt[i] / 10, res.dt[i] %= 10;
//             if (res.dt[i])
//                 res.len = i;
//         }
//         return res;
//     }
// } val;
// int main()
// {
//     n = qread();
//     up(1, n, i) W[i] = log(i);
//     up(1, n, i) dp[i] = -INF;
//     up(1, n, i) dn(n, i, j)
//     {
//         if (dp[j - i] + W[i] > dp[j])
//             dp[j] = dp[j - i] + W[i], flg[j] = j - i;
//     }
//     for (int p = n; p; p = flg[p])
//         ans.push_back(p - flg[p]);
//     dn(ans.size(), 1, i) printf("%d ", ans[i - 1]);
//     puts("");
//     val.len = 1, val.dt[1] = 1;
//     up(1, ans.size(), i) val = val * ans[i - 1];
//     dn(val.len, 1, i) putchar('0' + val.dt[i]);
//     puts("");
//     system("pause");
//     return 0;
// }