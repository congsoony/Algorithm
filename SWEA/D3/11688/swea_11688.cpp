#include <bits/stdc++.h>
using namespace std;
string s;
void input() {
	cin >> s;
}
void solve() {
	int ldata[100] = { 1 };
	int rdata[100] = { 1 };
	int l = 0;
	int r = 0;
	for (char c : s) {
		if (c == 'L')
			rdata[r + 1] = ldata[l] + rdata[r++];
		else
			ldata[l + 1] = ldata[l++] + rdata[r];
	}
	cout << ldata[l] << " " << rdata[r] << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		input();
		cout << "#" << i << " ";
		solve();
	}
}