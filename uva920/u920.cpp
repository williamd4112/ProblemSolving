#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef struct Point {
    double x, y;
    
    friend ostream& operator <<(ostream& os, const Point p){
        return os << "(" << p.x << ", " << p.y << ")";
    }
    
    friend bool operator <(const Point p1, const Point p2){
        return p1.x < p2.x;
    }
}Point;

double distance(const Point p1, const Point p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

Point project(Point p1, Point p2, Point spacePoint){
    double m = (p2.y - p1.y) / (p2.x - p1.x);
    double c = p2.y  - m * p2.x;
    
    return Point{(spacePoint.y - c) / m, spacePoint.y};
}

int main(){
    
    int nCase;
    cin >> nCase;
    
    while(nCase--){
        int nPoint;
        cin >> nPoint;
        
        vector<Point> points;
        for(int i = 0; i < nPoint; i++){
            double x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }
        
        sort(points.begin(), points.end());
        
        double ans = 0;
        Point highestPoint = points.back();
        for(vector<Point>::reverse_iterator rit = points.rbegin() + 1; rit != points.rend(); rit++){
            if(rit->y > highestPoint.y){
                ans += distance(*rit, project(*(rit - 1), *rit, highestPoint));
                highestPoint = *rit;
            }
        }
    
        printf("%.2lf\n",ans);
    }
    
    return 0;
}