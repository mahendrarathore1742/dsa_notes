#include <bits/stdc++.h>
using namespace std;


int helper(int n, int h, vector<vector<int>> &dp) {

	// if (i == j) return 0;

	// if (dp[i][j] != -1) return dp[i][j];

	// int opt1 = INT_MAX;

	// for (int k = 1; k < i; ++k)
	// {

	// 	opt1 = min(opt1, helper(k, j, dp) + helper(i - k, j, dp) + 1);
	// }

	// int opt2 = INT_MAX;
	// for (int k = 1; k < j; ++k)
	// {
	// 	opt2 = min(opt2, helper(i, k, dp) + helper(i, j - k, dp) + 1);
	// }

	// return dp[i][j] = min(opt1, opt2);


	for (int i = 1; i <= n; ++i)
	{

		for (int j = 1; j <= h; ++j)
		{

			int opt1 = INT_MAX;

			if (i == j) {
				dp[i][j] = 0;
			}

			else {
				for (int k = 1; k < i; ++k)
				{

					opt1 = min(opt1, dp[k][j] + dp[i - k][j] + 1);
				}

				int opt2 = INT_MAX;
				for (int k = 1; k < j; ++k)
				{
					opt2 = min(opt2, dp[i][k] + dp[i][j - k] + 1);
				}

				dp[i][j] = min(opt1, opt2);
			}
		}


	}

	return dp[n][h];



}


int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int n, h;
	cin >> n >> h;


	vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));
	cout << helper(n, h, dp);



	return 0;
}