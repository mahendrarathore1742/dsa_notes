#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> graph[N];
int pars[N];

void lowest_common_ancestor_dfs(int node, int par) {

	pars[node] = par;
	for (int child : graph[node]) {

		if (child == par) continue;
		lowest_common_ancestor_dfs(child, node);

	}
}

vector<int> path(int node) {

	vector<int> ans;

	while (node != -1) {
		ans.push_back(node);
		node = pars[node];
	}

	reverse(ans.begin(), ans.end());
	return ans;
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

	lowest_common_ancestor_dfs(1, -1);

	int x, y;
	cin >> x >> y;

	vector<int> path_x = path(x);
	vector<int> path_y = path(y);


	int mn_ln = min(path_x.size(), path_y.size());
	int lca = -1;


	for (int i = 0; i < mn_ln; ++i)
	{
		if (path_x[i] == path_y[i]) {
			lca  = path_x[i];
		} else {
			break;
		}
	}


	cout << lca << endl;



	return 0;
}