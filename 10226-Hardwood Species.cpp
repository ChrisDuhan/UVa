#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
	int t;
	
	string tree;
	cin >> t;
	cin.ignore().ignore();
	while (t--) {
		float ct = 0;
		map<string, int> trees;
		getline(cin, tree);
		while (tree != "") {
			trees[tree]++;
			ct++;
			getline(cin, tree);
		}
		cout << fixed << setprecision(4);
		for (auto iter = trees.begin(); iter != trees.end(); iter++) {
			cout << iter->first << " " << iter->second / ct * 100.0 << "\n";
		}
		
		if (t) cout << "\n";
	}
	return 0;
}
