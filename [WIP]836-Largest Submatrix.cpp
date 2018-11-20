#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int size = s.size();
		vector<vector<int>> v(size, vector<int>(size));
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				v[j][k] = s[k] - 48;
			}
			if (j != (size - 1)) {
				cin >> s;
			}
		}
		for (int j = 1; j < size; ++j) {
			v[0][j] += v[0][j - 1];
			v[j][0] += v[j - 1][0];
		}
		for (int j = 1; j < size; ++j) {
			for (int k = 1; k < size; ++k) {
				// the cell plus upper and left neighbors, minus upper-left neighbor
				v[j][k] = v[j][k] + v[j][k - 1] + v[j - 1][k] - v[j - 1][k - 1];
			}
		}
		int r = 0, c = 0;
		for (int mr = 1; mr < size; ++mr) {
			for (int mc = 1; mc < size; ++mc) {
				while (mr + r < size) {
					while (mc + c < size) {


						++mc;
					}
					++mr;
				}

			}
		}




		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				cout << v[j][k] << " ";
			}
			cout << '\n';
		}
		




	}
	return 0;
}
