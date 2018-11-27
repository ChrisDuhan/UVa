#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
				if (s[k] - 48 == 0)
					v[j][k] = -625;
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
		int maxSub = 0;
		for (int subRow = 0; subRow < size; ++subRow) {
			for (int subCol = 0; subCol < size; ++subCol) {
				for (int endRow = subRow; endRow < size; ++endRow) {
					for (int endCol = subCol; endCol < size; ++endCol) {
						int currentSub = v[endRow][endCol];
						if (subRow > 0) // only do when not in a cell in the first row
							currentSub -= v[subRow - 1][endCol];
						if (subCol > 0) // only do when not in a cell in the first column
							currentSub -= v[endRow][subCol - 1];
						if (subRow > 0 && subCol > 0) // do for every cell not in the first row or column
							currentSub += v[subRow - 1][subCol - 1];
						maxSub = max(maxSub, currentSub);
					}
				}
			}
		}

		cout << maxSub << "\n";
		if (i != n - 1)
			cout << "\n";

		// uncomment below for visualizing
		/*
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				cout << v[j][k] << " ";
			}
			cout << '\n';
		}
		*/

	}
	return 0;
}
