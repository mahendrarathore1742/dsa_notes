#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;

void solve() {


	vector<int> ans(3);

	for (int i = 0; i < 3; ++i)
	{
		cin >> ans[i];
	}

	if ((ans[0]) % 2 == 0) {
		cout << ans[0] / ans[1] << endl;
	} else {
		cout << ans[0] / ans[1] + 1 << endl;
	}

}



int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
