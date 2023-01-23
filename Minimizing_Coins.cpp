#include <bits/stdc++.h>
using namespace std;


int helper(int n, vector<int> &nums, int sum, vector<vector<int>> &dp) {

	for (int i = 0; i <= sum; ++i)
	{

		if (i % nums[0] == 0 ) dp[0][i] =  i / nums[0];
		else dp[0][i] = 1e9;

	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			int nontake = dp[i - 1][j];
			int take = INT_MAX;

			if (j >= nums[i]) {
				take = 1 + dp[i][j - nums[i]];
			}

			dp[i][j] = min(take, nontake);


		}
	}

	if (dp[n - 1][sum] >= 1e9) return -1;

	return dp[n - 1][sum];

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, sum;
	cin >> n >> sum;

	vector<int> nums(n);

	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	cout << helper(n , nums, sum, dp);


}