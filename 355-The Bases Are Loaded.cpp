#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
int convertCharToNum(char c) {
	if (c >= '0' && c <= '9')
		return (int)c - 48;
	else
		return (int)c - 55; // A - 10
}

char convertNumToChar(int i) {
	if (i >= 0 && i <= 9)
		return (char)i + 48;
	else
		return (char)i + 55; // A - 10
}

// Convert number of a given base to a decimal
long long convertToDecimal(int base, string s) {
	int con;
	long long num = 0; // may be too big
	for (int i = 0; i < s.length(); ++i) {
		con = convertCharToNum(s[i]);
		if (con >= base)
			return -1; // Not a number of given base
		num = num * base + con; // Modified Horner method
	}
	return num;
}

// Convert decimal to a number in given base
string decimalToNewBase(int base, long long decNum) {
	string res = "";
	if (!decNum) // int used as a bool, sue me
		return "0";
	while (decNum > 0) { // Wish there was a fater way to do this
		res += convertNumToChar(decNum % base);
		decNum /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	int startBase, newBase;
	string num, newNum;
	long long decNum;
	// Using long long because the input number may be up to ten charactors,
	// ten 'f's is 1,099,511,627,775 - significantly larger than INT_MAX

	while (cin >> startBase >> newBase >> num) {
		decNum = convertToDecimal(startBase, num);
		if (decNum == -1)
			cout << num << " is an illegal base " << startBase << " number\n";
		else {
			newNum = decimalToNewBase(newBase, decNum);
			cout << num << " base " << startBase << " = " << newNum << " base " << newBase << "\n";
		}
	}
	return 0;
}
