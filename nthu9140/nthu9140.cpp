#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 105
#define M 4955

using namespace std;

typedef struct Edge
{
    int u, v;
    long long w;

    friend bool operator <(const Edge a, const Edge b)
    {
        return a.w < b.w;
    }
}Edge;

Edge e[M];

int parent[N];

int find(int i)
{
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void unions(int i, int j)
{
    parent[find(j)] = parent[find(i)];
}

int main(void)
{
    int n, m, nCase = 0;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
        }

        sort(e + 1, e + m + 1);
        double product = 0;

        for(int i = 1; i <= m; i++)
        {
            if(find(e[i].u) != find(e[i].v))
            {
                 unions(e[i].u, e[i].v);
                 product += log(e[i].w);
            }
        }

        printf("Case %d: %.2lf\n",++nCase, product);
    }

    return 0;
}
