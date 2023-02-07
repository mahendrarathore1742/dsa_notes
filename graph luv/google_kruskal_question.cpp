#include <bits/stdc++.h>

using namespace  std;
const int N = 2e3 + 10;

int parents[N];
int size[N];

void make(int  v) {
	parents[v] = v;
	size[v] = 1;
}

int find(int v) {
	if (v == parents[v])  return v;
	return parents[v] = find(parents[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);

		parents[b] = a;
		size[a] += size[b];
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n;
	cin >> n;
	vector<pair<int, int>> cities(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> cities[i].first >> cities[i].second;
	}

	vector<int> c(n + 1), k(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
	}


	vector<pair<long long, pair<int, int>>> edges;

	for (int i = 1; i <= n; ++i)
	{
		edges.push_back({c[i], {0, i}});
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			int dist = abs(cities[i].first - cities[j].first) +  abs(cities[i].second - cities[j].second);
			long long  cost = dist * 1LL * (k[i] + k[j]);
			edges.push_back({cost, {i, j}});
		}
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; ++i)
	{
		make(i);
	}

	long long total_cost = 0;
	vector<int> power_station;
	vector <pair<int, int>> connections;

	for (auto &edge : edges) {

		int wt = edge.first;
		int u = edge.second.first;
		int v  = edge.second.second;


		if (find(u) == find(v)) continue;
		Union(u, v);

		total_cost += wt;

		if (u == 0 || v == 0) {
			power_station.push_back(max(u, v));
		} else {
			connections.push_back({u, v});
		}


	}

	cout << total_cost << endl;

	cout << power_station.size() << endl;
	for (auto &i : power_station) {
		cout << i << " ";
	}
	cout << endl;

	cout << connections.size() << endl;

	for (auto &i : connections) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}