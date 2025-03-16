inline void pre()
{
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            vis[i] = i;
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (prime[j] > N / i || prime[j] > vis[i])
                break;
            vis[prime[j] * i] = prime[j];
        }
    }
}