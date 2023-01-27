#include <bits/stdc++.h>
using namespace std;
int mod = 1e5 + 7;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> diverse[N];

// Marke the prime number.
void sieve() {

	isPrime[0] = isPrime[1] = 1;

	//Sieve Algorithm
	for (int i = 2; i  < N; ++i)
	{
		if (isPrime[i] == true) {
			for (int j = 2 * i; j < N; j += i) {

				isPrime[j] =  false;
			}
		}
	}

	cout << isPrime[17] << endl;
}


//---------------------------------------------------//
vector<bool> isPrime1(N, 1);
vector<int>  lowest_prime(N, 0), highest_prime(N, 0);


// lowest and Highest Prime number
void Lowest_and_Highest_prime_number() {

	isPrime1[0] = isPrime1[1] = 1;

	//Sieve Algorithm
	for (int i = 2; i  < N; ++i)
	{

		if (isPrime1[i] == true) {
			lowest_prime[i] = highest_prime[i] = i;
			for (int j = 2 * i; j < N; j += i) {

				isPrime1[j] =  false;
				highest_prime[j] = i;

				if (lowest_prime[j] == 0) {
					lowest_prime[j] = i;
				}
			}
		}
	}

	// cout << lowest_prime[18] << " " << highest_prime[18] << endl;

	int nums;
	cin >> nums;

	vector<int> prime_factors;

	while (nums > 1) {

		int prime_factor = highest_prime[nums];
		while (nums % prime_factor == 0) {

			nums = nums / prime_factor;
			prime_factors.push_back(prime_factor);
		}
	}

	for (auto i : prime_factors) {
		cout << i << " ";
	}
}



// Similar way we can do with diverse with pre computations

void Pre_diverse() {


	for (int i = 2; i < N; ++i)
	{
		for (int j = i; j < N; j += i)
		{
			diverse[j].push_back(i);
		}
	}

	for (int i = 2; i < 10; ++i)
	{
		for (int x : diverse[i]) {
			cout << x << " ";
		}

		cout << endl;
	}
}


int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	sieve();


	return 0;
}
