#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int Check(long long n) {
	bool digit_seen[10] = { 0 };
	long long digit;

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit])
			return 0;
		digit_seen[digit] = 1;
		n /= 10;
	}
	return 1;
}

int main() {
	const long long limit = 9876543210LL;
	int t;
	long long n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		for (long long j = 1; n*j <= limit; ++j) {
			m = n * j;
			if (Check(m) && Check(j)) {
				cout << m << " / " << j << " = " << n << "\n";
			}
		}
		if (t)
			cout << "\n";
	}
	return 0;
}
