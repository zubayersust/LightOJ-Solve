/**
Online Judge : LightOJ
Problem No   : 1210
Problem Name : Efficient Traffic System
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.138s
Memory       : 1760KB
Algorithm    : Strongly Connected Component
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 20000

int T, caseNumber = 1;
int n, m, a, b;
int visited[MAX_N + 1];
int indeg[MAX_N + 1], outdeg[MAX_N + 1];
vector<int> v[MAX_N + 1];
stack<int> stk;

void reset()
{
    fill_n(visited, MAX_N + 1, 0);
    fill_n(indeg, MAX_N + 1, 0);
    fill_n(outdeg, MAX_N + 1, 0);

    for(int i = 0; i < MAX_N + 1; i++)
        v[i].clear();
}

void DFS(int node)
{
    visited[node] = 1;

    for(auto child : v[node])
        if (visited[child] == 0)
            DFS(child);

    stk.push(node);
}

void DFS2(int node)
{
    visited[node] = 1;

    for(auto child : v[node])
    {
        outdeg[node] = 1;
        indeg[child] = 1;

        if (visited[child] == 0)
            DFS2(child);
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &T);
    while(caseNumber <= T)
    {
        reset();

        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }

        for(int i = 1; i <= n; i++)
            if(visited[i] == 0)
                DFS(i);

        memset(visited, 0, sizeof(visited));
        while(!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            if(visited[node] == 0)
                DFS2(node);
        }

        int total_indeg = 0;
        int total_outdeg = 0;

        for(int i = 1; i <= n; i++)
        {
            if(indeg[i] == 1) total_indeg++;
            if(outdeg[i] == 1) total_outdeg++;
        }

        printf("Case %d: %d\n", caseNumber++, max(n - total_indeg, n - total_outdeg));
    }

    return 0;
}
