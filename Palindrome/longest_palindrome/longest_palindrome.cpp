#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX 705

using namespace std;

bool dp[MAX][MAX] = {0};

string dp_palindrome(char *str)
{
    memset(dp, false, sizeof(dp));

    int start = 0, maxlen = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        dp[i][i] = true;
    }

    for(int i = 0; i < len - 1; i++)
    {
        if(str[i] == str[i + 1])
        {
             dp[i][i + 1] = true;
             start = i;
             maxlen = 2;
        }
    }

    for(int k = 3; k <= len; k++)
    {
         for(int i = 0; i < len - k + 1; i++)
         {
            int j = i + k - 1;
            if(str[i] == str[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if(k > maxlen)
                {
                     maxlen = k;
                     start = i;
                }
            }
         }
    }

    return string(str, start, maxlen);
}

int main(void)
{
    char *s = "aabbbbca";
    string str = dp_palindrome(s);
    for(int i = 0; i < strlen(s); i++)
    {
         for(int j = 0; j < strlen(s); j++)
         {
             printf("%d ",dp[i][j]);
         }
         printf("\n");
    }

    cout << str << endl;

    return 0;
}
