#include <iostream>
#include <cstdio>

using namespace std;

const int MAXC = 102;
const int MAXS = 1002;
const int MAXQ = 10002;
const int INF = 0x7fffffff;

int G[MAXC][MAXC];

void dbg(int maxc, int nS, int nQ){
    for(int i = 1; i <= maxc; i++){
        for(int j = 1; j <= maxc; j++){
            if(G[i][j] == INF)
                printf("%-4s","X");
            else
                printf("%-4d",G[i][j]);
        }
        cout << endl;
    }
}

void reset(int maxc){
    for(int i = 1; i <= maxc; i++){
        for(int j = 1; j <= maxc; j++)
            G[i][j] = INF;
        G[i][i] = 0;
    }
}

void load(int maxc, int nS){
    int src, dst, w;
    for(int i = 0; i < nS; i++){
        cin >> src >> dst >> w;
        G[src][dst] = G[dst][src] = w;
    }
}

void floyd(int maxc){
    for(int k = 1; k <= maxc; k++)
        for(int i = 1; i <= maxc; i++)
            for(int j = 1; j <= maxc; j++)
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
}

void query(int nQ){
    int src, dst;
    for(int i = 0; i < nQ; i++){
        cin >> src >> dst;
        if(G[src][dst] == INF)
            printf("no path\n");
        else
            printf("%d\n",G[src][dst]);
    }
}

int main(){
    
    int nCase = 0;
    int maxc, nS, nQ;
    while(cin >> maxc >> nS >> nQ, maxc || nS || nQ){
        reset(maxc);
        load(maxc, nS);
        floyd(maxc);
        //dbg(maxc, nS, nQ);
        
        if(nCase) putchar('\n');
        printf("Case #%d\n",++nCase);
        query(nQ);
    }
    
    return 0;
}