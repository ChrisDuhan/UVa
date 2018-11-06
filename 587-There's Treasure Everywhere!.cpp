#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
const double diagDist = sqrt(2.0) / 2;
const pair<double, double> origin(0.0, 0.0);

int main() {
	map<string, pair<double, double>> compass;
	int distance, ct = 1;
	string line, direction = "";

	// Init values of the cardinal directions
	compass["N"] = make_pair(0, 1);
	compass["S"] = make_pair(0, -1);
	compass["E"] = make_pair(1, 0);
	compass["W"] = make_pair(-1, 0);
	compass["NW"] = make_pair(-diagDist, diagDist);
	compass["NE"] = make_pair(diagDist, diagDist);
	compass["SW"] = make_pair(-diagDist, -diagDist);
	compass["SE"] = make_pair(diagDist, -diagDist);

	cout << fixed << setprecision(3);
	getline(cin, line);
	
	while (line != "END") {
		pair<double, double> myLocation = origin;
		line = line.erase(line.size() - 1);
		replace(line.begin(), line.end(), ',', ' ');
		istringstream ss(line);
		while (ss >> distance >> direction) {
			myLocation.first = myLocation.first + distance * compass[direction].first;
			myLocation.second = myLocation.second + distance * compass[direction].second;
		}

		double simpleDistance = sqrt((myLocation.first*myLocation.first) + (myLocation.second*myLocation.second));

		cout << "Map #" << ct << "\nThe treasure is located at (" << myLocation.first << "," << myLocation.second 
			<< ").\nThe distance to the treasure is " << simpleDistance << ".\n\n";

		++ct;
		getline(cin, line);
	}
	return 0;
}
