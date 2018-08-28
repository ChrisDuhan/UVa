#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t = 0;
	vector<int> salaries(3);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> salaries[0] >> salaries[1] >> salaries[2];
		sort(salaries.begin(), salaries.end());
		cout << "Case " << i + 1 << ": " << salaries[1] << endl;
	}
	return 0;
}
