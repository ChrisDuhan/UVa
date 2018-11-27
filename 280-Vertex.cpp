#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, tc;
	cin >> n;
	while (n != 0) {
		vector<vector<int>> g(n + 1, vector<int>());
		int vertex, edge;
		cin >> vertex;
		while (vertex != 0) {
			cin >> edge;
			while (edge != 0) {
				g[vertex].push_back(edge);
				cin >> edge;
			}
			cin >> vertex;
		}

		/*
    // for visualization
    for (int i = 1; i < g.size(); ++i) {
			for (int j = 0; j < g[i].size(); ++j) {
				cout << g[i][j] << " ";
			}
			cout << "\n";
		}*/

		cin >> tc;
		for (int i = 0; i < tc; ++i) {
    // BFS
			int current;
			cin >> current;
			vector<int> color(g.size(), 0);
			queue<int> q;
			q.push(current);
			int node;
			while (!q.empty()) {
				node = q.front();
				q.pop();
				for (auto child : g[node]) {
					if (color[child] == 0) {
						color[child] = 1;
						q.push(child);
					}
				}
			}
			int c = 0;
			for (int j = 1; j < color.size(); ++j) {
				if (color[j] == 0) {
					++c;
				}
			}
			cout << c;
			for (int j = 1; j < color.size(); ++j) {
				if (color[j] == 0) {
					cout << " " << j;
				}
			}
			cout << "\n";
		}
		cin >> n;
	}
	return 0;
}
