#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 1002
#define INF 0x7fffffff

using namespace std;

typedef long long Int;
typedef struct Node{
    int row, col, cost;
    Node(int _row, int _col, int _cost){
        row = _row;
        col = _col;
        cost = _cost;
    }
    
}Node;

int maze[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};
Int dist[MAX][MAX];

bool operator <(const Node a, const Node b){
    return a.cost > b.cost;
}

void load(int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d",&maze[i][j]), dist[i][j] = INF, visited[i][j] = false;
}

const int instr[4][2] = {
    {-1,0}, // Up
    {1,0}, // Bottom
    {0,-1}, // Left
    {0,1} // Right
};

void solve(int n, int m){
    priority_queue<Node> pq;
    
    dist[0][0] = maze[0][0];
    
    pq.push(Node(0, 0, dist[0][0]));
    
    while(!pq.empty()){
        
        Node node = pq.top(); pq.pop();
        
        if(visited[node.row][node.col])
            continue;
        
        visited[node.row][node.col] = true;

        for(int i = 0; i < 4; i++){
            int row = node.row + instr[i][0];
            int col = node.col + instr[i][1];
            
            if(row < 0 || row >= n || col < 0 || col >= m)
                continue;
            
            if(!visited[row][col] && dist[node.row][node.col] + maze[row][col] < dist[row][col]){
                dist[row][col] = dist[node.row][node.col] + maze[row][col];
                pq.push(Node(row, col, dist[row][col]));
            }
        }
    }
    
}

int main(){
    int nCase;
    scanf("%d",&nCase);
    
    while(nCase--){
        int n, m;
        scanf("%d%d",&n,&m);

        load(n, m);
        solve(n, m);
        printf("%lld\n",dist[n - 1][m - 1]);
    }
    
    return 0;
}