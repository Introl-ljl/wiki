#pragma GCC optimize(1, 2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ONLINE_JUDGE
 #define MULTI_CASES
#define endl '\n'
const int MaxN = 2e5+100;
const int INF = 1e9;
const int mod=212370440130137957ll;
int T=1, N, M;
int a[MaxN];
struct DSU{
    vector<int> fn;
    DSU(int n){
        for(int i=0;i<=n;i++){
            fn.push_back(i);
        }
    }
    int find(int x){
        if(fn[x]==x){
            return x;
        }
        return fn[x]=find(fn[x]);
    }
    void join(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            fn[fx]=fy;
        }
    }
};
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
    cin.tie(0),cout.tie(0);

#ifdef MULTI_CASES
    cin >> T;
    while (T--)
#endif
       Solve();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
