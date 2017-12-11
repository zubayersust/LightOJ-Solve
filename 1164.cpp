/**
Online Judge : LightOJ
Problem No   : 1164
Problem Name : Horrible Queries
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.372s
Memory       : 6376KB
Algorithm    : Segment Tree (Lazy Propagation)
*/

#include<bits/stdc++.h>

#define MAX_DATA_ELEMENTS 100000
#define MAX_COMMANDS 50000

using namespace std;

class Data
{
public:
    long long sum;
    long long x;
};

int testCases,caseNumber=1;
int n,c;

Data tree[3*MAX_DATA_ELEMENTS];

void make_segment_tree(int node, int i, int j)
{
    if(i==j)
    {
        tree[node].sum = 0;
        tree[node].x   = 0;
        return;
    }

    int left  = node << 1;
    int right = (node << 1) + 1;
    int mid   = (i + j) >> 1;

    make_segment_tree(left,i,mid);
    make_segment_tree(right,mid+1,j);

    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].x   = 0;
}

void update(int node, int i, int j, int a, int b, long long v)
{
    if(i>b || j<a)
        return;

    if(i>=a && j<=b)
    {
        tree[node].x   += v;
        tree[node].sum += (abs(i - j) + 1) * v;
        return;
    }

    int left  = node << 1;
    int right = (node << 1) + 1;
    int mid   = (i + j) >> 1;

    update(left,i,mid,a,b,v);
    update(right,mid+1,j,a,b,v);

    tree[node].sum = tree[left].sum + tree[right].sum + (abs(i - j) + 1) * tree[node].x;
}

long long query(int node, int i, int j, int p, int q, long long c)
{
    if(i>q || j<p)
        return 0;

    if(i>=p && j<=q)
        return tree[node].sum + (abs(i - j) + 1) * c;

    int left  = node << 1;
    int right = (node << 1) + 1;
    int mid   = (i + j) >> 1;

    long long sum1 = query(left,i,mid,p,q,c+tree[node].x);
    long long sum2 = query(right,mid+1,j,p,q,c+tree[node].x);

    return sum1+sum2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCases);

    while(caseNumber<=testCases)
    {
        scanf("%d %d", &n, &c);

        make_segment_tree(1,1,n);

        int i;
        int k,p,q;
        long long v;
        long long ans;

        printf("Case %d:\n", caseNumber++);

        for(i=0; i<c; i++)
        {
            scanf("%d", &k);

            if(k==0)
            {
                scanf("%d %d %lld", &p, &q, &v);
                update(1,1,n,++p,++q,v);
            }
            else
            {
                scanf("%d %d", &p, &q);
                ans = query(1,1,n,++p,++q,0);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
