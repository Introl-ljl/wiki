#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MaxN = 1e6 + 100;
const int INF = 1e9;
int T=1, N, M;
int fail[10000];
void judge(string a){
    int match = 0, l=a.length();
    for (int i = 1; i <l;i++){
        while(match&&a[match]!=a[i]){
            match = fail[match];
        }
        if(a[match]==a[i]){
            match++;fail[i+1] = match;
        }
        
    }
}
void KMP(string b,string P){
    int match = 0, la = P.length(), lb = b.length();
    for (int i = 0; i < lb;i++){
        while(match>0&&P[match]!=b[i]){
            match = fail[match];
        }
        if(P[match]==b[i]){
            match++;
        }
        if (match == la){
            cout << i - la + 2 << endl;
            match = fail[match];
        }
    }
    for (int i = 1; i <= la;i++){
        cout << fail[i] << " ";
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
    string a, b;
    cin>>a>>b;
    judge(b);
    KMP(a, b);
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
