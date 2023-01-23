#include <bits/stdc++.h>
using namespace std;


// int fun(int i,vector<int> &nums,vector<int> &dp){

// 	if(i==0) return 0;

// 	if(dp[i] !=-1) return dp[i];

// 	int take1 = abs(nums[i] - nums[i-1]) + fun(i-1,nums,dp);
// 	int take2 = INT_MAX;

// 	if(i>1){
// 		 take2 = abs(nums[i] - nums[i-2]) + fun(i-2,nums,dp);
// 	}

// 	return dp[i] = min(take1,take2);
// }

int tabu(int n, vector<int> &nums, vector<int> &dp, int k) {


	for (int i = 1; i <= n; ++i)
	{
		if (i == 0) dp[i] = 0;

		else {

			int cost = INT_MAX;

			for (int j = 1; j <= k; ++j)
			{

				if (i - j >= 0) {
					cost = min(cost, abs(nums[i] - nums[i - j]) + dp[i - j]);
				}
				dp[i] = cost;
			}
		}
	}

	return dp[n];
}

int main()

{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif




	int n;
	int k;

	cin >> n >> k;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> dp(n + 1, 0);
	cout << tabu(n - 1, nums, dp, k) << endl;


}