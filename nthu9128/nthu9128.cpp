#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctype.h>

using namespace std;

int weight(char c)
{
    if(islower(c))
        return (c - 'a') * 2 + 1;
    else
        return (c - 'A') * 2;
}

bool cmp(string& a, string& b)
{
    string::iterator ait = a.begin(), bit = b.begin();
    while(ait != a.end() && bit != b.end())
    {
        int wa = weight(*ait), wb = weight(*bit);
        if(wa == wb)
            ait++, bit++;
        else if(wa < wb)
            return true;
        else
            return false;
    }

    if(ait == a.end() && bit == b.end())
        return false;
    else if(ait == a.end())
        return true;
    else
        return false;
}

int main(void)
{
    int n;
    cin >> n;

    while(n--)
    {
        string a, b;
        cin >> a >> b;

        if(cmp(a, b))
            cout << a << " " << b << endl;
        else
            cout << b << " " << a << endl;
    }

    return 0;
}
