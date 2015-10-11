#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>
#include <cstring>

#define MAX 100005
#define MAXQ 105

using namespace std;

int n, m;
bool visit[MAX];
int q[MAXQ][3];
int p[MAX];

void show()
{
    for(int i = 1; i <= n; i++)
        printf("%d ",p[i]);
    printf("\n");
}

int Find(int x)
{
    return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    p[y] = x;
}

void dfs(list<int> *g, int i)
{
    //printf("dfs(%d)\n",i);
    if(visit[i]) return;
    else visit[i] = true;
    
    for(int j = 0; j < m; j++)
    {
        if(q[j][2] < 0 && (q[j][0] == i || q[j][1] == i) && visit[q[j][0]] && visit[q[j][1]])
        {
            int id = (q[j][1] == i) ? q[j][0] : q[j][1];
            q[j][2] = Find(id);
            //printf("find(%d): (%d, %d) => %d\n",id,q[j][0],q[j][1],q[j][2]);
        }
    }
                
    for(list<int>::iterator it = g[i].begin(); it != g[i].end(); it++)
    {
        if(!visit[*it])
        {
            dfs(g, *it);
            Union(i, *it);
        }
    }
}

int main(void)
{
    int nCase;
    int v, r, a, b;
    
    scanf("%d",&nCase);
    
    for(int c = 0; c < nCase; c++)
    {
        list<int> g[MAX];
        scanf("%d",&n);
        memset(visit, 0, sizeof(visit));
        
        for(int i = 1; i <= n; i++)
        {
            p[i] = i;
            scanf("%d",&v);
            if(v < 0) r = i;
            else g[v].push_back(i);
        }
        
        m = 0;  
        while(scanf("%d%d",&a,&b), a, b)
        {
            q[m][0] = a;
            q[m][1] = b;
            q[m][2] = -1;
            m++;
            //printf("%d %d\n",a,b);
        }
        dfs(g, r);
        printf("Case %d:",c + 1);
        for(int qi = 0; qi < m; qi++)
        {
            printf(" %d",q[qi][2]);
        }
        printf("\n");
    }
    
    return 0;
}