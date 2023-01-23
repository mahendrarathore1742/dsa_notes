#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void solve(vector<int> nums) {



	sort(nums.begin(), nums.end());


	cout << nums[1] << endl;

}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int t;
	cin >> t;
	while (t--) {

		vector<int> nums(3);

		for (int i = 0; i < 3; ++i)
		{
			cin >> nums[i];

		}
		solve(nums);


	}

	return 0;
}
