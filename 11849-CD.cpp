#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m;
	while (!(n == 0 && m == 0)) {
		set<int> cds;
		for (int i = 0; i < n + m; ++i) {
			cin >> x;
			cds.insert(x);
		}
		cout << (n + m) - cds.size()<< "\n";
		cin >> n >> m;
	}
	return 0;
}
