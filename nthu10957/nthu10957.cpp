#include <cstdio>
#include <cstring>
#include <queue>

#define MAX_R 512
#define MAX_C 512

using namespace std;

struct Node
{
    int row, col, dis;
};

int dir[4][2] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

int s_r, s_c;
int f_r, f_c;

bool visited[MAX_R][MAX_C] = { 0 };
char maze[MAX_R][MAX_C] = { 0 };
int dist[MAX_R][MAX_C] = { 0 };

void load(int R, int C)
{
    char row[C + 10];
    for (int r = 0; r < R; r++) {
        scanf("%s", row);
        for (int c = 0; c < C; c++) {

            maze[r][c] = row[c];
            visited[r][c] = false;
            dist[r][c] = 1e9;

            if (maze[r][c] == 'S') {
                s_r = r;
                s_c = c;
            }
            else if (maze[r][c] == 'F') {
                f_r = r;
                f_c = c;
            } 
        }
    }
}



void solve(int R, int C){
    queue<Node> q;
    
    dist[s_r][s_c] = 0;
    
    q.push(Node{s_r, s_c, dist[s_r][s_c]});
    
    int min_dis = 1e9;
    while(!q.empty()){
        
        Node node = q.front(); q.pop();
        
        if(visited[node.row][node.col])
            continue;
        
        visited[node.row][node.col] = true;

        for(int i = 0; i < 4; i++){
            int row = node.row + dir[i][0];
            int col = node.col + dir[i][1];
            
            if (row < 0 || row >= R || col < 0 || col >= C)
                continue;
            if (maze[row][col] == '#')
                continue;
            
            int dis = dist[node.row][node.col] + 1;
            if(!visited[row][col] && dis < min_dis){
                dist[row][col] = dis;
                q.push(Node{row, col, dist[row][col]});
            
                if (row == f_r && col == f_c) {
                    min_dis = dist[f_r][f_c];
                }
            }
        }
    }
 
    if (min_dis == 1e9) {
        min_dis = -1;
    }
    printf("%d\n", min_dis);
}

int main(int argc, char * argv[])
{
    int N, R, C;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &R, &C);
        
        load(R, C);
        solve(R, C);
    }

    return 0;
}
