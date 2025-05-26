/**
Online Judge : LightOJ
Problem No   : 1041
Problem Name : Road Construction
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.005s
Memory       : 752KB
Algorithm    : MST - Prim's Algorithm
*/

#include<bits/stdc++.h>

using namespace std;

long long MST(vector <vector<pair<int, int>>> &V, int node)
{
	long long result = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<bool> visited(node + 1, false);

	pq.push({0, 1});

	while(!pq.empty()) {
		pair<int, int> next_smallest_node = pq.top();
		pq.pop();

		int _weight = next_smallest_node.first;
		int _node = next_smallest_node.second;

		if(visited[_node] == false) {
			visited[_node] = true;
			result += _weight;

			for(pair<int, int> x : V[_node])
				if(visited[x.second] == false)
					pq.push(x);
		}
	}


	return count(visited.begin() + 1, visited.end(), true) == node ? result : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

	int T;
	int _case = 1;

	scanf("%d", &T);

	while(T--) {
		int n, w, node = 0;
		int node_1, node_2;

		string city1, city2;
		map<string, int> cityMap;

		scanf("%d", &n);

		vector <vector<pair<int, int>>> vc(n * 2 + 1);

		while(n--) {
			cin >> city1 >> city2 >> w;

			if(cityMap[city1] == 0)
				cityMap[city1] = ++node;

			if(cityMap[city2] == 0)
				cityMap[city2] = ++node;

			node_1 = cityMap[city1];
			node_2 = cityMap[city2];

			vc[node_1].push_back({w, node_2});
			vc[node_2].push_back({w, node_1});
		}

		long long result = MST(vc, node);

		if(result == -1)
			printf("Case %d: Impossible\n", _case++);
		else printf("Case %d: %lld\n", _case++, result);
	}

	return 0;
}
