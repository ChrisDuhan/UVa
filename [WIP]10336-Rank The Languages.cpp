#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

void check(vector<string> &world, int r, int c) {
	if (world[r - 1][c] == world[r][c]) {
		check(world, r - 1, c);
	}
	if (world[r + 1][c] == world[r][c]) {
		check(world, r + 1, c);
	}
	if (world[r][c - 1] == world[r][c]) {
		check(world, r, c - 1);
	}
	if (world[r][c + 1] == world[r][c]) {
		check(world, r, c + 1);
	}
	world[r][c] = '#';
}

bool pairSort(const pair<int, char> &a, const pair<int, char> &b) {
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
		vector<int> lang(26, 0);
		for (int r = 1; r < h; ++r) {
			for (int c = 1; c < w; ++c) {
				if (world[r][c] != '#') {
					lang[world[r][c] - 97] += 1;
					check(world, r, c);
				}
			}
		}
		vector<pair<int, char>> ordered;
		for (int j = 0; j < 26; ++j) {
			if (lang[j] != 0) {
				ordered.push_back(make_pair(lang[j], (char)j + 97));
			}
		}
		sort(ordered.begin(), ordered.end(), pairSort);
		for (auto t : ordered) {
			cout << t.second << ": " << t.first << "\n";
		}
	}

	return 0;
}
