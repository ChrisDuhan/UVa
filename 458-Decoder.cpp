#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		for (auto c : s) {
			cout << char(c - 7);
		}
		cout << endl;
	}
	return 0;
}
