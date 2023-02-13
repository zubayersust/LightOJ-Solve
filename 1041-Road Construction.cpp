/**
Online Judge : LightOJ
Problem No   : 1041
Problem Name : Road Construction
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 0.000s
CPU          : 0.000s
Memory       : 0KB
Algorithm    :
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

#define MAX_ROADS 50

class Edge
{
    int city1;
    int city2;
    int cost;

public:
    Edge(int city1, int city2, int cost)
    {
        this->city1 = city1;
        this->city2 = city2;
        this->cost = cost;
    }

    friend bool operator < (const Edge &E1, const Edge &E2) return E1.cost < E2.cost;
    friend bool operator > (const Edge &E1, const Edge &E2) return E1.cost > E2.cost;
};

int main()
{
#ifndef ONLINE_JUDGE
    READ_INPUT_FILE();
#endif // ONLINE_JUDGE

    int T, m;

    scanf("%d", &T);
    FOR(i, 1, T)
    {
        scanf("%d", &m);

        int _count = 0;
        map<string, int> road;
        string city1, city2;
        int cost;

        map<string, int>::iterator it;
        FOR(j, 1, m)
        {
            cin >> city1 >> city2 >> cost;

            it = road.find(city1);
            if(it != road.end())
                int city1_num = it->second;
            else
                int city1_num = road[city1] = ++_count;

            it = road.find(city2);
            if(it != road.end())
                int city2_num = it->second;
            else
                int city2_num = road[city2] = ++_count;


        }
    }

    return 0;
}

