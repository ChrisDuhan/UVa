#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int t = 0, num = 0;
	cin >> t;
	while (t) {
		cin >> num;
		while (num) {
			vector<int> vect(t);
			vect[0] = num;
			for (int i = 1; i < t; ++i) {
				cin >> vect[i];
			}
			stack<int> stk;
			int i = 0, j = 1;
			// stack stuff
			while (true) {
				if (!stk.empty() && stk.top() == vect[i]) {
					stk.pop();
					++i;
					continue;
				}
				if (j > t)
					break;
				stk.push(j);
				++j;
			}
			if (stk.empty())
				cout << "Yes\n";
			else
				cout << "No\n";
			cin >> num;
		}
		cout << "\n";
		cin >> t;
	}
	return 0;
}

/*Dosnt work
1 4 2 3
2 4 1 3
3 1 2 4
3 1 4 2
3 4 1 2
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2

works
1 2 4 3
1 3 2 4
1 3 4 2
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 3 1
3 2 1 4
3 2 4 1
3 4 2 1
*/
