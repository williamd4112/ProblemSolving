#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void hsort(vector<int>& v){
    make_heap(v.begin(), v.end());
    while(!v.empty()){
        cout << v.front() << endl;
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }
}

int main(){
    
    int arr[] = {20, 35, 15, 5, 12, 6};
    vector<int> v(arr, arr + 6);
    hsort(v);
    
    return 0;
}