/**
Online Judge : LightOJ
Problem No   : 1026
Problem Name : Critical Links
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.338s
Memory       : 5224KB
Algorithm    : Articulation Point/Bridge
*/

#include<bits/stdc++.h>

#define MAX_NODE 10005

using namespace std;

int testCases,caseNumber=1;
int n,u,k,v,tim=0;
int low[MAX_NODE],dis[MAX_NODE],parent[MAX_NODE];
bool visited[MAX_NODE];

vector<int> vec[MAX_NODE];

class Link
{
public:
    int u;
    int v;

    Link(int u, int v)
    {
        this->u=u;
        this->v=v;
    }

    bool operator< (const Link& link)
    const
    {
        if(u == link.u)
            return v > link.v;
        return u > link.u;
    }
};

priority_queue<Link> Q;

void reset()
{
    int i;

    for(i=0; i<MAX_NODE; i++)
    {
        visited[i] =false;
        low[i]     =0;
        parent[i]  =-1;

        vec[i].clear();
    }

    tim=0;
}

void DFS(int root)
{
    int i,v,child=0;

    visited[root]=true;
    low[root]=dis[root]=++tim;

    while(!vec[root].empty())
    {
        v= *vec[root].begin();
        vec[root].erase(vec[root].begin());

        if(visited[v] == false)
        {
            child++;
            parent[v]=root;

            DFS(v);

            low[root] = min(low[root], low[v]);

            if(dis[root] < low[v])
            {
                int temp1=root,temp2=v;
                if(root > v)
                    swap(temp1,temp2);
                Link link(temp1, temp2);
                Q.push(link);
            }

        }
        else if (parent[root] != v)
            low[root] = min(low[root], dis[v]);
    }
}

void printResult()
{
    int len=Q.size();
    printf("Case %d:\n%d critical links\n",caseNumber++,len);

    while(!Q.empty())
    {
        Link link = Q.top();

        printf("%d - %d\n",link.u, link.v);

        Q.pop();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    char num[20];

    scanf("%d", &testCases);

    while(caseNumber <= testCases)
    {
        scanf("%d", &n);

        reset();

        int i,j;

        for(i=0; i<n; i++)
        {
            scanf("%d %s", &u, num);

            k = atoi(&num[1]);

            while(k--)
            {
                scanf("%d", &v);
                vec[u].push_back(v);
                vec[v].push_back(u);
            }
        }

        for(j=0; j<n; j++)
            if(!visited[j])
                DFS(j);

        printResult();
    }

    return 0;
}
