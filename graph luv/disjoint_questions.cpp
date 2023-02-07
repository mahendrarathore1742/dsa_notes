#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int parents[N];
int size[N];
multiset<int> sizes;


void make(int v) {
	parents[v] = v;
	size[v] = 1;
	sizes.insert(1);
}


int find(int v) {
	if (v == parents[v]) return v;
	//path compression
	return parents[v] =  find(parents[v]);
}

void merge(int a, int b) {

	sizes.erase(sizes.find(size[a]));
	sizes.erase(sizes.find(size[b]));

	sizes.insert(size[a] + size[b]);


}


void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {

		//union by size
		if (size[a] < size[b]) {
			swap(a, b);
		}

		parents[b] = a;
		merge(a, b);
		size[a] += size[b];
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		make(i);
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		Union(u, v);


		if (sizes.size() == 1) {
			cout << 0 << endl;
		} else {
			int mn  = *(sizes.begin());
			int mx = *(--sizes.end());
			cout << mx - mn << endl;
		}

	}


	return 0;
}
