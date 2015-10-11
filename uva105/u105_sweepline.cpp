#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef struct Building {
    int left;
    int height;
    int right;
    
    friend bool operator <(const Building b1, const Building b2){
        return b1.height > b2.height;
    }
    
    friend bool operator ==(const Building b1, const Building b2){
        return (b1.left == b2.left &&
                b1.height == b2.height &&
                b1.right == b2. right);
    }
}Building;

typedef struct Point {
    int left;
    int height;
    
    int buildingIndex;
    bool isRight;
    
    friend bool operator <(const Point p1, const Point p2){
        return (p1.left == p2.left) ? p1.buildingIndex < p2.buildingIndex : p1.left < p2.left;
    }
    
    friend bool operator ==(const Point p1, const Point p2){
        return (p1.left == p2.left &&
                p1.height == p2.height &&
                p1.buildingIndex == p2.buildingIndex &&
                p1.isRight == p2.isRight);
    }
}Point;

int maxHeight(set<Building>& s){
    return (s.empty()) ? 0 : s.begin()->height;
}

int main(){
    
    vector<Building> buildings;
    set<Building> activeSet;
    set<Point> criticalPointSet;
    vector<Point> ansSet;
    
    int left, height, right;
    while(scanf("%d%d%d",&left, &height, &right) == 3){
        buildings.push_back(Building{left, height, right});
        
        int buildingIndex = buildings.size() - 1;
        criticalPointSet.insert(Point{left, height, buildingIndex, false});
        criticalPointSet.insert(Point{right, 0, buildingIndex, true});
        
    }
    
    int lastHeight = 0, lastLeft = -1;
    for(set<Point>::iterator it = criticalPointSet.begin(); it != criticalPointSet.end(); it++){
       // printf("Critical(%d %d) [%d]\n",it->left, it->height, it->buildingIndex);
        Building building = buildings[it->buildingIndex];
        if(!it->isRight){
           //printf("Insert %d %d %d\n",building.left, building.height, building.right);
            activeSet.insert(building);
        }
        else{
            activeSet.erase(building);
            //printf("Remove %d %d %d\n",building.left, building.height, building.right);
        }
        
        int height = maxHeight(activeSet);
        if(height != lastHeight){
            //printf("Point(%d %d)\n",it->left, height);
            if(it->left == lastLeft){
                ansSet.back().height = height;
            }
            else{
                ansSet.push_back(Point{it->left, height});
            }
            
            lastHeight = height;
            lastLeft = it->left;
        }
        
        // for(set<Building>::iterator j = activeSet.begin(); j != activeSet.end(); j++){
        //     printf("%d %d %d\n",j->left, j->height, j->right);
        // }
        
    }

    for(vector<Point>::iterator it = ansSet.begin(); it != ansSet.end(); it++){
        if(it != ansSet.begin())
            putchar(' ');
        printf("%d %d",it->left, it->height);
    }
    cout << endl;
    
    return 0;
}
