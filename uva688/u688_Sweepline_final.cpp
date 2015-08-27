/*
	UVA 688
	Language: C++11
	Status: Accepted
	Time: 0.000
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int MAX_NUM_RECTS = 102;
const double NINF = -1. / 0.;
const double EPS = 1e-9;

typedef struct Rect {
	double x1, y1, x2, y2;
	double radius, diameter;

	Rect(){}

	Rect(double x, double y, double r):
	x1(x - r),
	y1(y - r),
	x2(x + r),
	y2(y + r),
	radius(r),
	diameter(r * 2){}

	friend bool operator <(const Rect a, const Rect b){
		return a.y1 < b.y1;
	}

}Rect;

bool equal(const double a, const double b){
	return fabs(a - b) < EPS;
}

bool lsq(const double a, const double b){
	return a <= (b + EPS);
} 

bool lrq(const double a, const double b){
	return a >= (b - EPS);
}

bool isOutBound(const Rect &rect, const double leftBound, const double rightBound){
	return (lsq(rect.x1,leftBound) && lsq(rect.x2, leftBound)) || 
			(lrq(rect.x1, rightBound) && lrq(rect.x2, rightBound));
}

Rect rects[MAX_NUM_RECTS];
double endpoints[2 * MAX_NUM_RECTS];

int main(){
	
	int n, cCase = 0;

	while(cin >> n, n){

		// Get input
		for(int i = 0; i < n; i++){
			double x, y, r;
			cin >> x >> y >> r;
			rects[i] = Rect(x, y, r);
			endpoints[i] = rects[i].x1;
			endpoints[i + n] = rects[i].x2;
		}

		// Sort rect by Y coord
		// Sort endpoint by X coord
		sort(rects, rects + n);
		sort(endpoints, endpoints + 2 * n);

		double area = 0;
		for(int i = 1; i < 2 * n; i++){
			// Overlap scanline
			if(equal(endpoints[i], endpoints[i - 1]))
				continue;

			double leftBound = endpoints[i - 1];
			double rightBound = endpoints[i];
			double dx = rightBound - leftBound;
			double currentHeight = NINF;

			// Iterate each rectangle
			for(int j = 0; j < n; j++){
				// Check if rect is outbound
				if(isOutBound(rects[j], leftBound, rightBound))
					continue;

				// Scan from bottom, update the currentHeight if need
				if(lsq(rects[j].y1, currentHeight)){
					if(rects[j].y2 > currentHeight){
						area += (rects[j].y2 - currentHeight) * dx;
						currentHeight = rects[j].y2;
					}
				}
				else{
					area += rects[j].diameter * dx;
					currentHeight = rects[j].y2;
				}
			}
		}

		printf("%d %.2lf\n", ++cCase, area);

	}
}