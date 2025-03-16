#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MaxN = 2e5 + 100;
const int INF = 1e9;
int T=1, N, M;
struct f{
    int u, v, w;
} a[MaxN];
bool cmp(f a,f b){
    return a.w < b.w;
}
int fa[MaxN];
int find(int a){
    if(fa[a]==a){
        return a;
    }
    return fa[a] = find(fa[a]);
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
    qread(N), qread(M);
    for (int i = 1; i <= M;i++){
        int x, y, z;
        qread(x), qread(y), qread(z);
        a[i].u = x;
        a[i].v = y;
        a[i].w = z;
    }
    for (int i = 1; i <= N;i++){
        fa[i] = i;
    }
    sort(a+1, a + M+1, cmp);
    int cnt = 1;
    int sum = 0;
    int num = 0;
    for(int i = 1; i <= M; i ++)
	{
		int x = find(a[i].u);
		int y = find(a[i].v);
		if(x == y) continue;
		fa[x] = y;
		sum += a[i].w;
		if(++ num == N - 1){
            
            break; 
        }
    }
    if(num!=N-1){
        puts("orz");
        return;
    }
    cout << sum << endl;
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
