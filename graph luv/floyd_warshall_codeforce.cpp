#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int INF = 1e9 + 10;

long long dis[N][N];


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j) {
			cin >> dis[i][j];
		}
	}

	vector<int> dele_order(n);

	for (int i = 0; i < n; ++i) {
		cin >> dele_order[i];
	}

	reverse(dele_order.begin(), dele_order.end());
	vector<long long> ans;

	for (int k = 0; k < n; ++k)
	{
		int k_v = dele_order[k];

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				long long new_dist = dis[i][k_v] + dis[k_v][j];
				dis[i][j] = min(dis[i][j], new_dist);
			}
		}


		long long sum = 0;
		for (int i = 0; i <= k; ++i)
		{
			for (int j = 0; j <= k; ++j) {

				sum += dis[dele_order[i]][dele_order[j]];

			}
		}
		ans.push_back(sum);

	}

	reverse(ans.begin(), ans.end());

	for (auto i : ans) {
		cout << i << " ";
	}

	cout << endl;



}