#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll> , greater<ll>> min_heap;
typedef priority_queue<ll> max_heap;
#define pb        push_back
#define f  first
#define s  second




void  solve() {


	ll a, b, c;

	cin >> a >> b >> c;

	ll k = 0;

	cout << max(k, max(b, c) + 1 - a) << " ";
	cout << max(k, max(a, c) + 1 - b) << " ";
	cout << max(k, max(a, b) + 1 - c) << endl;


}


int main()

{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	ll  t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}