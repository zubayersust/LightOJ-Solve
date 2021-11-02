/**
Online Judge : LightOJ
Problem No   : 1232
Problem Name : Coin Change (II)
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          :
Memory       :
Algorithm    : Dynamic Programming
*/

#include<bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_N 100
#define MAX_K 10000
#define MOD_BY 100000007

using namespace std;

int T,n,K;
int coin[MAX_N+1];
int dp_result[MAX_N+1][MAX_K+1];

int dp(int i, int amount)
{
    if(i>n)
    {
        if(amount==0)
            return 1;
        else return 0;
    }

    if(dp_result[i][amount]!=-1)
        return dp_result[i][amount];

    int result1=0, result2=0;

    for(int j=1; j<=K; j++)
        if(amount-coin[i]*j >= 0)
            result1 += dp(i+1, amount-coin[i]*j);

    result2 = dp(i+1, amount);

    return dp_result[i][amount] = (result1+result2) % MOD_BY;
}

void reset()
{
    mem(dp_result, -1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &T);

    int case_no=0, result;

    while(case_no < T)
    {
        reset();

        scanf("%d %d", &n, &K);

        for(int i=1; i<=n; i++)
            scanf("%d", &coin[i]);

        result = dp(1, K);
        printf("Case %d: %d\n", ++case_no, result);
    }

    return 0;
}
