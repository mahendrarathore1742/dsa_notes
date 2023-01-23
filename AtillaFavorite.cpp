#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;



int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	long long int t, n, d;

	string s;

	cin >> t;

	while (t--) {
		cin >> n;
		cin >> s;
		sort(s.begin(), s.end());
		d = s[n - 1] - 'a';
		cout << d + 1 << endl;
	}




	return 0;
}
