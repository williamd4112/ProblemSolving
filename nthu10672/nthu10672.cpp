#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1e6 + 9;

ll arr[N];

ll merge(int lower, int mid, int upper);
ll solve(int lower, int upper);

void dbg(int lower, int upper){
    for(int i = lower; i <= upper; i++){
        printf("%lld ",arr[i]);
    }
    cout << endl;
}

ll solve(int lower, int upper){
    ll inv = 0;
    if(lower < upper){
        int mid = lower + (upper - lower) / 2;
        inv += solve(lower, mid);
        inv += solve(mid + 1, upper);
        inv += merge(lower, mid, upper);
    }
    
    return inv;
}

ll merge(int lower, int mid, int upper){
    int tmpLen = upper - lower + 1;
    
    ll tmp[tmpLen];
    memset(tmp, 0, sizeof(tmp));
    
    ll inv = 0;
    
    int ti = 0, lowerIndex = lower, upperIndex = mid + 1;
    for(;lowerIndex <= mid && upperIndex <= upper; ti++){
        if(arr[lowerIndex] > arr[upperIndex]){
            tmp[ti] = arr[upperIndex++];
            inv += mid - lowerIndex + 1;
        }
        else{
            tmp[ti] = arr[lowerIndex++];
        }
    }
    
    while(lowerIndex <= mid){
        tmp[ti++] = arr[lowerIndex++];
    }
    
    while(upperIndex <= upper){
        tmp[ti++] = arr[upperIndex++];
    }
    
    memcpy(arr + lower, tmp, sizeof(tmp));
    
    return inv;
}

int main(){
    
    int n;
    while(cin >> n, n != 0){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << solve(0, n - 1) << endl;
    }
    
    return 0;
}