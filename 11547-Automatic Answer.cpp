#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		n = (n * 315 + 36962);
		string s = to_string(n);
		cout << s[s.size() - 2] << "\n";
	}
	return 0;
}
