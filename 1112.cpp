/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.280s
Memory : 3252
*/
/**
Online Judge : LightOJ
Problem No   : 1112
Problem Name : Curious Robin Hood
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.280s
Memory       : 3252KB
Algorithm    : Segment Tree
*/

#include<bits/stdc++.h>

#define MAX_ELEMENTS 100010

using namespace std;

int data[MAX_ELEMENTS];
int tree[MAX_ELEMENTS*3];

int testCase,p=1;

void make_segment_tree(int node, int i, int j)
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

    tree[node] = tree[left] + tree[right];
}

void delete_data(int node, int i, int j, int a, int value)
{
    if(a<i || a>j)
        return;
    if(i==j)
    {
        tree[node] -= value;
        return;
    }

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (i + j) / 2;

    delete_data(left, i, mid, a, value);
    delete_data(right, mid+1, j, a, value);

    tree[node] = tree[left] + tree[right];
}

void add_data(int node, int i, int j, int a, int value)
{
    if(a<i || a>j)
        return;
    if(i==j)
    {
        tree[node] += value;
        return;
    }

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (i + j) / 2;

    add_data(left, i, mid, a, value);
    add_data(right, mid+1, j, a, value);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int i, int j, int a, int b)
{
    if(i>b || j<a)
        return 0;
    if(i>=a && j<=b)
        return tree[node];

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (i + j) / 2;

    int p1 = query(left, i, mid, a, b);
    int p2 = query(right, mid+1, j, a, b);

    return p1 + p2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,q,k,i,j,number,v;

    scanf("%d", &testCase);

    while(p<=testCase)
    {
        scanf("%d %d", &n, &q);

        for(k=1; k<=n; k++)
            scanf("%d", &data[k]);

        make_segment_tree(1,1,n);

        printf("Case %d:\n",p++);

        for(k=1; k<=q; k++)
        {
            scanf("%d", &number);

            if(number == 1)
            {
                scanf("%d", &i);
                i++;

                delete_data(1,1,n,i,data[i]);
                printf("%d\n", data[i]);
                data[i]=0;
            }
            else if(number == 2)
            {
                scanf("%d %d", &i, &v);
                i++;

                add_data(1,1,n,i,v);
                data[i] += v;
            }
            else if(number == 3)
            {
                scanf("%d %d", &i, &j);
                printf("%d\n", query(1,1,n,++i,++j));
            }
        }
    }

    return 0;
}
