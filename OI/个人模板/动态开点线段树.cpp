#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    long long tag;
    long long sum;
    Node *lson;
    Node *rson;
    Node()
    {
        tag = sum = 0;
        lson = rson = nullptr;
    }
};

inline void pushdown(Node *root, int l, int r)
{
    int m = (l + r) >> 1;

    if (root->lson == nullptr)
        root->lson = new Node;
    root->lson->tag += root->tag;
    root->lson->sum += root->tag * (m - l + 1);

    if (root->rson == nullptr)
        root->rson = new Node;
    root->rson->tag += root->tag;
    root->rson->sum += root->tag * (r - m);

    root->tag = 0;
}

inline void pushup(Node *root, int l, int r)
{
    root->sum = 0;
    if (root->lson != nullptr)
    {
        root->sum += root->lson->sum;
    }
    if (root->rson != nullptr)
    {
        root->sum += root->rson->sum;
    }
}

void modify(Node *root, int stdl, int stdr, int l, int r, int v)
{
    if (l <= stdl && stdr <= r)
    {
        root->sum += v * (stdr - stdl + 1);
        root->tag += v;
        return;
    }
    pushdown(root, stdl, stdr);
    int mid = (stdl + stdr) >> 1;
    if (l <= mid)
    {
        modify(root->lson, stdl, mid, l, r, v);
    }
    if (r > mid)
    {
        modify(root->rson, mid + 1, stdr, l, r, v);
    }
    pushup(root, stdl, stdr);
}

int query(Node *root, int stdl, int stdr, int l, int r)
{
    if (l <= stdl && stdr <= r)
        return root->sum;
    pushdown(root, stdl, stdr);
    int res = 0;
    int mid = (stdl + stdr) >> 1;
    if (l <= mid)
    {
        res = query(root->lson, stdl, mid, l, r);
    }
    if (r > mid)
    {
        res += query(root->rson, mid + 1, stdr, l, r);
    }
    pushup(root, stdl, stdr);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    Node *root = new Node;

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        modify(root, 1, n, i, i, x);
    }

    while (m--)
    {
        int tp, x, y, k;
        cin >> tp >> x >> y;
        if (tp == 1)
        {
            cin >> k;
            modify(root, 1, n, x, y, k);
        }
        else
        {
            cout << query(root, 1, n, x, y) << endl;
        }
    }

    return 0;
}