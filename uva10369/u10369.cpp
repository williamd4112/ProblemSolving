#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAXS = 102;
const int MAXP = 502;

typedef struct Edge {
    int ux, uy, vx, vy;
    double dis;
    
    bool operator ==(const Edge b){
        return (ux == b.ux && uy == b.uy) || (ux == b.uy && uy == b.ux);
    }
    
    friend bool operator <(const Edge a, const Edge b){
        return a.dis > b.dis;
    }
}Edge;

typedef struct Point{
    int x, y;
}Point;

vector<Point> pv;
set<Edge> es;

double dist(const Point a, const Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void reset(){
    pv.clear();
    es.clear();
}

void load_point(int p){
    for(int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;
        pv.push_back(Point{x, y});
    }
}

void load_edge(int p){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            if(i == j) continue;
            es.insert(Edge{pv[i].x, pv[i].y, pv[j].x, pv[j].y, dist(pv[i], pv[j])});
        }
    }
}

void dbg(int p){
    for(set<Edge>::iterator it = es.begin(); it != es.end(); it++){
        Edge e = *it;
        printf("Edge((%d, %d), (%d, %d)): %f\n",e.ux,e.uy,e.vx,e.vy,e.dis);
    }
}

int main(){
    int nCase;
    cin >> nCase;
    
    while(nCase--){
        int s, p;
        cin >> s >> p;
        reset();
        load_point(p);
        load_edge(p);
        dbg(p);
    }
    
    return 0;
}

