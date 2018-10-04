#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	while (num != 0) {
		int x, y, a, b;
		cin >> x >> y;
		for (int i = 0; i < num; ++i) {
			cin >> a >> b;
			if (a == x || b == y) {
				cout << "divisa\n";
			}
			else {
				if (b > y)
					cout << "N";
				else
					cout << "S";
				if (a > x)
					cout << "E\n";
				else
					cout << "O\n";
			}
		}
		cin >> num;
	}
	return 0;
}
