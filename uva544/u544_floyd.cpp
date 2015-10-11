#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 202;
const int MAXR = 20000;
const int INF = 0x7fffffff;

typedef struct Edge {
    int src, dst, w;
}Edge;

int id = 0;
map<string, int> city_hash;
int getID(string& name){
    if(!city_hash.count(name))
        city_hash[name] = id++;
    return city_hash[name]; 
}

int g[MAXN][MAXN];
void init_graph(int maxn){
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            g[i][j] = 0;
}

int main(){
    int nC, nR, nCase = 0;
    while(scanf("%d%d",&nC ,&nR) == 2, nC || nR){
        init_graph(nC);
        
        int src, dst, w;
        string src_key, dst_key;
        for(int i = 0; i < nR; i++){
            cin >> src_key >> dst_key >> w;
            src = getID(src_key), dst = getID(dst_key);
            g[src][dst] = g[dst][src] = w;
        }
        
        string start, end;
        cin >> start >> end;
        
        int start_id = getID(start);
        int end_id = getID(end);

        for(int k = 0; k < nC; k++)
            for(int i = 0; i < nC; i++)
                for(int j = 0; j < nC; j++)
                    g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
        
        printf("Scenario #%d\n",++nCase);
        printf("%d tons\n\n",g[start_id][end_id]);
    }
    
    
    return 0;
}