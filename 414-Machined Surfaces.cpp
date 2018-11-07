#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string line;

	cin >> n;
	while (n != 0) {
		cin.ignore();
		int sum = 0;
		vector<int> vals(n);
		for (int i = 0; i < n; ++i) {
			getline(cin, line);
			vals[i] = (25 - count(line.begin(), line.end(), 'X'));
		}
		sort(vals.begin(), vals.end());
		for (int i = 1; i < n; ++i) {
			sum += (vals[i] - vals[0]);
		}
		cout << sum << "\n";
		cin >> n;
	}
	return 0;
}
