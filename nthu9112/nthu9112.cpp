#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 500005
#define M 500005

using namespace std;

typedef struct Edge {
    int u, v;
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
    int n, m;
    while(scanf("%d%d",&n ,&m) == 2, n, m)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&e[i].u ,&e[i].v);
        }

        bool cycle = false;
        for(int i = 0; i < m; i++)
        {
            if(find(e[i].u) != find(e[i].v))
            {
                unions(e[i].u, e[i].v);
            }
            else
            {
                cycle = true;
                break;
            }
        }

        printf("%s\n", (cycle) ? "No" : "Yes");
    }

    return 0;
}
