/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.024s
Memory : 2752
*/


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_HILL 10005

using namespace std;

int testCase,caseNum=1,n,m,tim=0;
int low[MAX_HILL],dis[MAX_HILL],parent[MAX_HILL];
bool visited[MAX_HILL],ap[MAX_HILL];

vector<int> vec[MAX_HILL];

void reset()
{
    int i;

    for(i=1; i<=MAX_HILL; i++)
    {
        visited[i]=ap[i]=false;
        low[i]=0;
        parent[i]=-1;
        vec[i].clear();
    }
    tim=0;
}

void DFS(int root)
{
    int v;

    visited[root]=true;
    low[root]=dis[root]=++tim;

    int i;
    int child=0;

    for(i=0; i<vec[root].size(); i++)
    {
        v=vec[root][i];

        if(visited[v] == false)
        {
            child++;
            parent[v]=root;

            DFS(v);

            low[root] = min(low[root], low[v]);

            if(parent[root] != -1 && dis[root] <= low[v])
                ap[root] = true;
            if(parent[root] == -1 && child > 1)
                ap[root] = true;
        }
        else if(parent[root] != v)
            low[root] = min(low[root], dis[v]);
    }
}

void printResult()
{
    printf("Case %d: ",caseNum++);

    int result=0;
    int i;

    for(i=1; i<=n; i++)
        if(ap[i] == true)
            result++;

    printf("%d\n", result);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(caseNum <= testCase)
    {
        scanf("%d %d", &n, &m);

        reset();

        int i,u,v;

        for(i=0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        DFS(1);
        printResult();
    }
    return 0;
}
