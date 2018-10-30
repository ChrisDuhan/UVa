#include <iostream>
#include <vector>

using namespace std;
const int N = 1000000;

void sieve(vector<int> &primes) {
	primes[0] = primes[1] = 0;
	for (int i = 2; i < N; ++i)
		for (int j = 2; i*j < N; ++j)
			primes[i*j] = 0;
	return;
}

int main() {
	int n;
	vector<int> primes(N, 1);
	sieve(primes);
	cin >> n;
	while (n != 0) {
		int half = n >> 1;
		for (int i = 2; i <= half; i++)
			if (primes[i] && primes[n - i])
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		cin >> n;
	}
	return 0;
}
