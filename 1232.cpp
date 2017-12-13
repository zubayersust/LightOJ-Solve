/**
Online Judge : LightOJ
Problem No   : 1232
Problem Name : Coin Change (II)
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.492s
Memory       : 1768KB
Algorithm    : Coin Change
*/

#include<bits/stdc++.h>

#define MAX_N 100
#define MAX_K 10000

using namespace std;

int testCase,caseNum=1;
int n,k;

int coin[MAX_N+1];
long long way[MAX_K+1];

void reset()
{
    int i;

    way[0] = 1;

    for(i=1; i<=k; i++)
        way[i] = 0;
}

int coin_change()
{
    int i,j;

    for(i=1; i<=n; i++)
        for(j=1; j<=k; j++)
            if(coin[i] <= j)
                way[j] = way[j]%100000007 + way[j-coin[i]]%100000007;

    return way[k];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(caseNum<=testCase)
    {
        scanf("%d %d", &n, &k);

        int i;

        for(i=1; i<=n; i++)
            scanf("%d", &coin[i]);

        reset();

        int result = coin_change();

        printf("Case %d: %lld\n", caseNum++, result%100000007);
    }
    return 0;
}
