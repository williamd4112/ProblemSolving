#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

typedef struct Point {
    double x, y;
    
    friend bool operator <(const Point p1, const Point p2){
        return p1.x < p2.x;
    }

}Point;

double distance(const Point p1, const Point p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double conquer(vector<Point>& pv, int left, int mid, int right, double leftMin, double rightMin){
    double minDis = min(leftMin, rightMin);
    double median = (pv[mid].x + pv[mid + 1].x) / 2.0;
    double medianRight = median + minDis;
    double medianLeft = median - minDis;
    
    double ans = minDis;
    for(int i = mid + 1; pv[i].x < medianRight && i <= right; i++){
        for(int j = mid; pv[j].x > medianLeft && j >= left; j--){
            double dis = distance(pv[i], pv[j]);
            if(dis < ans){
                ans = dis;
            }
        }
    }
    
    return ans;
}

double divide(vector<Point>& pv, int left, int right){
    if(left >= right)
        return DBL_MAX;
    int mid = left + (right - left) / 2;
    double leftMin = divide(pv, left, mid);
    double rightMin = divide(pv, mid + 1, right);
    double ans = conquer(pv, left, mid, right, leftMin, rightMin);
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
        
        double ans = divide(pv, 0, pv.size() - 1);
        cout.setf(ios::fixed, ios::floatfield); 
        cout.precision(4);
            
        if(ans < 10000){
            cout << ans << endl;
        }else{
            cout << "INFINITY" << endl;
        }
    }
    
    return 0;
    return 0;
}