#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAXID 1024
#define MAXN 1024

using namespace std;

struct Compare
{
    bool operator ()(const int& a, const int& b)
    {
        return a > b;
    }
};

typedef struct Node
{
    int id;
    priority_queue<int, vector<int>, Compare> pq;

}Node;

bool isRoot;
void preorder_traverse(Node *pool, int root)
{
    if(isRoot) isRoot = false;
    else printf(" ");

    printf("%d",root);
    while(!pool[root].pq.empty())
    {
        preorder_traverse(pool, pool[root].pq.top());
        pool[root].pq.pop();
    }
}

int main(void)
{
    int n;
    while(scanf("%d",&n) == 1, n)
    {
        Node pool[MAXID];

        while(n--)
        {
            int p, c;
            scanf("%d%d",&p,&c);
            pool[p].pq.push(c);
        }

        int r;
        scanf("%d",&r);

        isRoot = true;
        preorder_traverse(pool, r);

        printf("\n");
    }

    return 0;
}
