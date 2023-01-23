#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int helper(int i, int j, vector<vector<char>>& nums, int n) {

	// if (i >= 0 && j >= 0 && nums[i][j] == '*') return 0;

	// if (i == 0 && j == 0) return 1;

	// if (i < 0 || j < 0) return 0;

	// if (dp[i][j] != -1) return dp[i][j];

	// int opt1 = helper(i - 1, j, nums, dp);
	// int opt2 = helper(i, j - 1, nums, dp);

	// return dp[i][j] = ( opt1 + opt2) % mod;


	// for (int i = 0; i < n ; ++i)
	// {
	// 	for (int j = 0; j < n ; ++j)
	// 	{
	// 		if (i >= 0 && j >= 0 && nums[i][j] == '*') dp[i][j] =  0;
	// 		else if (i == 0 && j == 0)  dp[i][j] = 1;
	// 		else {

	// 			int opt1 = 0, opt2 = 0;

	// 			if (i > 0) opt1 += dp[i - 1][j];
	// 			if (j > 0)  opt2 = dp[i][j - 1];


	// 			dp[i][j] = ( opt1 + opt2) % mod;
	// 		}
	// 	}

	// }
	// return dp[n - 1][n - 1];

	vector<int> prev(n + 1, -1);

	for (int i = 0; i < n ; ++i)
	{
		vector<int> temp(n + 1, -1);
		for (int j = 0; j < n ; ++j)
		{
			if (i >= 0 && j >= 0 && nums[i][j] == '*') temp[j] =  0;
			else if (i == 0 && j == 0) temp[j] = 1;
			else {

				int opt1 = 0, opt2 = 0;

				if (i > 0) opt1 += prev[j];
				if (j > 0)  opt2 = temp[j - 1];


				temp[j] = ( opt1 + opt2) % mod;
			}

		}
		prev = temp;

	}
	return prev[n - 1];

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<vector<char>> nums(n, vector<char>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> nums[i][j];
		}
	}

	// vector<vector<int>> dp(n, vector<int>(n, 0));
	cout << helper(n - 1, n - 1, nums, n);





}