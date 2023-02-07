#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int parents[N];
int size[N];

void make(int v) {
	parents[v] = v;
	size[v] = 1;
}

int find(int v) {
	if (v == parents[v]) return v;
	return parents[v]  = find(parents[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (size[a] < size[b]) {
			swap(a, b);
		}

		parents[b] = a;
		size[a] += size[b];
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n, m;
	cin >> n >> m;

	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < m; ++i)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; ++i)
	{
		make(i);
	}


	int total_cost = 0;
	for (auto &edge : edges) {

		int wt = edge.first;
		int u = edge.second.first;
		int v  = edge.second.second;


		if (find(u) == find(v)) continue;
		Union(u, v);

		total_cost += wt;
		cout << u << " " << v << endl;

	}

	cout << total_cost << endl;



	return 0;
}

