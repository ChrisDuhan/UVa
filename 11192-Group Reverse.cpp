//////////////////////////////////////////////////////////////////////
//
// Chris Duhan: Group Reverse: 11192: chriscodes
//
// Data structure required : STL string
//
// Tricks of the trade: Use the reverse function with some clever 
//						indexing.
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <algorithm> // reverse()

using namespace std;

int main() {
	int c = 0, group = 0, sos = 0; // sos = start of set
	string s;
	cin >> c;
	while (c != 0) {
		cin >> s;
		group = s.length() / c;
		for (int i = 1; i <= c; i++) {
			sos = group * i;
			reverse(s.begin()+(sos-group), s.begin()+(sos));
		}
		cout << s << endl;
		cin >> c;
	}
	return 0;
}
