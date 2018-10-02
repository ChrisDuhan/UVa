#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int n, m;
	while (cin >> n) {
		bitset<32>numBig(n);
		bitset<32>numSmall;
		for (int i = 0; i < 8; ++i) {
			numSmall[i + 24] = numBig[i];
			numSmall[i + 16] = numBig[i + 8];
			numSmall[i + 8] = numBig[i + 16];
			numSmall[i] = numBig[i + 24];
		}
		m = numSmall.to_ulong();
		cout << n << " converts to " << m << "\n";
	}
	return 0;
}
