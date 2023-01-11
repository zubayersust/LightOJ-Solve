/**
Online Judge : LightOJ
Problem No   : 1003
Problem Name : Drunk
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.580s
Memory       : 2176KB
Algorithm    : Topological Sort
*/

#include<bits/stdc++.h>

using namespace std;

map<string, int> mp;
int vs[10001];
vector<int> v[10001];
queue<int> q;

void reset(int k)
{
    mp.clear();
    int i, j;
    for(i = 0; i < k; i++)
    {
        vs[i] = 0;
        v[i].clear();
    }
    while(!q.empty())
        q.pop();
}

void find_zero(int m[], int n)
{
    int i;
    for(i = 1; i < n; i++)
        if(m[i] == 0)
            q.push(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int t, p = 1, n, i, c, d, f, g, h, temp;
    char a[15], b[15];

    scanf("%d", &t);
    while(p <= t)
    {
        scanf("%d", &n);
        getchar();
        temp = 1;
        for(i = 0; i < n; i++)
        {
            scanf("%s %s", a, b);
            if(mp[a] == 0)
                mp[a] = temp++;
            if(mp[b] == 0)
                mp[b] = temp++;
            c = mp[a];
            d = mp[b];
            vs[d]++;
            v[c].push_back(d);
        }
        find_zero(vs, temp);

        if(q.empty())
        {
            printf("Case %d: No\n", p++);
            reset(temp);
            continue;
        }

        h = 0;

        while(!q.empty())
        {
            g = q.front();
            q.pop();
            h++;
            for(i = 0; i < v[g].size(); i++)
            {
                f = v[g][i];
                vs[f]--;
                if(vs[f] == 0)
                    q.push(f);
            }

        }
        if(h == temp - 1)
            printf("Case %d: Yes\n", p++);
        else printf("Case %d: No\n", p++);

        reset(temp);
    }
    return 0;
}
