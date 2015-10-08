#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void dp_palindrome(char *str, int left, int right)
{
    int li = left, ri = right;
    while(str[li] == str[ri])
    {
        li++;
        ri--;

        if(left >= right)
        {
            for(int i = li; i <= ri; i++)
            {
                printf("%c",str[i]);
            }
            return;
        }
    }

}

int main(void)
{

    return 0;
}
