#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 102;
const int INF = 0x7fffffff;

int G[MAXN][MAXN];

void reset(int nC){
    for(int i = 1; i <= nC; i++){
        for(int j = 1; j <= nC; j++)
            G[i][j] = INF;
        G[i][i] = 0;
    }
}

void load(int nR){
    int src, dst, w;
    for(int i = 0; i < nR; i++){
        cin >> src >> dst >> w;
        G[src][dst] = G[dst][src] = w;
    }
}

void floyd(int nC){
    for(int k = 1; k <= nC; k++){
        for(int i = 1; i <= nC; i++){
            for(int j = 1; j <= nC; j++){
                if(G[i][j] != INF)
                    G[i][j] = max( G[i][j], min(G[i][k], G[k][j]) );
                else
                    G[i][j] = min( G[i][k], G[k][j] );
            }
        }
    }
}

int main(){
    
    int nC, nR, nCase = 0;
    while(cin >> nC >> nR, nC || nR){
        reset(nC);
        load(nR);
        
        int start, end, tot;
        cin >> start >> end >> tot;
        
        floyd(nC);
        
        int loading = G[start][end] - 1;
        
        printf("Scenario #%d\n",++nCase);
        printf("Minimum Number of Trips = %d\n\n",(int)ceil((float)tot / loading));
    }
    
    return 0;
}