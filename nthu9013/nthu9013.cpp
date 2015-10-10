#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 1024

using namespace std;

int lcstring(string& a, string& b)
{
    int n = a.length();
    int m = b.length();
    int dp[n][m];
    int maxlen = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i] == b[j])
                maxlen = max(maxlen, (dp[i][j] = (i - 1 < 0 || j - 1 < 0) ? 1 : dp[i - 1][j - 1] + 1));
            else
                 dp[i][j] = 0;

    return maxlen;
}

int main(void)
{
    int n;
    cin >> n;

    while(n--)
    {
        string a, b;
        cin >> a >> b;
        cout << lcstring(a, b) << endl;
    }

    return 0;
}
