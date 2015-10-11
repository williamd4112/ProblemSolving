#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_X = 10009;

int skyline[MAX_X] = {0};

int main(){
    
    int rightEnd = 0;
    
    int left, height, right;
    while(cin >> left >> height >> right){
        for(int i = left; i < right; i++){
            skyline[i] = max(skyline[i], height);
        }
        rightEnd = max(rightEnd, right);
    }
    
    bool isFirst = true;
    int lastHeight = 0;    
    for(int i = 0; i <= rightEnd; i++){
        if(lastHeight != skyline[i]){
            if(!isFirst) cout << " ";
            cout << i << " " << skyline[i];
            isFirst = false;
        }
        lastHeight = skyline[i];
    }
    cout << endl;
    
    return 0;
}