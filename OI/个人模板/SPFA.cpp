#include<bits/stdc++.h>
using namespace std;
const int MaxN = 1e6;
const int INF = 1e9;
struct SPFA{
    struct edge{
        int v, w;
    };
    vector<edge> G1[MaxN];
    int cnt[MaxN], vis[MaxN], dis[MaxN];
    queue<int> q;
    SPFA(){
        memset(cnt, 0, sizeof cnt);
        memset(dis, INF, sizeof dis);
        memset(vis, 0, sizeof vis);
    }
    bool spfa(int n, int s){
        dis[s] = 0;
        vis[s] = 1;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for(auto ed : G1[u]){
                int v = ed.v, w = ed.w;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if(cnt[v] >= n) return 0;
                    if(!vis[v])q.push(v), vis[v] = 1;
                }
            }
        }
        return 1;
    }
};