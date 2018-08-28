#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t = 0, s = 0, num = 0;
	vector<int> speeds;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> s;
		for (int j = 0; j < s; ++j) {
			cin >> num;
			speeds.push_back(num);
		}
		sort(speeds.begin(), speeds.end());
		cout << "Case " << i + 1 << ": " << speeds.back() << endl;
		speeds.clear();
	}
	return 0;
}
