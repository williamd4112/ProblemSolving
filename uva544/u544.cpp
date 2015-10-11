#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 202;
const int MAXR = 20000;

typedef struct Edge {
    int src_key, dst_key, w;
}Edge;

bool cmp(const Edge a, const Edge b){
    return a.w > b.w;
}

// City hash
int id;
map<string, int> city_hash;
int getID(string name){
    if(!city_hash.count(name))
        city_hash[name] = id++;
    return city_hash[name];
}

// Disjoint set
int disj_set[MAXN];
int find(int i){
    return (disj_set[i] == i) ? i : (disj_set[i] = find(disj_set[i]));
}

void sunion(int p, int c){
    disj_set[c] = p;
}


int main(){
    
    int nC, nR, nCase = 0;
    while(scanf("%d%d",&nC ,&nR) == 2, nC != 0, nR != 0){
        // Load road
        city_hash.clear(); id = 0;
        
        vector<Edge> ev;
        
        int src_id, dst_id;
        string src_city, dst_city;
        int road_load;
        
        for(int i = 0; i < nC; i++)
            disj_set[i] = i;
        for(int i = 0; i < nR; i++){
            cin >> src_city >> dst_city >> road_load;
            ev.push_back( Edge{getID(src_city), getID(dst_city), road_load} );
        }
        
        // Load start and end
        string start, end;
        cin >> start >> end;
        
        int start_id = getID(start);
        int end_id = getID(end);
        
        // Kruskal
        sort(ev.begin(), ev.end(), cmp);
        for(int i = 0; i < ev.size(); i++){
            Edge e = ev[i];
            int sp = find(e.src_key);
            int dp = find(e.dst_key);
            if(sp != dp) {
                sunion(sp, dp);
                
                if(find(start_id) == find(end_id)){
                    printf("Scenario #%d\n",++nCase);
                    printf("%d tons\n\n",e.w);
                    break;
                }
            }
        }
    }
    
    return 0;
}
