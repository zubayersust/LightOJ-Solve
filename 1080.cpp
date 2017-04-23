/**
Author    : Zubayer Rahman
Email     : zubayer.csesust@gmail.com
CPU       : 0.440s
Memory    : 2956KB
Algorithm : Segment Tree (Lazy Propagation)
*/

#include<bits/stdc++.h>

#define MAX_STRING_LENGTH 100000
#define MAX_QUERIES 50000

using namespace std;

int testCases,caseNumber=1;
int n,q;

char str[MAX_STRING_LENGTH+5];
int tree[3*MAX_STRING_LENGTH+5];

void update(int node, int i, int j, int a, int b)
{
    if(i>b || j<a)
        return;

    if(i>=a && j<=b)
    {
        tree[node]++;
        return;
    }

    int left  = node << 1;
    int right = (node << 1) + 1;
    int mid   = (i + j) >> 1;

    update(left,i,mid,a,b);
    update(right,mid+1,j,a,b);
}

int query(int node, int i, int j, int idx, int carry)
{
    if(i>idx || j<idx)
        return 0;

    if(i==idx && j==idx)
        return tree[node]+carry;

    int left  = node << 1;
    int right = (node << 1) + 1;
    int mid   = (i + j) >> 1;

    int result1 = query(left,i,mid,idx,carry+tree[node]);
    int result2 = query(right,mid+1,j,idx,carry+tree[node]);

    return result1+result2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCases);

    while(caseNumber<=testCases)
    {
        memset(tree, 0, sizeof(tree));

        scanf("%s", str);

        n = strlen(str);

        scanf("%d", &q);

        int i;
        char ch;
        int a,b;
        int ans;

        printf("Case %d:\n", caseNumber++);

        for(i=0; i<q; i++)
        {
            getchar();
            scanf("%c", &ch);

            switch(ch)
            {
            case 'I':
                scanf("%d %d", &a,&b);
                update(1,1,n,a,b);
                break;
            case 'Q':
                scanf("%d", &a);
                ans = query(1,1,n,a,0);

                if(ans%2==0)
                    printf("%c\n", str[a-1]);
                else
                {
                    if(str[a-1]=='0')
                        printf("1\n");
                    else printf("0\n");
                }
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
