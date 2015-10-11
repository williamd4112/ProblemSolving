#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_BUILDING 5002

using namespace std;

typedef struct Building {
    int left, height, right;
} Building;

typedef struct Strip{
    int left, height;
}Strip;

typedef struct Skyline{
    vector<Strip> strips;
    
    void append(Strip strip){
        
        if(!strips.empty()){
            if(strips[strips.size() - 1].height == strip.height){
                return;
            }
            
            if(strips[strips.size() - 1].left == strip.left){
                strips[strips.size() - 1].height = max(strips[strips.size() - 1].height, strip.height);
                return;
            }
        }
        
        strips.push_back(strip);
    }
    
}Skyline;

Building buildings[MAX_BUILDING];

Skyline merge(Skyline& leftSkyline, Skyline& rightSkyline){
    Skyline skyline;
    
    vector<Strip>::iterator leftIt = leftSkyline.strips.begin();
    vector<Strip>::iterator rightIt = rightSkyline.strips.begin();
    
    int leftCurrentHeight = 0;
    int rightCurrentHeight = 0;
    
    while(leftIt != leftSkyline.strips.end() && rightIt != rightSkyline.strips.end()){
        if(leftIt->left < rightIt->left){
            leftCurrentHeight = leftIt->height;
            skyline.append(Strip{leftIt->left, max(leftCurrentHeight, rightCurrentHeight)});
            leftIt++;
        }
        else{
            rightCurrentHeight = rightIt->height;
            skyline.append(Strip{rightIt->left, max(leftCurrentHeight, rightCurrentHeight)});
            rightIt++;
        }
    }
    
    while(leftIt != leftSkyline.strips.end()){
        skyline.append(Strip{leftIt->left, leftIt->height});
        leftIt++;
    }
    
    while(rightIt != rightSkyline.strips.end()){
        skyline.append(Strip{rightIt->left, rightIt->height});
        rightIt++;
    }
    
    return skyline;
}

Skyline solve(Building *arr, int lower, int upper){
    if(lower < upper){
        int mid = lower + (upper - lower) / 2;
        Skyline leftSkyline = solve(arr, lower, mid);
        Skyline rightSkyline = solve(arr, mid + 1, upper);
        return merge(leftSkyline, rightSkyline);    
    }
    else if(lower == upper){
        Skyline skyline;
        skyline.append(Strip{arr[lower].left, arr[lower].height});
        skyline.append(Strip{arr[lower].right, 0});
        return skyline;
    }
}

int main(){
    
    int i = 0;
    int left, height, right;
    while(scanf("%d%d%d",&left, &height, &right) == 3){
        buildings[i++] = Building{left, height, right};
    }
    
    Skyline ans = solve(buildings, 0, i - 1);
    for(vector<Strip>::iterator it = ans.strips.begin(); it != ans.strips.end(); it++){
        if(it != ans.strips.begin())
            putchar(' ');
        printf("%d %d",it->left, it->height);
    }
    putchar('\n');
    
    return 0;
}