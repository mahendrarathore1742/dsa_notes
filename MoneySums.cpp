#include <bits/stdc++.h>
using namespace std;



int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	long long n;
	cin >> n;
	vector<int> nums(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	long long mx = 1e5;
	vector<vector<int> > dp(n + 1, vector<int> (mx + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= mx; j++)
		{

			int nontake = dp[i - 1][j];
			int take = 0;
			if (j >= nums[i])
			{
				take = dp[i - 1][j - nums[i]];

			}

			dp[i][j]  = take | nontake;
		}
	}

	vector<int> ans;
	for (int i = 1; i <= mx; i++)
	{
		if (dp[n][i] == 1) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}


	return 0;
}