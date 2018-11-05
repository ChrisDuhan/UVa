#include <iostream>
#include <iomanip>
//#include <cmath>

using namespace std;

const double aArea = 0.31514674362772031;
const double bArea = 0.51129916633435203;
const double cArea = 0.17355409003792766;

int main() {
	double x, area;
	while (cin >> x) {
		area = x * x;
		cout << fixed << setprecision(3) << area * aArea << " " << area * bArea << " " << area * cArea << "\n";
	}
	return 0;
}

//const double PI = acos(-1);
//
//int main() {
//	// x = square side
//	// area = basic area
//	// a = sliver area
//	// b = triangular area
//	// c = inner square area
//	// leg3 = third leg of a triangle with a point in the squares corner
//	// tArea = area of the above triangle
//	// sArea = circular segment area
//	// sliver = area of the thin portion of the arc
//	// wArea = area of the odd triangular shape
//	double x, area, a, b, c, leg3, tArea, sArea, sliver, wArea;
//	while (cin >> x) {
//		area = x * x;
//		leg3 = sqrt((x*x) + (x*x) - (2 * x*x*cos(30.0*PI/180)));
//		tArea = (x*x*sin(30.0*PI/180)) / 2;
//		sArea = (30.0 / 360.0)*PI*(x*x);
//		sliver = sArea - tArea;
//		a = leg3 * leg3 + 4 * sliver;
//		wArea = (leg3*leg3*sin(60.0*PI / 180)) / 2;
//		b = 4*(wArea + sliver);
//		c = area - a - b;
//
//		cout << fixed << setprecision(3) << a << " " << b << " " << c << "\n";
//	}
//	return 0;
//}
