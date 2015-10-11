#include <iostream>
#include <cstdio>
#include <queue>
#include <list>
#define MAXV 102

using namespace std;

typedef struct Edge{
    int start, end, len;
}Edge;

list<Edge> g[MAXV];

void bfs(int x, int y, int k){
    queue<int> q;
    q.push(x);
    
    int nK = 0;
    while(!q.empty() && nk < k){
        
        int source = q.top(); q.pop();
        
        if(source == k) 
            nK++;
        
        for(list<Edge>::iterator it = g[source].begin(); it != g[source].end(); it++){
            q.push(it->end);
        }
    }
}

int main(){
    
    int nV, nE;
    int x, y, k;
    while(scanf("%d%d",&nV ,&nE) == 2, nV != 0, nE != 0){
        scanf("%d%d%d",&x, &y, &k);
        
        for(int i = 0; i < nE; i++){
            int start, end, len;
            scanf("%d%d%d",&start, &end, &len);
            g[start].push_back(Edge{start, end, len});
        }
    }
    
    
    return 0;
}