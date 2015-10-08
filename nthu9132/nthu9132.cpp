#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>

#define N 100005
#define K 1000005

using namespace std;

typedef struct Edge {
    int u, v;
}Edge;

Edge e[K];
int parent[N];
long long childcount[N];

int find(int x)
{
    return (parent[x] == x) ? x : (find(parent[x]));
}

long long unions(int x, int y)
{
    if(childcount[x] > childcount[y])
    {
        childcount[x] += childcount[y];
        parent[y] = x;
        return childcount[x];
    }
    else
    {
        childcount[y] += childcount[x];
        parent[x] = y;
        return childcount[y];
    }
}

int main(void)
{
    int n, k;
    while(scanf("%d",&n), n)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            childcount[i] = 1;
        }

        scanf("%d",&k);

        for(int i = 0; i < k; i++)
        {
            scanf("%d%d",&e[i].u ,&e[i].v);
        }

        long long maxNum = 1;
        for(int i = 0; i < k; i++)
        {
            int pu = find(e[i].u);
            int pv = find(e[i].v);
            if(pu != pv)
            {
                 long long num = unions(pu, pv);
                 maxNum = max(maxNum, num);
            }
        }
        printf("%lld\n",maxNum);

    }

    return 0;
}
