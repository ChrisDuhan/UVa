#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num, den;
	while (cin >> num >> den) {
		cout << '[';
		vector<int> s;
		while (num % den) {
			s.push_back(num / den);
			int tmp = num;
			num = den;
			den = tmp % den;
		}
		s.push_back(num / den);
		cout << s[0];
		for (int i = 1; i < s.size(); ++i) {
			if (i == 1)	
				cout << ';';
			else
				cout << ',';
			cout << s[i];
		}
		cout << "]\n";
	}
	return 0;
}
