/**
Online Judge : LightOJ
Problem No   : 1003
Problem Name : Drunk
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.640s
Memory       : 2628KB
Algorithm    : DFS
*/

// Hint: If there is a cycle in the Graph then Topological sorting is not possible.

#include<bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<int> vec[10001];
int visited[10001];
bool cycle = false;

void DFS(int node)
{
    visited[node] = 1;

    for(auto child : vec[node])
    {
        if (visited[child] == 0)
            DFS(child);
        else if (visited[child] == 1)
        {
            cycle = true;
            break;
        }
    }

    visited[node] = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int T, caseNumber = 1, m;
    char a[15], b[15];

    scanf("%d", &T);
    while(caseNumber <= T)
    {
        cycle = false;
        mp.clear();
        fill_n(visited, 10001, 0);
        for(int i = 0; i < 10001; i++) vec[i].clear();

        scanf("%d", &m);

        int idx = 1;
        for(int i = 0; i < m; i++)
        {
            scanf("%s %s", a, b);
            if (mp[a] == 0)
                mp[a] = idx++;
            if (mp[b] == 0)
                mp[b] = idx++;

            vec[mp[a]].push_back(mp[b]);
        }

        for(int i = 1; i < idx; i++)
            if (visited[i] == 0)
                DFS(i);

        printf("Case %d: %s\n", caseNumber++, cycle == true ? "No" : "Yes");
    }

    return 0;
}
