// Only need to care about checking incoming ")" and "]"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int t = 0;
	cin >> t;
	cin.ignore();
	string s;
	//stack<char> stk;
	while (t--) {
		getline(cin, s);
		if (!s.length())
			cout << "Yes\n";
		else {
			stack<char> stk;
			for (char c : s) {
				/*if ((c == ')' || c == ']') && stk.empty()) {
					cout << "No\n";
					break;
				}
				else {
					if ((c == '(' || c == '[')) {
						stk.push(c);
					}
					else if (c == ')' && stk.top() == '(') {
						stk.pop();
					}
					else if (c == ']' && stk.top() == '[') {
						stk.pop();
					}
					else {
						//cout << "No\n";
						break;
					}
				}*/
				if ((c == ')' || c == ']') && stk.empty()) {
					//cout << "No\n";
					stk.push(c);
					break;
				}
				if ((c == '(' || c == '[')) {
					stk.push(c);
				}
				else if (c == ')' && stk.top() == '(') {
					stk.pop();
				}
				else if (c == ']' && stk.top() == '[') {
					stk.pop();
				}
				else {
					//cout << "No\n";
					break;
				}
			}
		if (stk.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
		}

	}
	return 0;
}
