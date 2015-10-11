#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

typedef struct Point {
    int x, y;
    
    friend bool operator <(const Point p1, const Point p2){
        return p1.x < p2.x;
    }

}Point;

double distance(const Point p1, const Point p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double solve(vector<Point>& pv){
    double ans = DBL_MAX;
    
    for(vector<Point>::iterator i = pv.begin(); i != pv.end(); i++){
        for(vector<Point>::iterator j = i + 1; j != pv.end(); j++){
            if((j->x - i->x) > ans)
                break;
                
            double dis = distance(*i, *j);
            if(dis < ans)
                ans = dis;
        }
    }
    
    return ans;
}

int main(){
    
    int nPoint;
    while(cin >> nPoint, nPoint){
        vector<Point> pv;
        while(nPoint--){
            double x, y;
            cin >> x >> y;
            pv.push_back(Point{x, y});
        }
        
        sort(pv.begin(), pv.end());
        
        double ans = solve(pv);
        cout.setf(ios::fixed, ios::floatfield); 
        cout.precision(4);
            
        if(ans < 10000){
            cout << ans << endl;
        }else{
            cout << "INFINITY" << endl;
        }
    }
    
    return 0;
}