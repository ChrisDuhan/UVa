#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<int, int> map;
	int t, n, input;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		int testLen, cnt, longest;
		testLen = cnt = longest = 0;
		map.clear();
		for (int j = 0; j < n; ++j) {
			cin >> input;
			testLen = max(testLen, map[input]);
			map[input] = ++cnt;
			longest = max(longest, cnt - testLen);
		}
		cout << longest << '\n';
	}
	return 0;
}
