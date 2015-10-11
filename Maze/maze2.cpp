#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 1001;

int maze[MAXN][MAXN];

void dbg(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << setw(3) << maze[i][j];
        }
        cout << endl;
    }    
}

void load(int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> maze[i][j];
}

int solve(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i - 1 >= 0 && j - 1 >= 0 && i - 1 < n && j - 1 < m)
                maze[i][j] += min(maze[i - 1][j], maze[i][j - 1]);
            else if(i - 1 >= 0 && i - 1 < n)
                maze[i][j] += maze[i - 1][j];
            else if(j - 1 >= 0 && j - 1 < m)
                maze[i][j] += maze[i][j - 1];
        }
    }
    
    return maze[n - 1][m - 1];
}

int main(){
    
    int nCase;
    cin >> nCase;
    
    while(nCase--){
        int n, m;
        cin >> n >> m;
        
        load(n, m);
        cout << solve(n, m);
        if(nCase) cout << endl;
        // dbg(n, m);
    }
    
    return 0;
}