#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>

#define EPS 1e-9
#define NINF -1./0.

using namespace std;

const int MAX_NUM_RECTS = 102;

enum EventType {
	IN, OUT
};

typedef struct Rect{
	double cx, cy, r;
	double x1, y1, x2, y2;

	Rect(){
		x1 = y1 = x2 = y2 = 0;
	}

	Rect(double cx, double cy, double r):
	 cx(cx)
	,cy(cy)
	,r(r)
	,x1(cx - r)
	,y1(cy - r)
	,x2(cx + r)
	,y2(cy + r){

	}

	friend bool operator <(const Rect a, const Rect b){
		return a.y1 < b.y1;
	}

}Rect;

typedef struct Node {
	int rectID;
	double x;
	EventType type;

	friend bool operator <(const Node a, const Node b){
		return a.x < b.x;
	}
}Node;

Rect rects[MAX_NUM_RECTS];
bool activeSet[MAX_NUM_RECTS];
Node endpoints[2 * MAX_NUM_RECTS];

int main(){

	int cCase = 0;
	int n;
	
	while(cin >> n, n){

		double x, y, r;
		for(int i = 0; i < n; i++){
			cin >> x >> y >> r;
			activeSet[i] = false;
			rects[i] = Rect(x, y, r);
			endpoints[i] = Node{i, rects[i].x1, IN};
			endpoints[i + n] = Node{i, rects[i].x2, OUT};
 		}

 		sort(rects, rects + n);
 		sort(endpoints, endpoints + 2 * n);

 		double area = 0;
 		activeSet[endpoints[0].rectID] = endpoints[0].type ==;

 		for(int i = 1; i < 2 * n; i++){
 			if ((endpoints[i].x - endpoints[i - 1].x) < EPS) // endpoints[i] == endpoints[i - 1]
 				continue;
 			//printf("Line %d: %lf, %d\n",i ,endpoints[i].x, endpoints[i].type);
 			double up = -1. / 0.;
 			double dx = endpoints[i].x - endpoints[i - 1].x;
 			for (int j = 0; j < n; j++) {

 				// // If intersect with scan region
 				if(!activeSet[j])
 					continue;
 				//printf("Rect %d\n",j);
 				// if(rects[j].x1 <= endpoints[i - 1].x && 
 				// 	rects[j].x1 + rects[j].r * 2 <= endpoints[i - 1].x)
 				// 	continue;
 				// if(rects[j].x1 >= endpoints[i] && 
 				// 	rects[j].x1 + rects[j].r * 2 >= endpoints[i])
 				// 	continue;

 				// Scan from bottom
 				if (rects[j].y1 <= (up)) {				
 					if ((rects[j].y1 + rects[j].r * 2) > up) {
 						area += (rects[j].y1 + rects[j].r * 2 - up) * dx;
 						up = rects[j].y1 + rects[j].r * 2;
 					}
 				} else {
 					area += rects[j].r * 2 * dx;
 					up = rects[j].y1 + rects[j].r * 2;
 				}
 			}

 			activeSet[endpoints[i].rectID] = (endpoints[i].type == IN);
 		}

 		printf("%d %.2lf\n", ++cCase, area);

	}

	return 0;
}