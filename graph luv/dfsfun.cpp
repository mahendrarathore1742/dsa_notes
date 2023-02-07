#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;


vector<int> g[N];
int vis[N];

void dfs(int node) {


	for (int it : g[node]) {

		if (!vis[it]) {
			vis[node] = 1;
			dfs(it);
		}
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 9; ++i)
	{

		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	dfs(1);

}
