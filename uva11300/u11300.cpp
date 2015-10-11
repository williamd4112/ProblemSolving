#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1000005

long long arr[MAX];
long long c[MAX];

int main(void){
    
    int n;
    while(scanf("%d",&n) == 1){
        long long sum = 0;
        for(int i = 0; i < n; i++)
            scanf("%lld",&arr[i]), sum += arr[i];
        
        long long m = sum / n;
        c[0] = 0;
        for(int i = 1; i < n; i++)
            c[i] = c[i - 1] + arr[i] - m;
        sort(c, c + n);
        
        long long x1 = c[n / 2];
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(x1 - c[i]);
        }
        
        printf("%lld\n",ans);
        
        
    }
    
    return 0;
}