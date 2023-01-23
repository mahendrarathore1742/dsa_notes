#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
long long m;
long long nums[N];

bool isWoodSufficient(int h) {
	long long wood = 0;

	for (int i = 0; i < n; ++i)
	{

		if (nums[i] >= h) {
			wood += (nums[i] - h);
		}

	}

	return wood >= m;
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	long long start = 0;
	long long end = 1e9;
	long long mid;



	while (end - start > 1) {

		mid = (start + end) / 2;

		if (isWoodSufficient(mid))
		{

			start = mid;

		} else {
			end = mid - 1;
		}
	}


	if (isWoodSufficient(end)) {
		cout << end << endl;
	} else {
		cout << start << endl;
	}



	return 0;
}
