#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	string word;
	set<string> words;

	while (cin >> word) {
		string base = "";
		for (int i = 0; i < word.size(); ++i) {
			char c = tolower(word[i]);
			if ((c >= 'a') && (c <= 'z'))
				base += c;
			else if (base != "") {
				words.insert(base);
				base = "";
			}
		}
		if (base != "")
			words.insert(base);
	}
	for (auto iter = words.begin(); iter != words.end(); ++iter)
		cout << *iter << '\n';

	return 0;
}
