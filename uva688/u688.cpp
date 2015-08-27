#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_NUM_RECT = 102;

typedef struct Rect {
    double x, y, p;
}Rect;

bool isContain(const Rect &r, double x1, double y1, double x2, double y2){
    return (r.x - r.p <= x1 && r.x + r.p >= x2
        &&  r.y - r.p <= y1 && r.y + r.p >= y2);
}

double area(double x1, double y1, double x2, double y2){
    return (x2 - x1) * (y2 - y1);
}

double xCoord[2 * MAX_NUM_RECT];
double yCoord[2 * MAX_NUM_RECT];

Rect rects[MAX_NUM_RECT];

int main(){

    int cCase = 0;
    int n;

    while(cin >> n, n){
        double ans = 0;

        for(int i = 0; i < n; i++){
            cin >> rects[i].x >> rects[i].y >> rects[i].p;
            xCoord[i] = rects[i].x - rects[i].p;
            xCoord[i + n] = rects[i].x + rects[i].p;
            yCoord[i] = rects[i].y - rects[i].p;
            yCoord[i + n] = rects[i].y + rects[i].p;
        }

        sort(xCoord, xCoord + 2 * n);
        sort(yCoord, yCoord + 2 * n);

        for(int i = 0; i < 2 * n - 1; i++){
            for(int j = 0; j < 2 * n - 1; j++){
                for(int k = 0; k < n; k++){
                    if(isContain(rects[k], xCoord[i], yCoord[j], xCoord[i + 1], yCoord[j + 1])){
                        ans += area(xCoord[i], yCoord[j], xCoord[i + 1], yCoord[j + 1]);
                        break;
                    }
                }
            }
        }

        printf("%d %.2lf\n", ++cCase, ans);
    }

    return 0;
}
