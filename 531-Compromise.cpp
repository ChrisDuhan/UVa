#include <iostream>
#include <string>
#include <vector>

typedef vector<string> vs;
typedef vector<vector<int>> vvi;

using namespace std;

int main() {
	string s;
	vs vec1;
	vs vec2;
	while (cin >> s && s != "#") {
		vec1.push_back(s);
	}
	while (cin >> s && s != "#") {
		vec2.push_back(s);
	}
	vvi M(vec1.size() + 1, vs(vec2.size() + 1));

	return 0;
}
