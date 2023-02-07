#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// pritn sub tree sum and store in array

vector<int> graph[N];
int subTreeSum[N];
int even_cnt[N];


void pre_computation_dfs(int node, int par) {

	if (node % 2 == 0) even_cnt[node]++;

	subTreeSum[node] += node;

	for (int child : graph[node]) {

		if (child == par) continue;
		pre_computation_dfs(child, node);
		subTreeSum[node] += subTreeSum[child];
		even_cnt[node] += even_cnt[child];

	}

}




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int n ;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;

		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}


	pre_computation_dfs(1, 0);


	for (int i = 1; i < n; ++i)
	{
		cout << "sub Tree sum :- " << subTreeSum[i] << " " << " even count:-  " << even_cnt[i] << endl;
	}

}




