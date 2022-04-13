/**
Online Judge : LightOJ
Problem No   : 1135
Problem Name : Count the Multiples of 3
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.281s
Memory       : 3328KB
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
    ll n;
} tree[MAX_N * 3];

void update(int node, int start_index, int end_index, int i, int j, ll carry = 0)
{
    if(start_index > j || end_index < i)
        return;

    if(start_index >= i && end_index <= j)
    {
        tree[node].prop += 1;
        tree[node].n = (tree[node].prop + carry ) % 3 == 0 ? (end_index - start_index) + 1 : 0;

        return;
    }

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (start_index + end_index) >> 1;

    update(left, start_index, mid, i, j, tree[node].prop + carry);
    update(right, mid + 1, end_index, i, j, tree[node].prop + carry);

    tree[node].n = tree[left].n + tree[right].n;
}

ll query(int node, int start_index, int end_index, int i, int j, ll carry = 0)
{
    if(start_index > j || end_index < i)
        return 0;

    if(start_index >= i && end_index <= j)
        return (tree[node].prop + carry) % 3 == 0 ? (end_index - start_index) + 1 : 0;

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (start_index + end_index) >> 1;

    return query(left, start_index, mid, i, j, tree[node].prop + carry) + query(right, mid + 1, end_index, i, j, tree[node].prop + carry);
}

int main()
{
#ifndef ONLINE_JUDGE
    READ_INPUT_FILE();
#endif // ONLINE_JUDGE
    int T, n, q;
    int p, k, m;

    while(cin >> T)
    {
        FOR(i, 1, T)
        {
            sc2(n, q);
            FOR(i, 1, n * 3) tree[i].prop = tree[i].n = 0;

            printf("Case %d:\n", i);

            FOR(j, 1, q)
            {
                scanf("%d %d %d", &p, &k, &m);
                k++;
                m++;

                switch(p)
                {
                case 0:
                    update(1, 1, n, k, m);
                    break;
                case 1:
                    printf("%lld\n", query(1, 1, n, k, m));
                    break;
                }
            }
        }
    }
    return 0;
}

