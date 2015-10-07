#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX 102

using namespace std;

bool G[MAX][MAX];
int visit[MAX];
int low[MAX];

int t = 0;

void dfs(int p, int i)
{
    visit[i] = low[i] = ++t;

    int child = 0;
    bool isArticulation = false;

    for(int j = 0; j < MAX; j++)
    {
        if(G[i][j] && j != p)
        {
            if(visit[j]) // Back edge
            {
                low[i] = min(low[i], visit[j]);
            }
            else // Tree edge
            {
                child++;
                dfs(i, j);

                low[i] = min(low[j], low[i]);
                if(low[j] >= visit[i])
                    isArticulation = true;
            }
        }
    }

    if((i == p && child > 1) || (i != p && isArticulation))
        printf("%d\n",i);

}

int main(void)
{
    memset(G, 0, sizeof(G));
    memset(visit, 0, sizeof(visit));
    memset(low, 0, sizeof(low));

    int u, v;
    while(cin >> u >> v)
    {
        G[u][v] = G[v][u] = true;
    }

    dfs(0, 0);
    for(int i = 0; i < MAX; i++)
        printf("%d ",low[i]);
    printf("\n");

    return 0;
}
