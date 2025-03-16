#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MaxN = 5e5 + 100;
const int INF = INT_MAX;
int T=1, N, M,sum=0;
int dis[MaxN], vis[MaxN];
int n, m, s;
struct edge 
{ 
    int next;
    int to;
    int wei;
}edge[MaxN];
struct priority
{
    int ans;
    int id;
    bool operator <(const priority &x)const//从大到小
    {
        return x.ans<ans;
    }
};
priority_queue<priority> q;
int head[MaxN];//head[i]为i点的第一条边
int cnt=0;
void add_edge(int u,int v,int w) //起点，终点，权值 
{
    edge[++cnt].next=head[u];//更新cnt
    edge[cnt].to=v;
    edge[cnt].wei=w;
    head[u]=cnt;
}
void Prime(int s){
    int pos;
    dis[s] = 0;
    int ans = 0;
    q.push(priority{0, s});
    while (!q.empty()&&ans<n){//如果队列已空，则结束
        priority temp = q.top();//取队头
        q.pop();
        pos = temp.id;//当前点位置
        if(vis[pos]!=1){//如果没有访问过
            vis[pos] = 1;//标记
            ans++;
            sum += dis[pos];
            for (int i = head[pos]; i != 0;i=edge[i].next){
                if(edge[i].wei<dis[edge[i].to])
                    dis[edge[i].next]=edge[i].wei,q.push(priority{dis[edge[i].to],edge[i].to});
            }
        }
    }
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

inline void Solve()
{
    
    qread(n), qread(m);
    for (int i = 1; i <= n; i++){
        dis[i] = INF;//将所有的点都初始化为无穷大
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        qread(u), qread(v), qread(w);
        add_edge(u, v, w);//存图
        add_edge(v, u, w);
    }
    Prime(1);
    cout << sum;
}
signed main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cin >> T;
    while (T--)
       Solve();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
