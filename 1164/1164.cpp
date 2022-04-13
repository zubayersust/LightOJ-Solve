/**
Online Judge : LightOJ
Problem No   : 1164
Problem Name : Horrible Queries
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.249s
Memory       : 5380KB
Algorithm    : Segment Tree (Lazy Propagation)
*/

#include<bits/stdc++.h>

#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define ff first
#define ll long long
#define ss second
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define QI queue<int>
#define SI stack<int>
#define PII pair<int,int>
#define MAX(a,b) max(a,b)
#define MOD 1000000007
#define INF 1<<30
#define mem(a,b) memset((a),(b),sizeof(a))
#define MAX3(a,b,c) max(a,max(b,c))
#define READ_INPUT_FILE() freopen("input.txt","r",stdin)

#define MAX_N (int) 1e5

using namespace std;

struct
{
    ll prop;
    ll sum;
} tree[MAX_N * 3];

void update(int node, int start_node, int end_node, int i, int j, int v)
{
    if(start_node > j || end_node < i)
        return;

    if(start_node >= i && end_node <= j)
    {
        tree[node].prop += v;
        tree[node].sum += (end_node - start_node + 1) * v;
        return;
    }

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (start_node + end_node) >> 1;

    update(left, start_node, mid, i, j, v);
    update(right, mid + 1, end_node, i, j, v);

    tree[node].sum = tree[left].sum + tree[right].sum + (end_node - start_node + 1) * tree[node].prop;
}

ll query(int node, int start_node, int end_node, int i, int j, ll carry = 0)
{
    if(start_node > j || end_node < i)
        return 0;

    if(start_node >= i && end_node <= j)
        return tree[node].sum + (end_node - start_node + 1) * carry;

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (start_node + end_node) >> 1;

    return query(left, start_node, mid, i, j, tree[node].prop + carry) + query(right, mid + 1, end_node, i, j, tree[node].prop + carry);
}

int main()
{
#ifndef ONLINE_JUDGE
    READ_INPUT_FILE();
#endif // ONLINE_JUDGE

    int T, n, q;
    int k, x, y, v;

    while(cin >> T)
    {
        FOR(i, 1, T)
        {
            sc2(n, q);
            FOR(i, 1, n * 3) tree[i].sum = tree[i].prop = 0;

            printf("Case %d:\n", i);

            FOR(j, 1, q)
            {
                sc(k);

                switch(k)
                {
                case 0:
                    scanf("%d %d %d", &x, &y, &v);
                    x++;
                    y++;

                    update(1, 1, n, x, y, v);
                    break;
                case 1:
                    sc2(x, y);
                    x++;
                    y++;

                    printf("%lld\n", query(1, 1, n, x, y));
                    break;
                }
            }
        }
    }

    return 0;
}


