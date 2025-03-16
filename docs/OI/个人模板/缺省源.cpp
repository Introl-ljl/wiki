#pragma GCC optimize(1, 2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ONLINE_JUDGE
// #define MULTI_CASES
const int MaxN = 2e5 + 100;
const int INF = 1e9;
int T = 1, N, M;
int a[MaxN];
inline void Solve()
{
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef MULTI_CASES
    cin >> T;
    while (T--)
#endif
        Solve();
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

