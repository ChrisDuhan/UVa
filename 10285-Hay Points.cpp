#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int m, n, dollarVal;
	string keyWord, word;
	map<string, int> dict;
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		cin >> keyWord >> dollarVal;
		dict[keyWord] = dollarVal;
	}
	while (cin >> word) {
		int total = 0;
		while (word != ".") {
			if (dict.find(word) != dict.end())
				total += dict[word];
			cin >> word;
		}
		cout << total << '\n';
	}
	return 0;
}
