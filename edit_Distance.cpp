#include <bits/stdc++.h>
using namespace std;


int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {

	if (i == 0) return j;
	if (j == 0) return  i;

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i - 1] == s2[j - 1]) {
		return helper(i - 1, j - 1, s1, s2, dp);
	}

	int opt1  = helper(i, j - 1, s1, s2, dp);
	int opt2 =  helper(i - 1, j, s1, s2, dp);
	int opt3 = helper(i - 1, j - 1, s1, s2, dp);


	return dp[i][j] = 1 + min({opt1, opt2,  opt3});

}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	int n  = s1.size();
	int m =  s2.size();

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

	cout << helper(n , m, s1, s2, dp);



}