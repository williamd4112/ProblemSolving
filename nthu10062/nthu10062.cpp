#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctype.h>

using namespace std;

int main(void){
    long long len = 0, maxLen = 0;
    char c, lastChar = '\0';
    while(cin >> c, c != '#'){
        if(isalpha(c) && islower(c)){
            if(c < lastChar){
                maxLen = max(len, maxLen);
                len = 0;
            }
            lastChar = c;
            len++;
        }
    }
    cout << maxLen << endl;
    return 0;
}
