#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

void check(vector<string> &world, int r, int c, char chr) {
	if (world[r][c] != chr)
		return;

	world[r][c] = '#';
	check(world, r - 1, c, chr);
	check(world, r + 1, c, chr);
	check(world, r, c - 1, chr);
	check(world, r, c + 1, chr);
}

bool pairSort(pair<int, char> &a, pair<int, char> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; ++i) {
		int h, w;
		cin >> h >> w;
		vector<string> world(h + 2);
		string border = "#";
		for (int j = 0; j < w + 1; ++j) {
			border += "#";
		}
		world[0] = world[h + 1] = border;
		for (int j = 1; j < h + 1; ++j) {
			cin >> world[j];
			world[j] = "#" + world[j] + "#";
		}
		/*for (int j = 0; j < world.size(); ++j) {
		cout << world[j] << "\n";
		}*/
		cout << "World #" << i + 1 << "\n";
		vector<pair<int, char>> lang(26);
		for (int j = 0; j < 26; ++j) {
			lang[j].first = 0;
			lang[j].second = j + 97;
		}
		for (int r = 1; r < h + 1; ++r) {
			for (int c = 1; c < w + 1; ++c) {
				char chr = world[r][c];
				if (chr != '#') {
					check(world, r, c, chr);
					lang[chr - 97].first += 1;
				}
			}
		}
		sort(lang.begin(), lang.end(), pairSort);
		int t = 0;
		while (t<26 && lang[t].first != 0) {
			cout << lang[t].second << ": " << lang[t].first << "\n";
			++t;
		}
	}

	return 0;
}
