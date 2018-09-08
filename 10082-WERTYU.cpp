//////////////////////////////////////////////////////////////////////
//
// Chris Duhan: WERTYU: 10082: chriscodes
//
// Data structure required : STL string
//
// Tricks of the trade: Initializing the char array with the values
//                      coresponding to the encoded charactors
//                      provides rapid lookup.
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

int main() {
	char table[128] = {
		'q','q','q','q','q','q','q','q','q','q','q','q',
		'q','q','q','q','q','q','q','q','q','q','q','q',
		'q','q','q','q','q','q','q','q','q','q','q','q',
		'q','q','q',';','q','q','q','q','M','0',',','.',
		'9','`','1','2','3','4','5','6','7','8','q','L',
		'q','-','q','q','q','q','V','X','S','W','D','F',
		'G','U','H','J','K','N','B','I','O','q','E','A',
		'R','Y','C','Q','Z','T','q','P',']','[','q','q',
		'q','q','q','q','q','q','q','q','q','q','q','q',
		'q','q','q','q','q','q','q','q','q','q','q','q',
		'q','q','q','q','q','q','q','q'
	}; // q will be a placeholder
	string s;
	while (getline(cin, s)) {
		for (char c : s) {
			if (c != 32)
				cout << table[int(c)];
			else
				cout << char(32);
		}
		cout << endl;
	}
	return 0;
}
