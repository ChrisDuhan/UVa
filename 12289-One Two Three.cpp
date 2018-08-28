#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	string num;
	string one = "one";
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> num;
		if (num.length() == 5)cout << 3 << endl;
		else {
			int c = 0;
			for (int j = 0; j < 3; ++j)
				if (one[j] == num[j])++c;
			if (c >= 2)cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	return 0;
}
