#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;


vector<int> graph[N];
int vis[N];
int level[N];


void BFS(int src) {

	queue<int> q;
	q.push(src);
	vis[src]  = 1;

	while (q.size() > 0) {

		int node = q.front();
		q.pop();

		for (int child : graph[node]) {

			if (!vis[child]) {
				vis[child] = 1;
				q.push(child);
				level[child]  = level[node] + 1;
			}
		}
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

	BFS(1);

	for (int i = 1; i <= n; ++i)
	{
		cout << i << " " << level[i] << endl;
	}

}