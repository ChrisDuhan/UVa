#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void dijkstraRelax(int s, vi &dist, vector<vii> &graph) {
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue; // skip the rest
		for (int i = 0; i < (int)graph[u].size(); ++i) {
			ii v = graph[u][i];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int n, m, S, T;
		cin >> n >> m >> S >> T;
		vector<vii> graph(n, vii());
		int s1, s2, c; // server1, server2, cable length
		for (int j = 0; j < m; ++j) {
			cin >> s1 >> s2 >> c;
			graph[s1].push_back(ii(s2, c));
			graph[s2].push_back(ii(s1, c));
		}
		vi dist(n, 1000000); // beyond the value that should be contained
		dist[S] = 0;
		dijkstraRelax(S, dist, graph);
		cout << "Case #" << i + 1 << ": ";
		if (dist[T] != 1000000)
			cout << dist[T] << "\n";
		else
			cout << "unreachable\n";
	}
	return 0;
}
