/**
Online Judge : LightOJ
Problem No   : 1082
Problem Name : Array Queries
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.230s
Memory       : 2044KB
Algorithm    : Segment Tree
*/

#include<bits/stdc++.h>

#define MAX_ELEMENTS 100010

using namespace std;

int testCase,p=1;
int data[MAX_ELEMENTS];
int tree[MAX_ELEMENTS*3];

void make_segment_tree(int node,int i, int j)
{
    if(i==j)
    {
        tree[node] = data[i];
        return;
    }

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (i + j) / 2;

    make_segment_tree(left, i, mid);
    make_segment_tree(right, mid+1, j);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int i, int j, int a, int b)
{
    if(a>j || b<i)
        return MAX_ELEMENTS;
    if(i>=a && j<=b)
        return tree[node];

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (i + j) / 2;

    int p1 = query(left, i, mid, a, b);
    int p2 = query(right, mid+1, j, a, b);

    return min(p1, p2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,q,k,i,a,b;

    scanf("%d", &testCase);

    while(p<=testCase)
    {
        scanf("%d %d", &n, &q);

        for(i=1; i<=n; i++)
            scanf("%d", &data[i]);

        make_segment_tree(1,1,n);

        printf("Case %d:\n", p++);

        for(i=1; i<=q; i++)
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", query(1,1,n,a,b));
        }
    }
    return 0;
}
