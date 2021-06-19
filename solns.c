/* Enter your solutions in this file */
#include <stdio.h>
#include <stdlib.h>

int max(int ar[], int n)
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > mx)
            mx = ar[i];
    }
    return mx;
}

int min(int ar[], int n)
{
    int mx = __INT_MAX__;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] < mx)
            mx = ar[i];
    }
    return mx;
}
float average(int ar[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    float ans = sum / n;
    return ans;
}
int mode(int ar[], int n)
{
    int maxn = max(ar, n);
    int minn = min(ar, n);
    minn = -minn;
    int *arr = calloc(minn+maxn + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[ar[i]+minn] = arr[ar[i]+minn] + 1;
    }
    int ans = max(arr, minn+maxn + 1);
    for(int i=0;i<minn+maxn+1;i++){
        if(arr[i]==ans)
        {
            ans = i;
            break;
        }
    }
    free(arr);
    return ans-minn;
}
int factors(int n, int ar[])
{
    int start = 2;
    int idx = 0;
    while (n != 1)
    {
        int x = n % start;
        if (x == 0)
        {
            ar[idx] = start;
            n = n / start;
            idx++;
        }
        else
        {
            start++;
        }
    }
    return idx;
}