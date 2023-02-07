#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;




int dijk(int src, int n, vector<pair<int, int>> graph[]) {

	vector<int> vis(N, 0);
	vector<int> dis(N, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});


	while (!pq.empty()) {

		auto it = pq.top();
		int v = it.second;
		int wt = it.first;
		dis[src] = 0;
		pq.pop();

		if (vis[v]) continue;
		vis[v] = 1;

		for (auto child : graph[v]) {

			int child_v = child.first;
			int child_wt = child.second;

			if (dis[v] + child_wt < dis[child_v]) {

				dis[child_v] = dis[v] + child_wt;
				pq.push({dis[child_v], child_v});
			}
		}
	}


	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (dis[i] == INF) return -1;
		ans = max(ans, dis[i]);
	}

	return ans;
}


int networkDelayTime(vector<vector<int>>& times, int n, int k) {

	vector<pair<int, int>> graph[N]

	for (auto vec : times) {

		graph[vec[0]].push_back({vec[1], vec[2]});

	}

	return dijk(k, n, graph);

}



int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif





}




