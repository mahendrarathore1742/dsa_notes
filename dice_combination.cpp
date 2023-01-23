#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

// int helper(int i, vector<int> &dp) {

// 	if (i == 0) return 1;

// 	if (dp[i] != -1) return dp[i];

// 	int take = 0;

// 	for (int x = 1; x <= 6; ++x)
// 	{
// 		if (i - x >= 0) {
// 			take +=  helper(i - x, dp);
// 			take = (take ) % mod;
// 		}

// 	}

// 	return dp[i] = take;

// }


int tabu(int n, vector<int> &dp) {

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {

		int take = 0;

		for (int x = 1; x <= 6; ++x)
		{
			if (i >= x) {
				take +=  dp[i - x];
				take = (take ) % mod;
			}

		}
		dp[i] = take;

	}

	return dp[n];

}




int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif



	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	cout << tabu(n, dp) << endl;




	return 0;

}
