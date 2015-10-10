#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX 1024

using namespace std;

bool dp[MAX][MAX];

string dp_palindrome(string& s)
{
    memset(dp, false, sizeof(dp));

    int len = s.length();
    int start = 0, maxlen = 1;

    for(int i = 0; i < len; i++)
        dp[i][i] = true;

    for(int i = 0; i < len - 1; i++)
    {
         if(s[i] == s[i + 1])
         {
             dp[i][i + 1] = true;
             if(2 > maxlen)
             {
                 start = i;
                 maxlen = 2;
             }
         }
    }

    for(int k = 3; k <= len; k++)
    {
         for(int i = 0; i < len - k + 1; i++)
         {
             int j = i + k - 1;
             if(s[i] == s[j] && dp[i + 1][j - 1])
             {
                 dp[i][j] = true;
                 if(k > maxlen)
                 {
                      start = i;
                      maxlen = k;
                 }
             }
         }
    }

    return string(s, start, maxlen);
}

int main(void)
{
    string s;
    while(cin >> s)
    {
         cout << dp_palindrome(s) << endl;
    }

    return 0;
}
