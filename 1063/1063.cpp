/**
Online Judge : LightOJ
Problem No   : 1063
Problem Name : Ant Hills
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.045s
Memory       : 1928KB
Algorithm    : Articulation Point/Bridge
*/

#include<bits/stdc++.h>

#define MAX_NODE 10000

using namespace std;

int dis[MAX_NODE+1],low[MAX_NODE+1],parent[MAX_NODE+1],discover_time=0,root=0;;
bool visited[MAX_NODE+1];
vector<int> tracks[MAX_NODE+1];
set<int> points;

void reset()
{
    for(int i=1; i<MAX_NODE+1; i++)
    {
        dis[i]=low[i]=0;
        parent[i]=-1;
        visited[i]=false;

        tracks[i].clear();
    }

    discover_time=0;
    root=0;
    points.clear();
}

void DFS(int u)
{
    dis[u]=low[u]=++discover_time;
    visited[u]=true;

    int child=0,v;

    while(!tracks[u].empty())
    {
        v=*tracks[u].begin();
        tracks[u].erase(tracks[u].begin());

        if(visited[v]==false)
        {
            child++;
            parent[v]=u;

            DFS(v);

            low[u]=min(low[u], low[v]);

            if(dis[u] <= low[v] && u!=root)
                points.insert(u);
        }
        else if(parent[u]!=v)
            low[u]=min(low[u], dis[v]);
    }

    if(u==root && child>1)
        points.insert(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int T, testCase=1;
    int n, m;
    int a, b;
    int result;

    scanf("%d", &T);

    while(testCase<=T)
    {
        reset();

        scanf("%d %d", &n, &m);

        for (int i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);

            tracks[a].push_back(b);
            tracks[b].push_back(a);

            if (root==0)
                root=a;
        }

        DFS(root);
        printf("Case %d: %zu\n", testCase, points.size());

        testCase++;
    }

    return 0;
}
