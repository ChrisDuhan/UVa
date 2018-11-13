#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		//vector<int> v(n);
		int sum = 0, ans = 0, num;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			sum += num;
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (ans > 0)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
		cin >> n;
	}
	return 0;
}
