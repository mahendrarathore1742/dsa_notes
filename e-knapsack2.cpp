#include <bits/stdc++.h>
using namespace std;



long long helper(int i, int v , vector<int> &val, vector<int> &wt, vector<vector<long long>> &dp) {

	if (v == 0) return 0;

	if (i < 0) return 1e15;



	if (dp[i][v] != -1) return dp[i][v];

	long long ans = helper(i - 1 , v, val, wt, dp);


	if (v - val[i] >= 0)
		ans = min(ans, helper(i - 1, v - val[i], val, wt, dp) + wt[i]);


	return dp[i][v] = ans;

}


int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int n, w;
	cin >> n >> w;

	vector<int> val(105);
	vector<int> wt(105);



	vector<vector<long long>> dp(105, vector<long long>(100005, -1));

	for (int i = 0; i < n; ++i)
	{
		cin >> wt[i] >> val[i];
	}

	int max_val = 1e5;

	for (int i = max_val; i >= 0; --i)
	{
		if (helper(n - 1, i, val, wt, dp) <= w) {
			cout << i << endl;
			break;
		}
	}


	return 0;
}