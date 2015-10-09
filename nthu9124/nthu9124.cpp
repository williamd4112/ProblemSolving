#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>

#define MAXLEN 1000

using namespace std;

typedef struct BigNumber
{
    list<int> num;

    BigNumber(){}

    BigNumber(int number)
    {
        do num.push_back(number % 10);
        while((number /= 10));
    }

    BigNumber operator *(const BigNumber& b)
    {
        BigNumber result;

        int len = num.size() + b.num.size();
        int tmp[len];
        int i = 0, j = 0;

        memset(tmp, 0, sizeof(tmp));
        for(list<int>::const_iterator ait = num.begin(); ait != num.end(); ait++)
        {
            j = 0;
            for(list<int>::const_iterator bit = b.num.begin(); bit != b.num.end(); bit++)
            {
                 tmp[i + j] += (*ait) * (*bit);
                 j++;
             }
             i++;
        }

        int carry = 0;
        for(int i = 0; i < len; i++)
        {
            tmp[i] += carry;
            result.num.push_back(tmp[i] % 10);
            carry = tmp[i] / 10;
        }

        int val;
        while((val = result.num.back()) == 0)
            result.num.pop_back();

        return result;
    }

    friend ostream& operator <<(ostream& os, BigNumber& b)
    {
         for(list<int>::reverse_iterator it = b.num.rbegin(); it != b.num.rend(); ++it)
             os << *it;
         return os;
    }

}BigNumber;

int main(void)
{
    int n;
    cin >> n;

    while(n--)
    {
         int b, p;
         cin >> b >> p;

         BigNumber base(b);
         BigNumber ans(1);
         while(p)
         {
             if(p % 2 == 0)
             {
                base = base * base;
                p /= 2;
             }
             else
             {
                ans = ans * base;
                p--;
             }
         }

         cout << ans << endl;
    }

    return 0;
}
