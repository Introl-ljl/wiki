struct segment
{
    struct Tree
    {
        int l, r;
        int tag, sum, mex;
    } t[MaxN << 2];
#define ls p << 1
#define rs p << 1 | 1
    int midd(int p)
    {
        return (t[p].l + t[p].r) >> 1;
    }
    void push_up(int p)
    {
        t[p].sum = t[ls].sum + t[rs].sum;
        t[p].mex = max(t[ls].mex, t[rs].mex);
    }
    void pls(int p, int k)
    {
        t[p].tag += k;
        t[p].sum += (t[p].r - t[p].l + 1) * k;
        t[p].mex += k;
    }
    void push_down(int p)
    {
        if (t[p].tag)
        {
            pls(ls, t[p].tag);
            pls(rs, t[p].tag);
            t[p].tag = 0;
        }
    }
    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r;
        if (l == r)
        {
            t[p].sum = a[l];
            t[p].mex = a[l];
            return;
        }
        build(ls, l, midd(p));
        build(rs, midd(p) + 1, r);
        push_up(p);
    }
    void dfs(int p, int l, int r)
    {
        if (l == r)
        {
            a[l] = t[p].mex;
        }
        int mid = midd(p);
        push_down(p);
        dfs(ls, l, mid);
        dfs(rs, mid + 1, r);
        push_up(p);
    }
    void change(int p, int nl, int nr, int k)
    {
        int l = t[p].l, r = t[p].r;
        if (nl <= l && r <= nr)
        {
            pls(p, k);
            return;
        }
        int mid = midd(p);
        push_down(p);
        if (nl <= mid)
        {
            change(ls, nl, nr, k);
        }
        if (mid < nr)
        {
            change(rs, nl, nr, k);
        }
        push_up(p);
    }
    int query_sum(int p, int nl, int nr)
    {
        int l = t[p].l, r = t[p].r;
        if (nl <= l && r <= nr)
        {
            return t[p].sum;
        }
        int mid = midd(p), ans = 0;
        push_down(p);
        if (nl <= mid)
        {
            ans += query_sum(ls, nl, nr);
        }
        if (mid < nr)
        {
            ans += query_sum(rs, nl, nr);
        }
        return ans;
    }
    int query_max(int p, int nl, int nr)
    {
        int l = t[p].l, r = t[p].r;
        if (nl <= l && r <= nr)
        {
            return t[p].mex;
        }
        int mid = midd(p), maxn = -INF;
        push_down(p);
        if (nl <= mid)
        {
            maxn = max(maxn, query_max(ls, nl, nr));
        }
        if (mid < nr)
        {
            maxn = max(maxn, query_max(rs, nl, nr));
        }
        return maxn;
    }
};