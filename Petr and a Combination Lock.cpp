#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int helper(vector<int> &nums, int n) {

	bool flag = 0;

	for (int i = 0; i < (1 << n)  ; ++i)
	{
		int sum = 0;

		for (int bit = 0; bit < n ; ++bit)
		{
			if (i & 1 << bit) {
				sum += nums[bit];
			} else {
				sum -= nums[bit];
			}
		}
		if (sum % 360 == 0) { flag = 1; break;}
	}

	return flag;


}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	if (helper(nums, n)) {
		cout << "YES";
	} else {
		cout << "No";
	}


	return 0;


}