#include <bits/stdc++.h>
using namespace std;


void printbinary(int nums) {
	for (int i = 10; i >= 0; --i)
	{
		cout << ((nums >> i) & 1) << " ";
	}
}



int main() {

	printbinary(5);

}