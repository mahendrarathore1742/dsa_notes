#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

// if we have multipal source to start point so we can use this BFS for reach the destination.

int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;

vector<pair<int, int>> movements = {
	{0, 1}, {0, -1}, {1, 0}, { -1, 0},
	{1, 1}, {1, -1}, { -1, 1}, { -1, -1}

};

bool  isValid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}


int BFS_Multi_source() {

	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mx = max(mx, val[i][j]);
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mx == val[i][j]) {
				q.push({i, j});
				level[i][j] = 0;
				vis[i][j] = 1;

			}
		}
	}

	int ans = 0;

	while (!q.empty()) {

		auto v = q.front();
		int v_x = v.first;
		int v_y = v.second;
		q.pop();

		for (auto moment : movements) {
			int child_x = moment.first + v_x;
			int child_y = moment.second + v_y;

			if (!isValid(child_x, child_y)) continue;
			if (vis[child_x][child_y]) continue;

			q.push({child_x, child_y});
			level[child_x][child_y] = level[v_x][v_y] + 1;
			vis[child_x][child_y] = 1;
			ans = max(ans, level[child_x][child_y]);
		}
	}

	return ans;
}


void reset() {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vis[i][j] = 0;
			level[i][j] = INF;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int t;
	cin >> t;

	while (t--) {

		cin >> n >> m;
		reset();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> val[i][j];
			}
		}

		cout << BFS_Multi_source() << endl;
	}


}