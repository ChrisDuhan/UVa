#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	bool flag = false; // false for first of pair, true for second of pair
	
	while (getline(cin, s)) {
		for (char c : s) {
			if (c == '"' && !flag) {
				cout << "``";
				flag = !flag;
			}
			else if (c == '"' && flag) {
				cout << "''";
				flag = !flag;
			}
			else
				cout << c;
		}
		cout << "\n";
	}
	return 0;
}
