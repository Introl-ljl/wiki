#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int INF=1e9;
struct Segment{
    vector<int>a;
    struct Point{
        int l,r;
        int add,mul;
        int mex,sum;
    };
    vector<Point>t;
    Segment(int N){
        a.assign(N+1,0);
        t.assign(N<<2,{});
    }
    #define ls p<<1
    #define rs p<<1|1
    int midd(int p){
        return (t[p].l+t[p].r)>>1;
    }
    void push_up(int p){
        t[p].sum=(t[ls].sum+t[rs].sum)%mod;
        t[p].mex=max(t[ls].mex,t[rs].mex);
    }
    void build(int p,int l,int r){
        t[p].l=l,t[p].r=r;
        if(l==r){
            t[p].sum=t[p].mex=a[l];
            return;
        }
        int mid=midd(p);
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(p);
    }
    void push_down(int p){
        t[ls].sum=(t[ls].sum*t[p].mul+t[p].add*(t[ls].r-t[ls].l+1))%mod;
        t[rs].sum=(t[rs].sum*t[p].mex+t[p].add*(t[rs].r-t[rs].l+1))%mod;

        t[ls].mex=(t[ls].mex*t[p].mul+t[p].add)%mod;
        t[rs].mex=(t[rs].mex*t[p].mul+t[p].add)%mod;

        t[ls].mul=(t[ls].mul*t[p].mul)%mod;
        t[rs].mul=(t[rs].mul*t[p].mul)%mod;

        t[ls].add=(t[ls].add*t[p].mul+t[p].add)%mod;
        t[rs].add=(t[rs].add*t[p].mul+t[p].add)%mod;
    }
    void dfs(int p,int l,int r){
        if(l==r){
            a[l]=t[p].sum;
        }
        int mid=midd(p);
        push_down(p);
        dfs(ls,l,mid);
        dfs(rs,mid+1,r);
        push_up(p);
    }
    void changeAdd(int p,int nl,int nr,int k){
        int l=t[p].l,r=t[p].r;
        if(nl<=l&&r<=nr){
            t[p].sum+=(t[p].r-t[p].l+1)*k;
            t[p].mex+=k;
            t[p].add+=k;
            return ;
        }
        int mid=midd(p);
        push_down(p);
        if(nl<=mid){
            changeAdd(ls,nl,nr,k);
        }
        if(mid<nr){
            changeAdd(rs,nl,nr,k);
        }
        push_up(p);
    }
    void changeMul(int p,int nl,int nr,int k){
        int l=t[p].l,r=t[p].r;
        if(nl<=l&&r<=nr){
            t[p].sum=t[p].sum*k;
            t[p].mex=t[p].mex*k;
            t[p].mul=t[p].mul*k;
            t[p].add=t[p].add*k;
            return ;
        }
        int mid=midd(p);
        push_down(p);
        if(nl<=mid){
            changeMul(ls,nl,nr,k);
        }
        if(mid<nr){
            changeMul(rs,nl,nr,k);
        }
        push_up(p);
    }
    int query_sum(int p,int nl,int nr){
        int l=t[p].l,r=t[p].r;
        if(nl<=l&&r<=nr){
            return t[p].sum;
        }
        int mid=midd(p);
        push_down(p);
        int sum=0;
        if(nl<=mid){
            sum+=query_sum(ls,nl,nr);
        }
        if(mid<nr){
            sum+=query_sum(ls,nl,nr);
        }
    }
    int query_max(int p,int nl,int nr){
        int l=t[p].l,r=t[p].r;
        if(nl<=l&&r<=nr){
            return t[p].mex;
        }
        int mid=midd(p);
        push_down(p);
        int maxn=-INF;
        if(nl<=mid){
            maxn=max(maxn,query_max(ls,nl,nr));
        }
        if(mid<nr){
            maxn=max(maxn,query_max(rs,nl,nr));
        }
    }
};