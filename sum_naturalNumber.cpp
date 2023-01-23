#include <bits/stdc++.h>
using namespace std;


int sum(int n) {

	if (n == 1) return 1;


	return (n + sum(n - 1));

}

int sum1(int n) {

	if (n == 0) return 1;
	if (n == 1) return 1;


	return ( sum1(n - 1) + sum1(n - 2));

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;


	cout << sum1(n) << endl;


}