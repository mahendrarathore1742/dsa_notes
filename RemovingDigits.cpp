#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &dp) {

	// if (n == 0) return 0;
	// if (dp[n] != -1) return dp[n];

	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		int temp = i;
		int ans = INT_MAX;
		while (temp != 0) {
			int di = temp % 10;
			temp /= 10;
			if (di == 0) continue;
			ans = min(ans, 1 + dp[i - di]);
		} n
		dp[i] = ans;
	}

	return dp[n];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	cout << helper(n, dp);
}