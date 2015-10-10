#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>

#define MAX 1024

using namespace std;

int main(void)
{
    string sa, sb;
    while(cin >> sa >> sb)
    {
        int a[MAX], b[MAX];
        int alen = 0, blen = 0;
        for(string::reverse_iterator it = sa.rbegin(); it != sa.rend(); it++)
            a[alen++] = int((*it) - '0');
        for(string::reverse_iterator it = sb.rbegin(); it != sb.rend(); it++)
            b[blen++] = int((*it) - '0');

        int carry = 0, cnt = 0, sum, i;
        for(i = 0; i < alen && i < blen; i++)
        {
            sum = a[i] + b[i] + carry;
            carry = sum / 10;
            if(carry)
                cnt++;
        }

        for(; i < alen; i++)
        {
             sum = a[i] + carry;
             carry = sum / 10;
             if(carry)
                 cnt++;
        }

        for(; i < blen; i++)
        {
             sum = b[i] + carry;
             carry = sum / 10;
             if(carry)
                 cnt++;
       }

        printf("%d\n",cnt);
    }

    return 0;
}
