#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 202;
const int MAXP = 1002;

typedef struct Node {
    int row, col;
}Node;

inline double getDis(int ar, int ac, int br, int bc){
    return sqrt(pow(ar - br, 2) + pow(ac - bc, 2));
}

inline double getNodeDis(Node& a, Node& b){
    return getDis(a.row, a.col, b.row, b.col);
}

double d[MAXN][MAXN];

int main(){
    
    int n, nCase = 0;
    while(cin >> n, n){
        Node nodes[MAXN];
        for(int i = 0; i < n; i++)
            cin >> nodes[i].col >> nodes[i].row;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = (i == j) ? 0 : getNodeDis(nodes[i], nodes[j]);
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        printf("Scenario #%d\n",++nCase);
        printf("Frog Distance = %.3f\n\n",d[0][1]);
    }
    
    return 0;
}

