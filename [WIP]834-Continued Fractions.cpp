#include <iostream>

using namespace std;

int main() {
	int num, den;
	while (cin >> num >> den) {
		cout << '[';
		div_t divresult;
		divresult = div(num, den);
		cout << divresult.quot << ';';
		while (divresult.rem != 1) {
			num = den;
			den = divresult.rem;
			divresult = div(num, den);
			cout << divresult.quot << ',';
		}
		cout << den << "]\n";

	}
	return 0;
}
