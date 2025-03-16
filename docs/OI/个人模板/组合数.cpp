struct Math
{
    int jc[MaxN], ijc[MaxN], ip[MaxN];
    int ksm(int x, int y)
    {
        int res = 1;
        while (y)
        {
            if (y & 1)
                res = res * x % P;
            x = x * x % P;
            y >>= 1;
        }
        return res;
    }
    inline void pre(int N)
    {
        jc[0] = ijc[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            jc[i] = jc[i - 1] * i % P;
        }
        ijc[N] = ksm(jc[N], P - 2);
        for (int i = N; i >= 1; i--)
        {
            ijc[i - 1] = ijc[i] * i % P;
        }
    }
    inline void pre1(int N)
    {
        jc[0] = ijc[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            jc[i] = jc[i - 1] * i % P;
        }
        ip[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            ip[i] = (P - P / i) * ip[P % i] % P;
        }
        for (int i = 1; i <= N; i++)
        {
            ijc[i] = ijc[i - 1] * ip[i] % P;
        }
    }
    inline int C(int n, int m)
    {
        if (m > n)
            return 0;
        return jc[n] * ijc[m] % P * ijc[n - m] % P;
    }
    int lucas(int n, int m)
    {
        if (m == 0)
            return 1;
        return lucas(n / P, m / P) * C(n % P, m % P) % P;
    }
    int js(int n, int m)
    { // n个相同的小球放入m个不同的箱子中
        return C(n + m - 1, m - 1);
    }
} TT;