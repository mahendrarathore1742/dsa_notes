#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> graph[N];
int height[N], depth[N];


//should not be containe cycle. and can remove vis array only for tree graph

void dfs_height_and_depth(int node, int par) {


	for (int child : graph[node]) {

		if (child == par) continue;

		//coming from upper side
		depth[child] = depth[node] + 1;

		dfs_height_and_depth(child, node);

		//coming from buttom side
		height[node] = max(height[node], height[child] + 1);

	}

}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif


	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;

		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs_height_and_depth(1, 0);

	for (int i = 1; i <= n; ++i)
	{
		cout << "height :- " << height[i] << " " << " depth:- " << depth[i] << endl;
	}



}