#include <bits/stdc++.h>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, w;
	cin >> n >> w;


	vector<int> val(n);
	vector<int> wt(n);

	for (int&v : val) cin >> v;
	for (int&v : wt) cin >> v;

	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= w; ++j)
		{
			int nontake = dp[i - 1][j];
			int take = 0;

			int left = j - val[i - 1];
			if (left >= 0) {
				take = wt[i - 1] + dp[i - 1][left];
			}

			dp[i][j] = max(take, nontake);
		}

	}

	cout << dp[n][w];


}