#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 10000007

using namespace std;

long long merge(char *arr, int left, int mid, int right)
{
    int len = right - left + 1;
    char temp[len];
    long long inv = 0;
    int li = left;
    int ri = mid + 1;
    int ti = 0;

    while(li <= mid && ri <= right)
    {
        if(arr[li] <= arr[ri])
        {
            temp[ti++] = arr[li++];
        }
        else
        {
            temp[ti++] = arr[ri++];
            inv += mid - li + 1;
        }
    }

    while(li <= mid)
        temp[ti++] = arr[li++];
    while(ri <= right)
        temp[ti++] = arr[ri++];

    memcpy(&arr[left], temp, len);

    return inv;
}

long long mergesort(char *arr, int left, int right)
{
    if(left >= right)
        return 0;

    long long inv = 0;
    int mid = left + (right - left) / 2;
    inv += mergesort(arr, left, mid);
    inv += mergesort(arr, mid + 1, right);
    inv += merge(arr, left, mid, right);

    return inv;
}

char seq[N];
int getstr()
{
    int i = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n')
        seq[i++] = c;
    return i;
}

int main(void)
{
    int len;
    while((len = getstr()))
    {
        long long inv = mergesort(seq, 0, len - 1);
        printf("%lld\n",inv);
    }
    return 0;
}
