#include <bits/stdc++.h>
using namespace std;


// # ----- if value is even ------- #
/*

2 ^ 16 -> 2 ^ 8 * 2 ^ 8

2 ^ 8 -> 2 ^ 4 * 2 ^ 4

2 ^ 4 -> 2 ^ 2 * 2 ^ 2

2 ^ 2 -> 2 ^ 1 * 2 ^ 1


# ---------------------------------- #
f(a,b) - > f(a,b/2) * f(a,b/2)
# ---------------------------------- #

*/


// # ----- if value is odd ------- #
/*

3 ^ 13 -> 13 * 3^12

3^12 - > 3 ^ 6 * 3 ^ 6

3^6 - > 3 ^ 3 * 3 ^ 3

3^3 - > 3 * 3 ^ 2

3^2 - > 3 ^ 1 * 3 ^ 1

3 ^ 1 -> 3 * 3 ^ 0

# ---------------------------------- #
f(a,b) - > a *  f(a,b/2) * f(a,b/2)
# ---------------------------------- #

*/

int binary_expo_recur(int a, int b) {

	if (b == 0) return 1;

	//for time saving tecq
	long long res  = binary_expo_recur(a, b / 2);


	// if b is odd number
	if (b & 1) {
		return  a * res * res;
	}

	// if b is even is even number
	else {
		return res * res;
	}
}



// -------------------------------------------//
/*
				  13
				  |
				  V
	3^13 -> 3 ^ (1101)

------------------------------------------
	b 		a(a *= a)		ans( ans * a)

	1101		3 		  		3

	110     	3^2       		3

	11      	3^4       		3 ^ 5

	1       	3^8       		3 ^ 13



*/


int binary_expo_fast_using_bit(long long a, long long b) {

	int ans = 1;
	while (b) {

		//if bit is set so its contributing  in the ans
		if (b & 1) {
			ans =  ans * a;
		}

		// if bit is uset so it not contributing in ans
		a *= a;
		b = b >> 1;
	}

	return ans;

}


int main()

{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int a, b;
	cin >> a >> b;

	cout << binary_expo_fast_using_bit(a, b);



	return 0;
}