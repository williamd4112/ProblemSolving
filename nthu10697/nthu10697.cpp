#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

const long long M = 2 * 1e9 + 2;
const long long N = 100009;

using namespace std;

long long items[N];
long long packet[N];

int solve(int m, int n){
    int packetIndex = 0;
    
    for(int i = 1; i <= n; i++){
        
        long long tmp = items[i] + packet[packetIndex];
        if(tmp > m){
            packet[++packetIndex] = items[i];
        }
        else{
            packet[packetIndex] = tmp;   
        }
        
        // for(int k = 0; k <= packetIndex; k++){
        //     printf("%lld ",packet[k]);
        // }
        // cout << endl;
    }
    
    return (n == 0) ? 0 : packetIndex + 1;
}

int main(){
    
    long long m;
    while(cin >> m){

        long long size, n = 1;
        while(cin >> size, size != 0){
            packet[n - 1] = 0;
            items[n] = size;
            n++;
        }
        n--;
        //cout << "n = " << n << endl;
        
        cout << solve(m, n) << endl;
        
    }
    
    return 0;
}