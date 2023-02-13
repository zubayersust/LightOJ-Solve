/**
Online Judge : LightOJ
Problem No   : 1034
Problem Name : Hit the Light Switches
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.138s
Memory       : 1760KB
Algorithm    : DFS
*/

// Hint: Number of SCC in the Graph is the result.

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 10000

int T, caseNumber = 1;
int N, M, a, b;
int visited[MAX_N + 1];
vector<int> v[MAX_N + 1];
stack<int> stk;

void DFS(int node)
{
    visited[node] = 1;

    for(auto child : v[node])
        if (visited[child] == 0)
            DFS(child);

    visited[node] = 2;
    stk.push(node);
}

void DFS2(int node)
{
    visited[node] = 1;

    for(auto child : v[node])
        if (visited[child] == 0)
            DFS2(child);

    visited[node] = 2;
}

void reset()
{
    fill_n(visited, MAX_N + 1, 0);
    for(int idx = 0; idx < MAX_N + 1; idx++)
        v[idx].clear();
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

        scanf("%d %d", &N, &M);

        int result = 0;
        if (M == 0)
            result = N;
        else
        {
            for(int idx = 0; idx < M; idx++)
            {
                scanf("%d %d", &a, &b);
                v[a].push_back(b);
            }

            for(size_t i = 1; i <= N; i++)
                if(visited[i] == 0)
                    DFS(i);

            fill_n(visited, MAX_N + 1, 0);

            while(!stk.empty())
            {
                int node = stk.top();
                stk.pop();

                if(visited[node] == 0)
                {
                    result++;
                    DFS2(node);
                }
            }
        }

        printf("Case %d: %d\n", caseNumber++, result);
    }

    return 0;
}
