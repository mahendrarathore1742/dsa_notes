#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int helper(int n, vector<int> &nums, int sum, vector<vector<int>> &dp) {

	// if (i == 0) {
	// 	return (sum % nums[0] == 0);
	// }



	// if (dp[i][sum] != -1)  return dp[i][sum];
	// int nontake = helper(i - 1, nums, sum, dp);

	// int take = 0;
	// if (nums[i] <= sum  ) {
	// 	take =  helper(i, nums, sum - nums[i], dp);
	// }

	// return dp[i][sum] = (take + nontake) % mod;


	for (int i = 0; i <= sum; ++i)
	{
		dp[0][i] = (i % nums[0] == 0);
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			int nontake = dp[i - 1][j];

			int take = 0;
			if (nums[i] <= j  ) {
				take =  dp[i][j - nums[i]];
			}

			dp[i][j] = (take + nontake) % mod;
		}
	}

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

	cout << helper(n  , nums, sum, dp);


}