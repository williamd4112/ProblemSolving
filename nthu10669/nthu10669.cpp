#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_NODE = 1003;
const int MAX_EDGE = 100005;

typedef struct Edge {
	int u, v;
	int w;
	
	friend bool operator <(const Edge a, const Edge b){
		return a.w < b.w;
	}
}Edge;

int disjoint_set[MAX_NODE];
Edge edges[MAX_EDGE];

int find(int);
void unions(int , int);

int main(void){
	int nCase;
	scanf("%d",&nCase);

	while(nCase--){
		int nNode, nEdge;
		scanf("%d%d",&nNode, &nEdge);
		
		for(int i = 1; i <= nNode; i++)
			disjoint_set[i] = i;		
		
		for(int i = 0; i < nEdge; i++)
			scanf("%d%d%d",&edges[i].u, &edges[i].v, &edges[i].w);
		
		int weight = 0;
		sort(edges, edges + nEdge);
		for(int i = 0; i < nEdge; i++){
			int pu = find(edges[i].u);
			int pv = find(edges[i].v);
			if(pu != pv){
				unions(pu, pv);
				weight += edges[i].w;
			}
		}
		printf("%d\n",weight);
	}

	return 0;
}

int find(int x){
	return (disjoint_set[x] == x) ? x : disjoint_set[x] = find(disjoint_set[x]);
}

void unions(int a, int b){
	disjoint_set[find(a)] = find(b); 
}
