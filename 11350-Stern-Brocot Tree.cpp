#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<long long, long long> ii;

ii SBT(ii left, ii right, string& path) {
	ii mediant(left.first + right.first, left.second + right.second);
	if (!path.empty()) {
		if (path[0] == 'L') {
			path = path.substr(1);
			mediant = SBT(left, mediant, path);
		}
		else {
			path = path.substr(1);
			mediant = SBT(mediant, right, path);
		}
	}
	return mediant;
}

int main() {
	int n;
	string path;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> path;
		ii left(0, 1);
		ii right(1, 0);
		ii med;
		med = SBT(left, right, path);
		cout << med.first << '/' << med.second << "\n";
	}
	return 0;
}
