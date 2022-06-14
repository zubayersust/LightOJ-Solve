/**
Online Judge : LightOJ
Problem No   : 1002
Problem Name : Country Roads
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.205s
Memory       : 1876KB
Algorithm    : MST - Prims Algorithm
*/

#include<bits/stdc++.h>

#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define ff first
#define ll long long
#define ss second
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define QI queue<int>
#define SI stack<int>
#define PII pair<int,int>
#define MAX(a,b) max(a,b)
#define MOD 1000000007
#define INF 1<<30
#define mem(a,b) memset((a),(b),sizeof(a))
#define MAX3(a,b,c) max(a,max(b,c))
#define READ_INPUT_FILE() freopen("input.txt","r",stdin)

using namespace std;

typedef pair<int, int> iPair;

#define MAX_CITY 500
#define MAX_ROAD 16000

class Edge
{
public:
    int u;
    int v;
    int w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    friend bool operator > (const Edge& __x, const Edge& __y)
    {
        return __x.w > __y.w;
    }
};

vector<Edge> V[MAX_CITY];
priority_queue<Edge, vector<Edge>, greater<Edge>> Q;

void PrimMST(int start_node, int n)
{
    vector<int> visited(MAX_CITY, 0);
    visited[start_node] = 1;

    vector<int> parent(MAX_CITY, -1);
    vector<int> weight(MAX_CITY, 0);

    while(!Q.empty())
    {
        Edge edge = Q.top();

        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        Q.pop();

        if (visited[v]) continue;

        visited[v] = 1;
        parent[v] = u;
        weight[v] = w;

        for(auto it = V[v].begin(); it != V[v].end(); it++)
            Q.push(*it);
    }

    for(int idx = 0; idx < n; idx++)
    {
        if (idx == start_node)
            cout << 0 << endl;
        else
        {
            int u = idx;
            int dis = 0;

            while(parent[u] != -1)
            {
                dis = max(dis, weight[u]);
                u = parent[u];
            }

            if (dis == 0)
                cout << "Impossible" << endl;
            else cout << dis << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    READ_INPUT_FILE();
#endif // ONLINE_JUDGE

    int T;
    int n, m;
    int u, v, w;
    int t;

    scanf("%d", &T);

    FOR(i, 1, T)
    {
        scanf("%d %d", &n, &m);

        FOR(k, 1, m)
        {
            scanf("%d %d %d", &u, &v, &w);

            V[u].push_back(Edge(u, v, w));
            V[v].push_back(Edge(v, u, w));
        }

        scanf("%d", &t);

        for(auto it = V[t].begin(); it != V[t].end(); it++)
            Q.push(*it);

        printf("Case %d:\n", i);
        PrimMST(t, n);

        for(int idx = 0; idx < MAX_CITY; idx++) V[idx].clear();

    }

    return 0;
}

