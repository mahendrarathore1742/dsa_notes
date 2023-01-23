#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int helper(vector<int> &nums, int sum, vector<long> &dp) {


	if (sum == 0) return 1;
	if (sum < 0) return 0;

	if (dp[sum] != -1) return dp[sum];


	long ans = 0;
	for (unsigned i = 0; i < nums.size(); ++i)
	{
		if (sum >= nums[i]) {

			ans += helper(nums, sum - nums[i], dp);
		}
	}

	return dp[sum] = ans % mod;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, sum;
	cin >> n >> sum;

	vector<int> nums(n);

	vector<long> dp(sum + 1, -1);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	cout << helper(nums, sum, dp);


}