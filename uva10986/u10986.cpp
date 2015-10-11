#include <iostream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

const int MAXN = 20002; // Vertex
const int MAXM = 50002; // Edge
const int INF = 0x7fffffff;

typedef struct Node{
    int id, w;
}Node;

bool operator <(const Node a, const Node b){
    return a.w > b.w;
}

list<Node> g[MAXN];
int d[MAXN];

void dbg(int n){
    for(int i = 0; i < n; i++){
        printf("%d ",d[i]);
    }
    cout << endl;
}

void reset(int n){
    for(int i = 0; i < n; i++)
        d[i] = INF, g[i].clear();
}

void load(int n, int m){
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(Node{v, w});
        g[v].push_back(Node{u, w});
    }
}

void dij(int n, int s, int t){
    bool visited[MAXN];
    memset(visited, 0, sizeof(visited));
    
    priority_queue<Node> pq;
    pq.push(Node{s, 0});
    
    d[s] = 0;
    
    while(!pq.empty()){
        Node node = pq.top();
        pq.pop();
        
        if(visited[node.id])
            continue;
        
        visited[node.id] = true;
        
        // Relax
        for(list<Node>::iterator it = g[node.id].begin(); it != g[node.id].end(); it++){
            Node& e = *it;
            if(!visited[e.id]){
                d[e.id] = min(d[e.id], d[node.id] + e.w);
                pq.push(Node{e.id, d[e.id]});
            }
        }
    }
}

int main(){
    
    int nCase;
    cin >> nCase;
    
    for(int i = 0; i < nCase; i++){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        reset(n);
        load(n, m);
        dij(n, s, t);
        
        printf("Case #%d: ",i + 1);
        if(d[t] == INF)
            printf("unreachable\n");
        else
            printf("%d\n",d[t]);
    }
    
    return 0;
}