// #pragma GCC optimize(1, 2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ONLINE_JUDGE
// #define MULTI_CASES
#define endl '\n'
const int MaxN = 2e5+100;
const int INF = 1e9;
const int mod=212370440130137957ll;
int T=1, N, M;
int a[MaxN];
vector<int> G1[MaxN];
struct LCA{
    int fa[MaxN][21],dep[MaxN];
    void dfs(int x,int f){
        fa[x][0]=f;
        dep[x]=dep[f]+1;
        for(int i=1;i<=20;i++){
            fa[x][i]=fa[fa[x][i-1]][i-1];
        }
        for(auto y:G1[x]){
            if(y==f){
                continue;
            }
            dfs(y,x);
        }
    }
    int find(int x,int y){
        if(dep[x]<dep[y]){
            swap(x,y);
        }
        for(int i=20;i>=0;i--){
            if(dep[fa[x][i]]>=dep[y]){
                x=fa[x][i];
            }
            if(x==y){
                return x;
            }
        }
        for(int i=20;i>=0;i--){
            if(fa[x][i]!=fa[y][i]){
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        return fa[x][0];
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
