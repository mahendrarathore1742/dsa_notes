#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void prime() {

	int n;
	cin >> n;
	bool  is_prime = true;

	for (int i = 2; i * i < n; ++i)
	{
		if (n % i == 0) {
			is_prime = false;
			break;
		}
	}

	cout << is_prime << endl;
}


//24 -> 24/2 - 12/2 - 6/2 - 3/3 - 0 [2 2 2 3]
void prime_number_subtract_the_value() {

	int n;
	cin >> n;
	vector<int> prime_factors;

	for (int i = 2; i * i <= n; ++i)
	{
		while (n % i == 0) {
			prime_factors.push_back(i);
			n = n / i;
		}
	}

	if (n > 1) prime_factors.push_back(n);

	for (auto i : prime_factors) {
		cout << i << " ";
	}
}


int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// prime();
	prime_number_subtract_the_value();


	return 0;
}
