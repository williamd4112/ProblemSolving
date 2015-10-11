#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000003;

long long d[MAX];

long long mergearr(long long *arr, int start, int mid, int end){
    int len = end - start + 1;
    long long tmp[len];
    
    long long inv = 0;
    int ti = 0, li = start, ri = mid + 1;
    
    while(li <= mid && ri <= end)
        if(arr[li] <= arr[ri])
            tmp[ti++] = arr[li++];
        else
            tmp[ti++] = arr[ri++], inv += (mid - li + 1);
            
    while(li <= mid)
        tmp[ti++] = arr[li++];
    while(ri <= end)
        tmp[ti++] = arr[ri++];
        
    copy(tmp, tmp + len, arr + start);
    
    return inv;
}

long long mergesort(long long *arr, int start, int end){
    if(start >= end)
        return 0;
    
    long long inv = 0;
    int mid = start + (end - start) / 2;
    inv += mergesort(arr, start, mid);
    inv += mergesort(arr, mid + 1, end);
    inv += mergearr(arr, start, mid, end);

    return inv;
}

int main(){
    
    int n;
    while(scanf("%d", &n)){
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            scanf("%lld",&d[i]);
        printf("%lld\n",mergesort(d, 0, n - 1));
    }
    
    return 0;
}