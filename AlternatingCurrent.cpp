#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void solve() {

	char ch;

	stack<char> st;

	while (cin >> ch) {

		if (st.empty() || st.top() != ch) {

			st.push(ch);
		} else if (st.top() == ch) {
			st.pop();

		}
	}

	if (st.empty()) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif




	solve();

	return 0;



}
