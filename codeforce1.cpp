#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void solve(int n, int m) {


	if (n % 2 == 0) {
		cout << n*m - n << endl;
	} else if (m % 2 != 0 && n < m) {

		int mod = m % 10;
		m = m - mod;
		cout << n*m << endl;
	} else if (n > m  && n % 2 == 1 && m % 2 == 1) {
		cout << n*m << endl;
	} else if (n % 2 == 0 && n < m) {

	}
}




int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int t;
	cin >> t;
	while (t) {

		int n, m;
		cin >> n >> m;
		solve(n, m);
		t--;
	}

	return 0;

}
