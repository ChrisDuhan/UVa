#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> vs;
typedef vector<vector<int>> vvi;

int main() {
	string s;
	while (cin >> s) {
		vs vec1;
		vs vec2;
		vec1.push_back("-");
		vec1.push_back(s);
		vec2.push_back("-");
		while (cin >> s && s != "#")
			vec1.push_back(s);
		while (cin >> s && s != "#")
			vec2.push_back(s);
		vvi M(vec1.size(), vector<int>(vec2.size()));
		for (int i = 1; i < vec2.size(); ++i)
			for (int j = 1; j < vec1.size(); ++j) {
				if (vec1[j] == vec2[i])
					M[j][i] = 1 + M[j - 1][i - 1];
				else
					M[j][i] = max(M[j][i - 1], M[j - 1][i]);
			}
		int i = vec2.size() - 1, j = vec1.size() - 1;
		string output = "";
		while (M[j][i] != 0) {
			if (M[j][i] == M[j - 1][i]) // move left
				j -= 1;
			else if (M[j][i] == M[j][i - 1]) // move up
				i -= 1;
			else { // new word
				if (output != "")
					output = vec1[j] + " " + output;
				else
					output = vec1[j];
				i -= 1;
				j -= 1;
			}
		}
		cout << output << '\n';
	}
	return 0;
}
