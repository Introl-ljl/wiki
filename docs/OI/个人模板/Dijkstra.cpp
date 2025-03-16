struct Dijkstra
{
    int d[MaxN], vis[MaxN];
    struct Point
    {
        int id, x;
        inline bool operator<(const Point &aa) const
        {
            return x > aa.x;
        }
    };
    priority_queue<Point> q;
    inline void solve(int S)
    {
        for (int i = 1; i <= N; i++)
            d[i] = INF, vis[i] = 0;

        d[S] = 0;
        q.push((Point){S, 0});
        while (!q.empty())
        {
            auto [x, w] = q.top();
            q.pop();
            if (vis[x])
                continue;
            vis[x] = 1;
            for (auto it : G1[x])
            {
                int y = it.first;
                int z = it.second;
                if (d[x] + z < d[y])
                {
                    d[y] = d[x] + z;
                    if (!vis[y])
                        q.push((Point){y, d[y]});
                }
            }
        }
    }
} dij;