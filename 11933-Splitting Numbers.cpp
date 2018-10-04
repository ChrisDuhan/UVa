#include <iostream>
#include <bitset>

using namespace std;

int main() {
	long long num;
	cin >> num;
	while (num != 0) {
		bitset<32> n(num);
		bitset<32> a;
		bitset<32> b;
		bool evenOdd = false; //false for odd, true for even
		for (int i = 0; i < 32; ++i) {
			if (n[i] && !evenOdd) { // if 1 and odd indexed
				a[i] = n[i];
				evenOdd = !evenOdd;
			}
			else if (n[i] && evenOdd) { // if 1 and even indexed
				b[i] = n[i];
				evenOdd = !evenOdd;
			}
			else
				a[i], b[i] = n[i];
		}
		cout << a.to_ullong() << " " << b.to_ullong() << "\n";
		cin >> num;
	}
	return 0;
}
