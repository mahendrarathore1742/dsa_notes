#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector < pair<int, int>> graph[N];
vector<int> level(N, INF);

int n, m;

/*

if graph is weightless or (0 or 1) weight so we can use this
0 1 BFS.

(*) graph is weight is 0 or 1 so use this 0-1 BFS
(*) 0 - 1 BFS is implement in deque<int> q;

if low level(0) push into front side and high level(1) push into back side

*/

int BFS_0_1() {

	deque<int> dq;
	dq.push_back(1);
	level[1] = 0;

	while (dq.size() > 0) {

		int node = dq.front();
		dq.pop_front();

		for (auto child : graph[node]) {

			int child_v = child.first;
			int wt = child.second;

			if (level[node] + wt < level[child_v] ) {
				level[child_v] = level[node] + wt;
				if (wt == 1) {
					dq.push_back(child_v);
				} else {
					dq.push_front(child_v);
				}
			}
		}
	}

	return level[n] == INF ? -1 : level[n];
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;

		if (x == y) continue;

		graph[x].push_back({y, 0});
		graph[y].push_back({x, 1});

	}


	cout << BFS_0_1() << endl;



}