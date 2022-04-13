/**
Online Judge : LightOJ
Problem No   : 1112
Problem Name : Binary Simulation
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.281s
Memory       : 3328KB
Algorithm    : Segment Tree
*/

#include<bits/stdc++.h>

#define MAX_N (int) 1e5

using namespace std;

int inp[MAX_N+1];
long long tree[MAX_N*3];

void init(int node, int start_index, int end_index)
{
    if(start_index==end_index)
    {
        tree[node] = inp[start_index];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (start_index+end_index)/2;

    init(left, start_index, mid);
    init(right, mid+1, end_index);

    tree[node] = tree[left]+tree[right];
}

void update(int node, int start_index, int end_index, int i, int v)
{

    if(i>end_index || i<start_index)
        return;

    if(start_index>=i && end_index<=i)
    {
        tree[node] = v == 0 ? 0:tree[node] + v;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (start_index+end_index)/2;

    update(left, start_index, mid, i, v);
    update(right, mid+1, end_index, i, v);

    tree[node] = tree[left] + tree[right];
}

long long query(int node, int start_index, int end_index, int i, int j)
{
    if(i>end_index || j<start_index)
        return 0;

    if(start_index>=i && end_index<=j)
        return tree[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (start_index+end_index)/2;

    return query(left, start_index, mid, i, j) + query(right, mid+1, end_index, i, j);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int testCase, t=1, n, q;

    scanf("%d", &testCase);

    while(t<=testCase)
    {
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++)
            scanf("%d", &inp[i]);

        init(1, 1, n);

        printf("Case %d:\n", t);
        t++;

        for(int i=0; i<q; i++)
        {
            int d, x, v, k, m;
            long long ans;

            scanf("%d", &d);

            switch(d)
            {
            case 1:
                scanf("%d", &x);
                x++;

                ans = query(1, 1, n, x, x);
                printf("%lld\n", ans);

                update(1, 1, n, x, 0);
                break;
            case 2:
                scanf("%d %d", &x, &v);
                x++;

                update(1, 1, n, x, v);
                break;
            case 3:
                scanf("%d %d", &k, &m);
                k++;
                m++;

                printf("%lld\n", query(1, 1, n, k, m));
                break;
            }
        }
    }

    return 0;
}

