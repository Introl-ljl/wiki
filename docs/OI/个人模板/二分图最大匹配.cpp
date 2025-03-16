#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MaxN = 1e6 + 100;
const int INF = 1e9;
int T=1, N, M;
struct edge 
{ 
    int next;
    int to;
    int wei;
}edge[100005];
int head[10005];//head[i]为i点的第一条边
int cnt=0;
void addedge(int u,int v,int w) //起点，终点，权值 
{
    edge[++cnt].next=head[u];//更新cnt
    edge[cnt].to=v;
    edge[cnt].wei=w;
    head[u]=cnt;
}
template<class T>
inline void qread(T &sum)
{
    sum=0;int boo=1;
    char x=getchar();
    while(x<'0'||x>'9'){if(x=='-')boo=-1;x=getchar();}
    while(x>='0'&&x<='9'){sum=(sum<<1)+(sum<<3)+x-'0';x=getchar();}
    sum*=boo;
}
template<class T>
void qput(T x)
{
    if(x<0){
        x=-x;
        putchar('-');}
    if(x>9)
        qput(x/10);
   putchar(x%10+48);
}
bool vis[100005];
int match[100005], sum = 0;
int dfs(int x){
   for (int i = head[x]; i;i=edge[i].next){
        if(vis[edge[i].to]){
            continue;
        }
        vis[edge[i].to] = 1;
        if(!match[edge[i].to]||dfs(match[edge[i].to])){
            match[edge[i].to] = x;
            return 1;
        }
   }
   return 0;
}
inline void Solve()
{
    int n, m, e;
    qread(n), qread(m), qread(e);
    for (int i = 1, a, b; i <= e;i++){
        qread(a), qread(b);
        //cout << 1;
        addedge(a, b, 1);
        //addedge(b, a, 1);
    }
    
    for (int i = 1; i <= n;i++){
        memset(vis, 0, sizeof vis);
        sum += dfs(i);
    }
    qput(sum);
}
signed main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cin >> T;
    while (T--)
       Solve();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
