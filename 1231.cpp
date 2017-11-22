/**
Online Judge : LightOJ
Problem No   : 1231
Problem Name : Coin Change (I)
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.252s
Memory       : 1888K
Algorithm    : Coin Change
*/

#include<bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_N 50
#define MAX_K 1000

using namespace std;

int testCase,caseNum=1;
int n,k;

int coin[MAX_N+1];
int coin_no[MAX_N+1];

int dp[MAX_N+1][MAX_K+1];

int coin_change(int i, int amount)
{
    if(i>n)
    {
        if(amount==0)
            return 1;
        return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount];

    int result1=0,result2=0;

    int j;

    for(j=1; j<=coin_no[i]; j++)
        if(amount-(coin[i]*j)>=0)
            result1 += coin_change(i+1, amount-(coin[i]*j));
    result2 = coin_change(i+1,amount);

    return dp[i][amount] = (result1+result2)%100000007;
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
        for(i=1; i<=n; i++)
            scanf("%d", &coin_no[i]);

        mem(dp, -1);

        int result = coin_change(1,k);

        printf("Case %d: %d\n", caseNum++, result);
    }
    return 0;
}
